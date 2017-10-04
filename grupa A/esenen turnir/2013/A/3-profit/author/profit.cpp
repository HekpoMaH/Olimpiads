#include <assert.h>
#include <stddef.h>
#include <stdio.h>

#include <queue>
#include <set>
#include <utility>
#include <algorithm>
#include <vector>

using std::make_pair;
using std::pair;
using std::vector;

typedef vector<vector<int> > graph_t;
typedef vector<pair<pair<int, int>, int> > bonus_t;
typedef vector<vector<pair<int, int> > > range_bonus_t;
typedef vector<vector<pair<int, int> > > maybe_bonus_t;
enum type_t { TYPE_NONE = 0, TYPE_A = 1, TYPE_B = 2, TYPE_P = 3 };

struct ans_t {
  int a, b, c;
  ans_t() : a(-1), b(-1), c(-1) {}
  ans_t(int a, int b, int c)
    : a(a), b(b), c(c) {}
};

void print_vi(const char *msg, const vector<int> &arr) {
  fprintf(stderr, "%s:", msg);
  for (size_t i = 0; i < arr.size(); ++i) {
    fprintf(stderr, " %d", arr[i]);
  }
  fprintf(stderr, "\n");
}

void print_rb(const char *msg, const range_bonus_t &arr) {
  fprintf(stderr, "%s:", msg);
  for (size_t i = 0; i < arr.size(); ++i) {
    fprintf(stderr, " (");
    for (size_t j = 0; j < arr[i].size(); ++j) {
      fprintf(stderr, " (%d %d)", arr[i][j].first, arr[i][j].second);
    }
    fprintf(stderr, " )");
  }
  fprintf(stderr, "\n");
}

void print_types(const char *msg, vector<type_t> &types) {
  fprintf(stderr, msg);
  for (size_t i = 0; i < types.size(); ++i) {
    fprintf(stderr, " %d", (int) types[i]);
  }
  fprintf(stderr, "\n");
}

void print_graph(const char *msg, graph_t &graph) {
  fprintf(stderr, "---- %s ----\n", msg);
  for (size_t i = 0; i < graph.size(); ++i) {
    fprintf(stderr, "%zu ->", i);
    for (size_t j = 0; j < graph[i].size(); ++j) {
      fprintf(stderr, " %d", graph[i][j]);
    }
    fprintf(stderr, "\n");
  }
}

struct it_node {
  int full;
  int child_max;
  it_node() : full(0), child_max(0) {}
  int total() { return child_max + full; }
};

class interval_tree {
 public:
  interval_tree(int size) {
    //fprintf(stderr, "interval_tree(%d ->", size);
    if ((size & (size - 1)) != 0) {
      while ((size & (size - 1)) != 0) {
        size &= size - 1;
      }
      size <<= 1;
    }
    //fprintf(stderr, " %d)\n", size);

    _size = size;
    _d.resize(size * 2 - 1, it_node());
  }

  /**
   * Add `value` to all leaves in [range.first, range.last]
   */
  void add(pair<int, int> range, int value) {
    _rlb = range.first;
    _rub = range.second + 1;
    _v = value;
    _add(0, _size, 0);
  }

  /**
   * Return the value of the max leaf
   */
  int global_max() {
    return _d[0].total();
  }

  /**
   * Return the index of the max leaf
   */
  int max_leaf() {
    int stop_cond = _size;
    int p = 0;
    // fprintf(stderr, "stop_cond: %d\n", stop_cond);
    while (stop_cond > 1) {
      if (_d[p].child_max == _d[p*2+1].total()) {
        p = p*2 + 1;
      } else {
        p = p*2 + 2;
      }
      stop_cond >>= 1;
    }
    // fprintf(stderr, "max_leaf: %d\n", p - _size + 1);
    return p - _size + 1;
  }

  /**
   * For debugging
   */
  void print() {
    for (size_t i = 0, b = 1; i < _d.size(); ++i) {
      if (i == b - 1) {
        b *= 2;
        fprintf(stderr, "\n");
      }
      fprintf(stderr, " (%d %d)", _d[i].full, _d[i].child_max);
    }
    fprintf(stderr, "\n\n");
  }
 private:
  // global _add variables
  int _rlb, _rub, _v;
  void _add(int lb, int ub, int p) {
    // fprintf(stderr, "  _add %d %d %d\n", lb, ub, p);
    if (_rlb <= lb && ub <= _rub) {
      // fprintf(stderr, "    full cover\n");
      // full cover
      _d[p].full += _v;
      return;
    }
    if (ub <= _rlb || _rub <= lb) {
      // fprintf(stderr, "    no cover\n");
      // no cover
      return;
    }
    // fprintf(stderr, "    touching %d %d (size %zu)\n", p*2 + 1, p*2 + 2, _d.size());
    int mid = (lb + ub) / 2;
    _add(lb, mid, p * 2 + 1);
    _add(mid, ub, p * 2 + 2);
    _d[p].child_max = std::max(_d[p*2+1].total(), _d[p*2+2].total());
  }
 private:
  // storage
  int _size;
  vector<it_node> _d;
};

class dfs_a {
 public:
  dfs_a(graph_t &graph, maybe_bonus_t &maybe_a_bonus,
      interval_tree &leaf_bonuses, vector<pair<int, int> > &ranges)
    : graph(graph), maybe_a_bonus(maybe_a_bonus),
      leaf_bonuses(leaf_bonuses), ranges(ranges) {
  }

  void xvisit(int root, vector<int> &children) {
    enter(root, -1);
    for (size_t i = 0; i < children.size(); ++i) {
      int child = children[i];
      visit(child, root);
    }
    exit(root, -1);
  }

 protected:
  void visit(int node, int parent) {
    enter(node, parent);
    for (size_t kid_id = 0; kid_id < graph[node].size(); ++kid_id) {
      int kid = graph[node][kid_id];
      if (kid == parent) {
        continue;
      }
      visit(kid, node);
    }
    exit(node, parent);
  }

  void enter(int node, int parent) {
    //fprintf(stderr, "A enter: %d (%d)\n", node, parent);
    parents.insert(node);
    for (size_t bonus_id = 0; bonus_id < maybe_a_bonus[node].size(); ++bonus_id) {
      if (parents.find(maybe_a_bonus[node][bonus_id].first) != parents.end()) {
        leaf_bonuses.add(ranges[node], maybe_a_bonus[node][bonus_id].second);
      }
    }
  }

  void exit(int node, int parent) {
    //fprintf(stderr, "A exit: %d (%d)\n", node, parent);
    parents.erase(node);
  }
 private:
  graph_t &graph;
  maybe_bonus_t &maybe_a_bonus;
  interval_tree &leaf_bonuses;
  vector<pair<int, int> > &ranges;
  std::set<int> parents;
};

class dfs_a1 {
 public:
  dfs_a1(graph_t &graph, type_t type, vector<type_t> &types, vector<int> &leaves,
      vector<pair<int, int> > &ranges)
    : graph(graph), type(type), types(types), leaves(leaves), ranges(ranges) {
  }

  pair<int, int> xvisit(int root, vector<int> &children) {
    for (size_t i = 0; i < children.size(); ++i) {
      visit(children[i], root);
    }
    return ranges[root] = make_pair(0, leaves.size() - 1);
  }

  pair<int, int> visit(int node, int parent) {
    types[node] = type;
    pair<int, int> res(-1, -1);
    for (size_t kid_id = 0; kid_id < graph[node].size(); ++kid_id) {
      int kid = graph[node][kid_id];
      if (kid == parent) { continue; }
      pair<int, int> kid_res = visit(kid, node);
      if (kid_id == 0 || (kid_id == 1 && graph[node][0] == parent)) { res.first = kid_res.first; }
      if (kid_id == graph[node].size() - 1 || (kid_id == graph[node].size() - 2 && graph[node][graph[node].size() - 1] == parent)) { res.second = kid_res.second; }
    }
    if (res.first == -1) {
      // no kids --> leaf
      res.first = res.second = (int) leaves.size();
      leaves.push_back(node);
    }
    ranges[node] = res;
    return res;
  }
 private:
  graph_t &graph;
  type_t type;
  vector<type_t> &types;
  vector<int> &leaves;
  vector<pair<int, int> > &ranges;
};

class dfs_p {
 public:
  dfs_p(graph_t &graph, pair<int, int> p, type_t type,
      // output
      pair<int, int> &p_parents, vector<type_t> &types)
    : graph(graph), p(p), type(type), p_parents(p_parents), types(types) {
  }
  void run() {
    visit(p.first, -1);
  }
 private:
  bool visit(int node, int parent) {
    if (node == p.second) {
      p_parents.second = parent;
      types[node] = type;
      return true;
    }
    for (size_t kid_id = 0; kid_id < graph[node].size(); ++kid_id) {
      int kid = graph[node][kid_id];
      if (kid == parent) { continue; }
      if (visit(kid, node)) {
        if (node == p.first) {
          p_parents.first = kid;
        }
        types[node] = type;
        return true;
      }
    }
    return false;
  }
 private:
  graph_t &graph;
  pair<int, int> p;
  type_t type;
  pair<int, int> &p_parents;
  vector<type_t> &types;
};

class dfs_b {
 public:
  dfs_b(graph_t &graph, interval_tree &leaf_bonuses,
      vector<pair<int, int> > &ranges, range_bonus_t &range_bonus,
      vector<int> &direct_bonus, maybe_bonus_t &maybe_b_bonus)
    : graph(graph), leaf_bonuses(leaf_bonuses), ranges(ranges),
      range_bonus(range_bonus), direct_bonus(direct_bonus),
      maybe_b_bonus(maybe_b_bonus),
      bonus(0), max_bonus(-1), best_a_leaf_id(-1), best_b_leaf_id(-1) {
  }

  void xvisit(int root, vector<int> &children) {
    enter(root, -1);
    for (size_t i = 0; i < children.size(); ++i) {
      visit(children[i], root);
    }
    exit(root, -1);
  }

  pair<int, int> get_best() {
    return make_pair(best_a_leaf_id, best_b_leaf_id);
  }

  int get_score() {
    return max_bonus;
  }
 protected:
  void visit(int node, int parent) {
    enter(node, parent);
    int kids = 0;
    for (size_t kid_id = 0; kid_id < graph[node].size(); ++kid_id) {
      int kid = graph[node][kid_id];
      if (kid == parent) {
        continue;
      }
      ++ kids;
      visit(kid, node);
    }
    if (kids == 0) {
      leaf(node, parent);
    }
    exit(node, parent);
  }

  void enter(int node, int parent) {
    //fprintf(stderr, "B enter: %d (%d)\n", node, parent);
    parents.insert(node);
    for (size_t i = 0; i < range_bonus[node].size(); ++i) {
      //fprintf(stderr, ">> %d %d %d\n", ranges[range_bonus[node][i].first].first,
//          ranges[range_bonus[node][i].first].second, range_bonus[node][i].second);
      leaf_bonuses.add(ranges[range_bonus[node][i].first], range_bonus[node][i].second);
    }
    for (size_t i = 0; i < maybe_b_bonus[node].size(); ++i) {
      if (parents.find(maybe_b_bonus[node][i].first) != parents.end()) {
        bonus += maybe_b_bonus[node][i].second;
      }
    }
    bonus += direct_bonus[node];
  }

  void exit(int node, int parent) {
    //fprintf(stderr, "B exit %d (%d)\n", node, parent);
    for (size_t i = 0; i < range_bonus[node].size(); ++i) {
      //fprintf(stderr, ">> %d %d %d\n", ranges[range_bonus[node][i].first].first,
//          ranges[range_bonus[node][i].first].second, -range_bonus[node][i].second);
      leaf_bonuses.add(ranges[range_bonus[node][i].first], -range_bonus[node][i].second);
    }
    for (size_t i = 0; i < maybe_b_bonus[node].size(); ++i) {
      if (parents.find(maybe_b_bonus[node][i].first) != parents.end()) {
        bonus -= maybe_b_bonus[node][i].second;
      }
    }
    bonus -= direct_bonus[node];
    parents.erase(node);
  }

  void leaf(int node, int parent) {
    //fprintf(stderr, "leaf %d\n", node);
    if (max_bonus < leaf_bonuses.global_max() + bonus) {
      //fprintf(stderr, "  > %d %d\n", leaf_bonuses.global_max(), bonus);
      max_bonus = leaf_bonuses.global_max() + bonus;
      best_a_leaf_id = leaf_bonuses.max_leaf();
      best_b_leaf_id = node;
      //fprintf(stderr, "  updating bonus: %d %d %d\n", max_bonus, best_a_leaf_id, best_b_leaf_id);
    }
  }
 private:
  graph_t &graph;
  std::set<int> parents;
  interval_tree &leaf_bonuses;
  vector<pair<int, int> > &ranges;
  range_bonus_t &range_bonus;
  vector<int> &direct_bonus;
  maybe_bonus_t &maybe_b_bonus;

  int bonus;
  int max_bonus;
  int best_a_leaf_id, best_b_leaf_id;
};

void input(graph_t &graph, bonus_t &bonuses, pair<int, int> &p) {
  int N, M;
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

  scanf("%d", &M);
  bonuses.resize(M);
  for (int i = 0; i < M; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    --a; --b;
    bonuses.push_back(make_pair(make_pair(a, b), c));
  }
}

class weight_comparator {
 public:
  weight_comparator(vector<int> &weights)
    : weights(weights) {
  }
  bool operator()(int id1, int id2) {
    return weights[id1] < weights[id2];
  }
 private:
  vector<int> &weights;
};

class split_finder {
 public:
  split_finder(graph_t &graph, int start,
      // output
      int &split, vector<int> &a_children, vector<int> &b_children)
    : graph(graph), start(start), split(split), a_children(a_children),
      b_children(b_children), weights(graph.size(), 0) {
  }

  void run() {
    fill_weights(start, -1);
    locate_split();
  }
 private:
  int fill_weights(int node, int parent) {
    for (size_t i = 0; i < graph[node].size(); ++i) {
      int kid = graph[node][i];
      if (kid == parent) {
        continue;
      }
      weights[node] += fill_weights(kid, node);
    }

    return ++ weights[node];
  }

  void locate_split() {
    int current = start;
    while (true) {
      vector<int> children_ids(graph[current].size());
      for (size_t i = 0; i < graph[current].size(); ++i) {
        children_ids[i] = graph[current][i];
      }

      std::sort(children_ids.begin(), children_ids.end(),
          weight_comparator(weights));

      int last_child = children_ids.back();
      if (weights[last_child] * 2 > weights[current]) {
        int total_weight = weights[current];
        weights[current] -= weights[last_child];
        weights[last_child] = total_weight;
        current = last_child;
        continue;
      }
      split = current;
      if (weights[last_child] * 3 >= weights[current]) {
        a_children.push_back(last_child);
        b_children.insert(b_children.begin(), children_ids.begin(), children_ids.end() - 1);
        return;
      }
      int current_weight = weights[last_child];
      for (int i = (int) children_ids.size() - 2; i >= 0; --i) {
        current_weight += weights[children_ids[i]];
        if (current_weight * 3 >= weights[current]) {
          a_children.insert(a_children.begin(),
              children_ids.begin(), children_ids.begin() + i);
          b_children.insert(b_children.begin(),
              children_ids.begin() + i, children_ids.end());
          return;
        }
      }
      assert(0);
    }
  }
 private:
  graph_t &graph;
  int start;
  int &split;
  vector<int> &a_children, &b_children;

  vector<int> weights;
};

void split_graph(graph_t &old_graph, vector<int> &old_nmap,
    int split, vector<type_t> &types, bonus_t &bonuses,
    // output
    graph_t &a_new, vector<int> &a_nmap, bonus_t &a_bonuses,
    graph_t &b_new, vector<int> &b_nmap, bonus_t &b_bonuses) {
  a_nmap.resize(0);
  b_nmap.resize(0);

  vector<int> a_rev_map(old_graph.size());
  vector<int> b_rev_map(old_graph.size());

  for (size_t i = 0; i < old_graph.size(); ++i) {
    if ((int) i == split) {
      a_rev_map[i] = a_nmap.size();
      a_nmap.push_back(old_nmap[i]);
      b_rev_map[i] = b_nmap.size();
      b_nmap.push_back(old_nmap[i]);
    } else if (types[i] == TYPE_A) {
      a_rev_map[i] = a_nmap.size();
      a_nmap.push_back(old_nmap[i]);
    } else if (types[i] == TYPE_B) {
      b_rev_map[i] = b_nmap.size();
      b_nmap.push_back(old_nmap[i]);
    } else {
      assert(0);
    }
  }
  a_new.resize(a_nmap.size());
  b_new.resize(b_nmap.size());

  // add all vertices except split
  vector<int> *rmap = NULL;
  vector<vector<int> > *ngraph = NULL;
  for (size_t i = 0; i < old_graph.size(); ++i) {
    if ((int) i == split) {
      continue;
    } else if (types[i] == TYPE_A) {
      rmap = &a_rev_map;
      ngraph = &a_new;
    } else if (types[i] == TYPE_B) {
      rmap = &b_rev_map;
      ngraph = &b_new;
    }
    for (size_t j = 0; j < old_graph[i].size(); ++j) {
      (*ngraph)[(*rmap)[i]].push_back((*rmap)[old_graph[i][j]]);
    }
  }

  // add split to both a_new and b_new
  for (size_t j = 0; j < old_graph[split].size(); ++j) {
    int child = old_graph[split][j];
    if (types[child] == TYPE_A) {
      a_new[a_rev_map[split]].push_back(a_rev_map[child]);
    } else if (types[child] == TYPE_B) {
      b_new[b_rev_map[split]].push_back(b_rev_map[child]);
    }
  }

  // split bonuses
  a_bonuses.clear();
  b_bonuses.clear();
  for (size_t i = 0; i < bonuses.size(); ++i) {
    int a, b, c;
    a = bonuses[i].first.first;
    b = bonuses[i].first.second;
    c = bonuses[i].second;

    if ((a == split && types[b] == TYPE_A) ||
        (types[a] == TYPE_A && types[b] == split) ||
        (types[a] == TYPE_A && types[b] == TYPE_A)) {
      a_bonuses.push_back(make_pair(make_pair(a_rev_map[a], a_rev_map[b]), c));
    }
    if ((a == split && types[b] == TYPE_B) ||
        (types[a] == TYPE_B && types[b] == split) ||
        (types[a] == TYPE_B && types[b] == TYPE_B)) {
      b_bonuses.push_back(make_pair(make_pair(b_rev_map[a], b_rev_map[b]), c));
    }
  }
}

void bfs(graph_t &graph, int start, vector<int> &children, type_t type,
    // output
    vector<type_t> &types) {
  std::queue<int> q;

  q.push(start);
  types[start] = type;

  // oh well, manually push first level of children
  q.pop();
  for (size_t i = 0; i < children.size(); ++i) {
    q.push(children[i]);
    types[children[i]] = type;
  }

  while (!q.empty()) {
    int current = q.front(); q.pop();

    for (size_t kid_id = 0; kid_id < graph[current].size(); ++kid_id) {
      int kid = graph[current][kid_id];

      if (types[kid] == TYPE_NONE) {
        q.push(kid);
        types[kid] = type;
      }
    }
  }
}

void sort_bonuses(bonus_t &C, vector<type_t> &types,
    vector<pair<int, int> > &ranges,
    // output
    int &base_bonus, interval_tree &leaf_bonuses,
    maybe_bonus_t &maybe_a_bonus, maybe_bonus_t &maybe_b_bonus,
    vector<int> &direct_bonus, range_bonus_t &range_bonus) {

  for (size_t i = 0; i < C.size(); ++i) {
    int a = C[i].first.first, b = C[i].first.second, c = C[i].second;
    if (types[a] == TYPE_NONE || types[b] == TYPE_NONE) {
      continue;
    }
    if (types[a] == TYPE_P && types[b] == TYPE_P) { base_bonus += c; }
    if (types[a] == TYPE_B && types[b] == TYPE_P) { direct_bonus[a] += c; }
    if (types[a] == TYPE_P && types[b] == TYPE_B) { direct_bonus[b] += c; }
    if (types[a] == TYPE_A && types[b] == TYPE_P) { leaf_bonuses.add(ranges[a], c); }
    if (types[a] == TYPE_P && types[b] == TYPE_A) { leaf_bonuses.add(ranges[b], c); }
    if (types[a] == TYPE_A && types[b] == TYPE_B) { range_bonus[b].push_back(make_pair(a, c)); }
    if (types[a] == TYPE_B && types[b] == TYPE_A) { range_bonus[a].push_back(make_pair(b, c)); }
    if (types[a] == TYPE_A && types[b] == TYPE_A) {
      if (a == b) {
        leaf_bonuses.add(ranges[a], c);
      } else {
        maybe_a_bonus[a].push_back(make_pair(b, c));
        maybe_a_bonus[b].push_back(make_pair(a, c));
      }
    }
    if (types[a] == TYPE_B && types[b] == TYPE_B) {
      if (a == b) {
        direct_bonus[a] = c;
      } else {
        maybe_b_bonus[a].push_back(make_pair(b, c));
        maybe_b_bonus[b].push_back(make_pair(a, c));
      }
    }
  }
}

ans_t conquer(graph_t &graph, bonus_t &bonuses,
    // output
    int &split, vector<type_t> &types) {
  vector<int> a_children, b_children;
  split_finder sf(graph, 0, split, a_children, b_children);
  sf.run();

  vector<int> leaves;
  vector<pair<int, int> > ranges(graph.size());

  // compute ranges, leaves, color A
  dfs_a1 range_computer(graph, TYPE_A, types, leaves, ranges);
  range_computer.xvisit(split, a_children);

  // color B
  bfs(graph, split, b_children, TYPE_B, types);

  // precalc bonuses
  //print_types("types", types);
  int base_bonus = 0;
  //fprintf(stderr, "lb: %d\n", (int) leaves.size());
  interval_tree leaf_bonuses(leaves.size());
  vector<int> direct_bonus(graph.size());
  range_bonus_t range_bonus(graph.size());
  maybe_bonus_t maybe_a_bonus(graph.size()), maybe_b_bonus(graph.size());
  sort_bonuses(bonuses, types, ranges, base_bonus, leaf_bonuses,
      maybe_a_bonus, maybe_b_bonus, direct_bonus, range_bonus);

  // put all A-only bonuses in leaf_bonuses
  dfs_a maybe_a_decide(graph, maybe_a_bonus, leaf_bonuses, ranges);
  maybe_a_decide.xvisit(split, a_children);

  // figure out A-B and B-only bonuses
  dfs_b traveler(graph, leaf_bonuses, ranges, range_bonus, direct_bonus, maybe_b_bonus);
  traveler.xvisit(split, b_children);
  pair<int, int> res = traveler.get_best();
  int score = traveler.get_score();

  int res_a = leaves[res.first],
      res_b = res.second,
      res_c = score + base_bonus;

  return ans_t(res_a, res_b, res_c);
}

ans_t conquer_trivial(graph_t &graph, bonus_t &bonuses) {
  assert(graph.size() == 2);
  int bonus = 0;
  for (size_t i = 0; i < bonuses.size(); ++i) {
    bonus += bonuses[i].second;
  }
  return ans_t(0, 1, bonus);
}

ans_t best;
void update_best(ans_t ans, vector<int> &map) {
    ans = ans_t(map[ans.a], map[ans.b], ans.c);
    if (ans.c > best.c) {
      best = ans;
    }
}

int sum(bonus_t &bonuses) {
  int sum = 0;
  for (size_t i = 0; i < bonuses.size(); ++i)
    sum += bonuses[i].second;
  return sum;
}

void do_it(graph_t &graph, vector<int> &map, bonus_t &bonuses) {
  assert(graph.size() != 1);

  if (sum(bonuses) <= best.c)
    return;

  if (graph.size() == 2) {
    ans_t res = conquer_trivial(graph, bonuses);
    update_best(res, map);
    return;
  }
  int split;
  vector<type_t> types(graph.size(), TYPE_NONE);
  ans_t res = conquer(graph, bonuses, split, types);

  update_best(res, map);

  graph_t a_graph, b_graph;
  vector<int> a_map, b_map;
  bonus_t a_bonuses, b_bonuses;
  split_graph(graph, map, split, types, bonuses,
      a_graph, a_map, a_bonuses,
      b_graph, b_map, b_bonuses);

  do_it(a_graph, a_map, a_bonuses);
  do_it(b_graph, b_map, b_bonuses);
}

int main() {
  graph_t graph;
  bonus_t bonuses;
  pair<int, int> p;
  input(graph, bonuses, p);

  vector<int> initial_map(graph.size());
  for (size_t i = 0; i < graph.size(); ++i) {
    initial_map[i] = i;
  }
  do_it(graph, initial_map, bonuses);

  printf("%d %d %d\n", best.a + 1, best.b + 1, best.c);

  // // Store parents information in A and B trees
  // // vector<int> parents(graph.size());
  // // Classify all nodes into A, B and P
  // vector<type_t> types(graph.size(), TYPE_NONE);

  // pair<int, int> p_parents(p.second, p.first);
  // // dfs_p detect_p(graph, p, TYPE_P, p_parents, types);
  // // detect_p.run();

  // fprintf(stderr, "%d-%d %d-%d\n",
  //     p.first, p_parents.first,
  //     p.second, p_parents.second);

  // // leaves of A
  // vector<int> leaves;
  // // bfs(graph, p.first, p_parents.first, true, TYPE_A, &parents, types, &leaves);

  // // print_vi("parents", parents);
  // // print_vi("leaves", leaves);

  // // store first and last leaf id for all nodes in A.
  // vector<pair<int, int> > ranges(graph.size());
  // // node_ranges(graph, leaves, parents, p.first, ranges);
  // dfs_a1 range_computer(graph, TYPE_A, types, leaves, ranges);
  // range_computer.visit(p.first, p_parents.first);
  // print_vi("leaves", leaves);

  // bfs(graph, p.second, p_parents.second, TYPE_B, types);
  // // print_vi("parents", parents);

  // print_types("types", types);
  // int base_bonus = 0;
  // fprintf(stderr, "lb: %d\n", (int) leaves.size());
  // interval_tree leaf_bonuses(leaves.size());
  // vector<int> direct_bonus(graph.size());
  // range_bonus_t range_bonus(graph.size());
  // maybe_bonus_t maybe_a_bonus(graph.size()), maybe_b_bonus(graph.size());
  // sort_bonuses(bonuses, types, ranges, base_bonus, leaf_bonuses,
  //     maybe_a_bonus, maybe_b_bonus, direct_bonus, range_bonus);

  // for (size_t i = 0; i < graph.size(); ++i) {
  //   fprintf(stderr, "len maybes %d %d\n",
  //       (int) maybe_a_bonus[i].size(), (int) maybe_b_bonus[i].size());
  // }
  // dfs_a maybe_a_decide(graph, maybe_a_bonus, leaf_bonuses, ranges);
  // maybe_a_decide.visit(p.first, p_parents.first);

  // print_vi("direct bonus", direct_bonus);
  // print_rb("range bonus", range_bonus);

  // leaf_bonuses.print();

  // dfs_b traveler(graph, leaf_bonuses, ranges, range_bonus, direct_bonus, maybe_b_bonus);
  // traveler.visit(p.second, p_parents.second);
  // pair<int, int> res = traveler.get_best();
  // int score = traveler.get_score();

  // printf("%d %d %d\n", leaves[res.first] + 1, res.second + 1, score + base_bonus);

  return 0;
}
