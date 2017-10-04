#include<cstdio>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
#include<queue>
#include<assert.h>

using namespace std;

const int MAX_N     = 3000+1;
const int MAX_E     = 2*MAX_N;

#define MAX_LABEL   10
#define str(x)      # x
#define xstr(x)     str(x)

struct Edge {
  int from;   // number of the vertex on the other end
  int to;     // number of the vertex on the other end
  int num;    // edge number in [0, 2*(E=N-1)] because of the orientation

  Edge() {}
  Edge(int _from, int _to, int _num)
    : from(_from), to(_to), num(_num) {}

  bool operator==(Edge e) { return from==e.from && to==e.to && num==e.num; }

  // reverse edges are indexed sequentially: even num edge <-> odd num edge
  Edge rev() { return Edge(to, from, num^1); }
};

struct Tree {
  int N, E;                   // number of vertices, number of edges 
  vector<Edge> neigh[MAX_N];  // list of neighbours
  string label[MAX_N];        // names of the leaves (empty string if not a leaf)
  Edge edge[MAX_E];           // beginning vertex of the edge

  void add_edge(int from, int to) {
    edge[E] = Edge(from, to, E);
    assert( find(edge, edge+E, edge[E]) == edge+E );

    neigh[from].push_back( edge[E] );
    E++;
  }
};

// both trees not to be changed through the algorithm
Tree P, Q;

Tree read_tree(FILE *fin)
{
  Tree T;
  int a, b;

  // edges
  T.E = 0; // important to start from an even number because of the num^1 hack
  assert(fscanf(fin, "%d", &T.N) == 1);
  assert(T.N >= 1 && T.N <= MAX_N-1);

  for (int i=0; i<T.N-1; i++) {
    assert(fscanf(fin, "%d %d", &a, &b) == 2);
    assert(a != b);
    assert(a >= 1 && a <= T.N);
    assert(b >= 1 && b <= T.N);

    T.add_edge(a, b);
    T.add_edge(b, a);
  }

  // leaves
  int L;
  set<string> labels;

  assert(fscanf(fin, "%d", &L) == 1);
  assert(L >= 1 && L <= T.N);

  for (int i=0; i<L; i++) {
    char label[MAX_LABEL+1];
    assert(fscanf(fin, "%d %"xstr(MAX_LABEL)"s", &a, label) == 2);
    assert(a >= 1 && a <= T.N);

    assert( label[0] != '\0' );
    for (char *c=label; *c!='\0'; c++)
      assert( (*c >= 'A' && *c <= 'Z') || (*c >= '0' && *c <= '9') );

    assert( labels.find(label) == labels.end() );
    labels.insert(label);

    assert(T.label[a] == "");
    T.label[a] = label;
  }

  return T;
}

void check_binary_structure(Tree &T)
{
  vector<bool> V(MAX_N, 0);
  int vertices=0;

  queue<int> Q;
  Q.push(1);

  while (!Q.empty()) {
    int curr = Q.front();
    Q.pop();

    V[curr] = true;

    int size(T.neigh[curr].size()), visited_neigh(0);
    assert (size == 3 || size == 1);

    vertices++;

    for (int i=0; i<size; i++) {
      int next = T.neigh[curr][i].to;
      if (V[next])
        visited_neigh++;
      else
        Q.push(next);
    }

    assert(visited_neigh <= 1); // number of visited neighbours > 1 <=> a cycle exists
  }

  assert(vertices == T.N);
}

void visualize(Tree T, string fn)
{
  FILE *fdot = fopen(fn.c_str(), "w");

  fprintf(fdot, "Graph G {\n");
  fprintf(fdot, "  ordering=out\n");
  fprintf(fdot, "  \n");
  fprintf(fdot, "  node [chape=box]\n");
  
  for (int i=1; i<=T.N; i++)
    if (T.label[i] != "")
      fprintf(fdot, "  %d [label=\"%d: %s\"];\n", i, i, T.label[i].c_str());
  
  fprintf(fdot, "  \n");
  fprintf(fdot, "  node [chape=ellipse]\n");
  
  for (int i=0; i<T.E; i+=2)
    fprintf(fdot, "  %d -- %d\n", T.edge[i].from, T.edge[i].to);

  fprintf(fdot, "}\n");
  fprintf(fdot, "\n");

  fclose(fdot);
  
  printf("Visualize file %s created.\n", fn.c_str());
}

int main(int argn, char* args[])
{
  if (argn != 2) {
    printf("args: <inputfile>\n");
    return 1;
  }

  printf("Checking input data...");
  
  FILE *fin = fopen(args[1], "r");
  
  P = read_tree(fin);
  Q = read_tree(fin);

  check_binary_structure(P);
  check_binary_structure(Q);

  printf("Correct.\n");

  visualize(P, string(args[1]) + ".P.dot");
  visualize(Q, string(args[1]) + ".Q.dot");
  
  return 0;
}
