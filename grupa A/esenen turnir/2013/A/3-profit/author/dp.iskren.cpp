#include <stdio.h>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using std::vector;
using std::set;
using std::pair;
using std::make_pair;

void print_si(const char *msg, set<int> s) {
  printf("%s:", msg);
  for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
    printf(" %d", *it);
  }
  printf("\n");
}

struct bonus {
  int to, cost;
  bonus() : to(-1), cost(-1) {}
  bonus(int to, int cost) : to(to), cost(cost) {}
};

typedef vector<vector<int> > graph_t;
typedef vector<vector<bonus> > bonuses_t;

graph_t graph;
bonuses_t bonuses;
pair<int, int> p;

void input() {
  int N;
  scanf("%d", &N);

  graph.resize(N);
  for (int i = 1; i < N; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a; --b;

    if (i == 1) {
      p.first = a;
      p.second = b;
    }

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  int M;
  scanf("%d", &M);
  bonuses.resize(N);
  for (int i = 0; i < M; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    --a; --b;

    bonuses[a].push_back(bonus(b, c));
    bonuses[b].push_back(bonus(a, c));
  }
}

vector<vector<int> > dp;
vector<int> parent;
set<int> path[2];

int collect_bonuses(int a, int b, int c) {
  int bonus = 0;
  //print_si("p0", path[0]);
  //print_si("p1", path[1]);
  for (size_t i = 0; i < bonuses[c].size(); ++i) {
    //printf("checking bonus %d %d %d", c, bonuses[c][i].to, bonuses[c][i].cost);
    if (path[0].find(bonuses[c][i].to) != path[0].end() ||
        path[1].find(bonuses[c][i].to) != path[1].end()) {
      bonus += bonuses[c][i].cost;
      //printf(" yes\n");
    } else {
      //printf(" no\n");
    }
  }
  return bonus;
}

void solve(int a, int b) {
  int try1 = dp[a][parent[b]] + collect_bonuses(a, parent[b], b);
  int try2 = dp[parent[a]][b] + collect_bonuses(parent[a], b, a);

  dp[a][b] = std::max(try1, try2);
}

int nodes[2];
vector<int> leaves[2];
void dfs(int node, int parent, int id) {
  //printf("%d %d %d\n", node, parent, id);
  nodes[id] = node;
  //printf("%d %d\n", (int) ::parent.size(), node);
  ::parent[node] = parent;
  path[id].insert(node);

  if (id == 0) {
    dfs(p.second, p.first, 1);
  } else {
    solve(nodes[0], nodes[1]);
  }

  int kids = 0;
  for (size_t i = 0; i < graph[node].size(); ++i) {
    int kid = graph[node][i];
    if (kid == parent) continue;
    ++ kids;
    dfs(kid, node, id);
  }

  if (kids == 0) {
    leaves[id].push_back(node);
  }
  path[id].erase(node);
}

int main() {
  input();
  dp.resize(graph.size(), vector<int>(graph.size()));
  parent.resize(graph.size());

  dfs(p.first, p.second, 0);

  int best = -1, best_a = -1, best_b = -1;
  //printf("%zu %zu\n", leaves[0].size(), leaves[1].size());
  for (size_t i = 0; i < leaves[0].size(); ++i) {
    for (size_t j = 0; j < leaves[1].size(); ++j) {
      if (best < dp[leaves[0][i]][leaves[1][j]]) {
        best = dp[leaves[0][i]][leaves[1][j]];
        best_a = leaves[0][i];
        best_b = leaves[1][j];
      }
    }
  }

  printf("%d %d %d\n", best_a + 1, best_b + 1, best);

  return 0;
}
