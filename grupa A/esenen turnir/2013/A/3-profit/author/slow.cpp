#include <stdio.h>
#include <utility>
#include <vector>
#include <set>

// #define LOG(...) fprintf(stderr, __VA_ARGS__)
#define LOG(...)

using std::vector;
using std::pair;
using std::make_pair;
using std::set;

vector<vector<int> > graph;
vector<pair<pair<int, int>, int> > bonuses;

vector<int> leaves;

void log_vi(const char *msg, vector<int> &v) {
  LOG("%s:", msg);
  for (size_t i = 0; i < v.size(); ++i) {
    LOG(" %d", v[i]);
  }
  LOG("\n");
}

void fill_leaves(int node, int parent) {
  int kids = 0;
  for (size_t i = 0; i < graph[node].size(); ++i) {
    int kid = graph[node][i];
    if (kid == parent) continue;
    ++ kids;

    fill_leaves(kid, node);
  }

  if (kids == 0) {
    leaves.push_back(node);
  }
}

int _begin, _end;
set<int> *_path;
bool detect_path(int node, int parent) {
  if (node == _end) {
    _path->insert(node);
    return true;
  }

  for (size_t i = 0; i < graph[node].size(); ++i) {
    int kid = graph[node][i];

    if (kid == parent) continue;

    if (detect_path(kid, node)) {
      _path->insert(node);
      return true;
    }
  }
  return false;
}

int calc_bonus(set<int> &nodes) {
  int res = 0;
  for (size_t i = 0; i < bonuses.size(); ++i) {
    pair<pair<int, int>, int> bonus = bonuses[i];
    if (nodes.find(bonus.first.first) != nodes.end() &&
        nodes.find(bonus.first.second) != nodes.end()) {
      res += bonus.second;
    }
  }
  return res;
}

int main() {
  int N, M;
  scanf("%d", &N);

  graph.resize(N);
  for (int i = 1; i < N; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a; --b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  scanf("%d", &M);
  bonuses.resize(M);
  for (int i = 0; i < M; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    --a; --b;
    bonuses.push_back(make_pair(make_pair(a, b), c));
  }

  fill_leaves(0, -1);
  if (graph[0].size() == 1) {
    leaves.push_back(0);
  }

  log_vi("leaves", leaves);

  int max_bonus = -1, best_a_leaf = -2, best_b_leaf = -2;
  for (size_t i = 0; i < leaves.size(); ++i) {
    for (size_t j = i+1; j < leaves.size(); ++j) {
      set<int> path;
      _begin = leaves[i], _end = leaves[j], _path = &path;
      detect_path(_begin, -1);
      int bonus = calc_bonus(path);
      if (max_bonus < bonus) {
        max_bonus = bonus;
        best_a_leaf = _begin;
        best_b_leaf = _end;
      }
    }
  }

  printf("%d %d %d\n", best_a_leaf + 1, best_b_leaf + 1, max_bonus);
}
