#include<iostream>
#include<queue>
using namespace std;

typedef long long flow_t;

const int     MAX_N = 5009;
const int     MAX_M = 2 * 30009;  // 2x for the reversed edges
const flow_t  MAX   = 1e9 + 5;  // max total flow value

struct Edge {
  int to;     // ending vertex of an oriented edge
  flow_t rd;  // residual capacity -- updated after finding an augmenting path
  int next;   // the index of the next Edge in E

  Edge() {}
  Edge(int _to, flow_t _rd, int _next)
    : to (_to), rd (_rd), next (_next) {}
};

int N, M;
int source, target;  // all vertex numbers should be zero-based

int head[MAX_N];  // head[v] points to the first edge of a linked list of the edges starting at v; the value -1 indicates the end of the list
Edge E[MAX_M];    // every edge (starting from E[0]) is followed by its reverse edge with odd index

int lvl[MAX_N];  // lvl[v] -- # of edges from v to target, or -1 if no path exists
int ptr[MAX_N];  // like head[] but skips edges which didn't lead to target
int path[MAX_N], path_len;  // list of edges of the current augmenting path

// added a new edge from a to b with residual flow c
void add_edge(int from, int to, flow_t cap) {
  static int E_len = 0;
  E[E_len] = Edge(to, cap, head[from]);
  head[from] = E_len++;
}

void input() {
  int from, to;
  flow_t rd;

  cin >> N >> M;
  source = 0;
  target = N-1;

  fill(head, head+N, -1);
  for (int i = 0; i < M; ++i) {
    cin >> from >> to >> rd;
    --from; --to;  // to zero-based vertex numbers

    add_edge(from, to, rd);  // direct edge with c initial residual flow
    add_edge(to, from, 0);   // reverse edge with no initial residual flow
    add_edge(to,from,rd);
    add_edge(from,to,0);

  }
}

// compute lvl[v] spreading from target going through the reversed edges
// so lvl[v] is the shortest edge-distance from v to target
// returns whether there is a path from source to target
bool bfs() {
  queue<int> Q;
  fill(lvl, lvl+N, -1);

  Q.push(target);
  lvl[target] = 0;
  while(!Q.empty()) {
    int v = Q.front();
    Q.pop();
    for (int e = head[v]; e != -1; e = E[e].next)
      if (lvl[E[e].to] == -1 && E[e ^ 1].rd > 0) {
        lvl[E[e].to] = lvl[v] + 1;
        Q.push(E[e].to);
      }
  }

  return lvl[source] != -1;
}

// finds one augmenting path from source to target
// returns the maximum flow throung the path <=> min edge
flow_t dfs(int v) {
  if (v == target)
    return MAX;

  for (int e = ptr[v]; e != -1; e = ptr[v] = E[e].next)
    // move only to a closer vertex to target so that a shortest path is found
    if (lvl[E[e].to] == lvl[v] - 1 && E[e].rd > 0) {
      path[path_len++] = e;
      if (flow_t tmp = dfs(E[e].to))
        return min(tmp, E[e].rd);
      --path_len;
    }

  return 0;
}

// propagate the max possible flow through the current augmenting path
void update_graph(flow_t cflow) {
  for (int i = 0; i < path_len; ++i) {
    E[path[i]].rd -= cflow;
    E[path[i] ^ 1].rd += cflow;
  }
}

flow_t dinitz() {
  flow_t maxflow = 0, cflow;

  // every consequitive BFS finds strictly longer shortest paths
  // so there are no more than N phases of BFS
  while (bfs()) {
    copy(head, head+N, ptr);

    // cflow > 0 <=> augmenting path is found
    while (path_len = 0, cflow = dfs(source)) {
      maxflow += cflow;
      update_graph(cflow);
    }
  }

  return maxflow;
}

int main () {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
  input();
  cout << dinitz() << endl;

  return 0;
}
