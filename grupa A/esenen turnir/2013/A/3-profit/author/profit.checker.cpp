#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vector>
#include <utility>
#include <set>
#include <algorithm>

using std::vector;
using std::set;
using std::pair;
using std::make_pair;
using std::find;

void verdict(int points, const char *msg) {
  printf("%d\n%s\n", points, msg);
  exit(0);
}

bool careful_read(FILE *f, int *q1, int *q2, int *bonus) {
  static char line[128];
  fgets(line, 128, f);
  if (fgetc(f) != EOF) { return false; }

  if (sscanf(line, "%d %d %d", q1, q2, bonus) != 3) {
    return false;
  }

  static char expected_line[128];
  sprintf(expected_line, "%d %d %d\n", *q1, *q2, *bonus);

  return strcmp(line, expected_line) == 0;
}

void input(FILE *f, vector<vector<int> > &graph,
    vector<pair<pair<int, int>, int > > &bonuses) {
  int N, M;
  fscanf(f, "%d", &N);

  graph.resize(N);
  for (int i = 1; i < N; ++i) {
    int a, b;
    fscanf(f, "%d %d", &a, &b);
    --a; --b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  fscanf(f, "%d", &M);
  bonuses.resize(M);
  for (int i = 0; i < M; ++i) {
    int a, b, c;
    fscanf(f, "%d %d %d", &a, &b, &c);
    --a; --b;
    bonuses.push_back(make_pair(make_pair(a, b), c));
  }
}

int _end;
vector<vector<int> > *_graph;
set<int> *_nodes;
bool dfs(int node, int parent) {
  if (node == _end) {
    _nodes->insert(node);
    return true;
  }
  for (size_t i = 0; i < (*_graph)[node].size(); ++i) {
    int kid = (*_graph)[node][i];

    if (kid == parent) { continue; }

    if (dfs(kid, node)) {
      _nodes->insert(node);
      return true;
    }
  }
  return false;
}

int main(int argc, char *argv[]) {
  //assert(argc == 4);
  FILE *in = fopen(argv[1], "r");
  FILE *out = fopen(argv[2], "r");
  FILE *sol = fopen(argv[3], "r");

  int out_q1, out_q2, out_bonus;
  if (!careful_read(out, &out_q1, &out_q2, &out_bonus)) {
    verdict(0, "Output syntax error");
  }
  fclose(out);

  int sol_q1, sol_q2, sol_bonus;
  fscanf(sol, "%d %d %d", &sol_q1, &sol_q2, &sol_bonus);
  fclose(sol);

  // Oh, well -- we have to make a full blown check.
  vector<vector<int> > graph;
  vector<pair<pair<int, int>, int> > bonuses;
  input(in, graph, bonuses);
  fclose(in);

  if (!(1 <= out_q1 && out_q1 <= (int) graph.size() &&
        1 <= out_q2 && out_q2 <= (int) graph.size())) {
    verdict(0, "Node indexes out of range");
  }

  -- out_q1, -- out_q2;
  set<int> nodes;
  _end = out_q2, _nodes = &nodes, _graph = &graph;
  dfs(out_q1, -1);

  int bonus = 0;
  for (size_t i = 0; i < bonuses.size(); ++i) {
    if (nodes.find(bonuses[i].first.first) != nodes.end() &&
        nodes.find(bonuses[i].first.second) != nodes.end()) {
      fprintf(stderr, "%d %d %d\n", bonuses[i].first.first,
          bonuses[i].first.second, bonuses[i].second);
      bonus += bonuses[i].second;
    }
  }

  set<int>::iterator it = nodes.begin();
  int v1 = *it, v2 = -1;
  for (it++; it!=nodes.end(); it++)
    if (find(graph[v1].begin(), graph[v1].end(), *it) != graph[v1].end())
      v2 = *it;

  //assert(v2 != -1);
  //printf("Random edge from the optimal path: %d %d\n", v1+1, v2+1);

  if (bonus == out_bonus) {
    if (out_bonus < sol_bonus) {
      verdict(0, "Wrong bonus");
    }

    assert(out_bonus == sol_bonus);
    verdict(5, "OK");
  } else {
    verdict(0, "Wrong bonus WTF");
  }

  return 0;
}
