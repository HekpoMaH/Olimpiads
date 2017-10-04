#include<iostream>
#include<cstdio>
#include<utility>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<cassert>
#include<cstdlib>
using namespace std;

typedef pair<int, int> interval; // leaves interval in the interval tree
typedef multimap< int, pair<int,int> > Bonuses; // from a starting vertex to pair(final vertex, bonus)

struct Answer {
  int from, to;  // the start and final vertices
  int bonus;     // total bonus on the from-to path

  Answer() {}
  Answer(int _from, int _to, int _bonus)
    : from(_from), to(_to), bonus(_bonus) {}

  bool operator<(const Answer &b) {
    return bonus < b.bonus;
  }
};

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
    _rub = range.second;
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

class Tree {
  Bonuses B; // from a vertex to pair<vertex, bonus>
  vector<int> local2orig;

  vector<interval> v2leaves; // from vertex to an interval of leaves for the interval tree
  vector<int> leaf2v;

  int A_leaves;
  vector<bool> traced_B; // whether a vertex lies on the current path in B

 public:
  vector< vector<int> > g;     // the tree as lists of neighbours for every node



  pair<int, int> input() {
    int n, c, u, v, bonus;
    pair<int, int> p;

    scanf("%d", &n);
    g.resize(n);
    
    local2orig.resize(n);
    for (int i=0; i<n; i++)
      local2orig[i] = i;

    for (int i=0; i<n-1; i++) {
      scanf("%d%d", &u, &v);
      --u; --v;
      g[u].push_back(v);
      g[v].push_back(u);
      
      if (i==0)
        p = make_pair(u, v);
    }

    scanf("%d", &c);
    for (int i=0; i<c; i++) {
      scanf("%d%d%d", &u, &v, &bonus);
      --u; --v;
      B.insert( make_pair(u, make_pair(v, bonus)) );
      B.insert( make_pair(v, make_pair(u, bonus)) );
    }

    return p;
  }

  bool check_bonuses() {
    set< pair<int,int> > S;

    for (Bonuses::iterator i=B.begin(); i!=B.end(); i++) {
      int from = i->first;
      int to = i->second.first;
      S.insert( make_pair(from, to) ); 
    }

    return S.size() == B.size();
  }

  int find_center() {
    return 12345 % g.size();
    
    /*
    queue<int> Q;
    vector<bool> V(g.size(), 0);
    int u = 0, v;

    assert(g.size() >= 1);

    for (int i=0; i<g.size(); i++)
      if (g[i].size() == 1) { // leaf
        Q.push(i);
        V[i] = true;
      }

    while (!Q.empty()) {
      u = Q.front();
      Q.pop();

      for(int i=0; i<g[u].size(); i++) {
        v = g[u][i];
        if (!V[v]) {
          V[v] = true;
          Q.push(v);
        }
      }
    }

    return u; // the last popped vertex from Q is a center
    */
  }

  bool dfs(int node, int parent, int end, set<int> &nodes) {
    if (node == end) {
      nodes.insert(node);
      return true;
    }
    for (size_t i = 0; i < g[node].size(); ++i) {
      int kid = g[node][i];

      if (kid == parent) { continue; }

      if (dfs(kid, node, end, nodes)) {
        nodes.insert(node);
        return true;
      }
    }
    return false;
  }

  int calc_bonuses(int a, int b) {
    set<int> nodes;

    dfs(a, -1, b, nodes);

    int bonus = 0;
    for (Bonuses::iterator i=B.begin(); i!=B.end(); i++) {
      int from = i->first;
      int to = i->second.first;
      int b = i->second.second;

      if (nodes.find(from) != nodes.end() &&
          nodes.find(to) != nodes.end()) {
        bonus += b;
      }
    }

    assert(bonus % 2 == 0);
    return bonus / 2;
  }

  bool is_valid(bool print=false) {
    int v, u, n = g.size();
    queue<int> Q;
    vector<bool> V(n, 0);

    assert(n == local2orig.size());

    Q.push(0);
    V[0] = true;

    for(Bonuses::iterator i=B.begin(); i!=B.end(); i++)
      if (i->second.first < 0 || i->second.first >= n)
        return false;

    if (print) cerr << "Tree: n=" << n << endl;

    while (!Q.empty()) {
      u = Q.front();
      Q.pop();

      for(int i=0; i<g[u].size(); i++) {
        v = g[u][i];
        
        if (!print)
          if(v<0 || v>=n || v==u)
            return false;

        if (!V[v]) {
          if (print) fprintf(stderr, " (%d, %d)\n", u, v);
          V[v] = true;
          Q.push(v);
        }
      }
    }

    if (print) {
      cerr << "Bonuses:" << endl;

      for (Bonuses::iterator i=B.begin(); i!=B.end(); i++) {
        fprintf(stderr, " (%d, %d) -> %d\n", i->first, i->second.first, i->second.second); 
      }
    }

    return true;
  }

  // return the maximum subtree excluding 'out' vertex and including 'in' vertex
  Tree get_subtree(int out, int in) {
    Tree subtree;
    queue<int> Q;
    vector<int> V(g.size(), -1);
    vector<int> orig2local(g.size(), -1);
    int n=0, u, v;

    Q.push(in);
    subtree.g.push_back( vector<int>() );
    subtree.local2orig.push_back(in);
    orig2local[in] = n;
    V[out] = -2;
    V[in] = n++;

    while (!Q.empty()) {
      u = Q.front();
      Q.pop();

      for (int i=0; i<g[u].size(); i++) {
        v = g[u][i];
        if (V[v] == -1) {
          Q.push(v);
          //fprintf(stderr, "(%d %d) -> (%d %d)\n", u, v, V[u], n);
          subtree.g[ V[u] ].push_back( n );
          subtree.g.push_back( vector<int>() );
          subtree.g[ n ].push_back( V[u] );
          subtree.local2orig.push_back(v);
          orig2local[v] = n;
          //fprintf(stderr, "orig2local[%d]=%d\n", v, n);
          V[v] = n++;
        }
      }
    }

    for (Bonuses::iterator i=B.begin(); i!=B.end(); i++) {
      int u = orig2local[i->first];
      int v = orig2local[i->second.first];

      // both bonus ends in the subtree
      if (u != -1 && v != -1) {
        //fprintf(stderr, "Bonus (%d, %d)->%d becomes (%d, %d)->%d\n",
        //    i->first, i->second.first, i->second.second,
        //    u, v, i->second.second);

        subtree.B.insert( make_pair(u, make_pair(v, i->second.second)) );
      }
    }

    assert(subtree.is_valid());

    return subtree;
  }

  // traces the A subtree, updates the v2leaves map
  // returns the number of leaves in it
  int init_v2leaves(int prev, int curr, int first_leaf) {
    int leaves = 0, next;

    if (g[curr].size() == 1) {
      // leaf
      leaves = 1;
      assert(leaf2v[first_leaf] == -1);
      leaf2v[first_leaf] = curr;
      //fprintf(stderr, "leaf2v[%d] = %d\n", first_leaf, curr);
    } else { 
      // count the number of leaves recursively
      for (int i=0; i<g[curr].size(); i++)
        if ((next = g[curr][i]) != prev)
          leaves += init_v2leaves(curr, next, first_leaf+leaves);
    }

    assert(v2leaves[curr] == interval());
    v2leaves[curr] = make_pair(first_leaf, first_leaf+leaves);
    assert(v2leaves[curr] != interval());
    //fprintf(stderr, "v2leaves[%d] = (%d, %d)\n", curr, first_leaf, first_leaf+leaves);
    
    return leaves;
  }

  void update_bonuses_from(int curr, int coef, interval_tree &it) {
    //fprintf(stderr, "Update_bonuses_from(%d)\n", curr);

    for (Bonuses::iterator i=B.lower_bound(curr); i!=B.upper_bound(curr); i++) {
      int to    = i->second.first;
      int bonus = i->second.second;
      //fprintf(stderr, "  to %d by bonus %d\n", to, bonus);

      interval to_int, curr_int;
      
      if (v2leaves[curr] != interval()) {
        // curr is a subtree of A
        curr_int = v2leaves[curr];

        // to is in subtree of A
        to_int = v2leaves[to];

        if (! (curr_int.first <= to_int.first && to_int.second <= curr_int.second))
          continue;

        if (curr_int == to_int) {
          // one after another
          if (curr < to)
            // break tie
            continue;
        }
      } else {
        // curr is in B
        // curr_int = interval(0, A_leaves);

        if (traced_B[to])
          // to lies on the path to the root of A
          to_int = interval(0, A_leaves);
        else
          to_int = v2leaves[to];
      }
       
      if (to_int == interval())
        continue;

      // if bonus is going to the same subtree
      //if (curr_int.first <= to_int.first && to_int.second <= curr_int.second) {
        //fprintf(stderr, "curr=%d, to=%d; %d <= %d < %d <= %d\n", curr, to, curr_int.first, to_int.first, to_int.second, curr_int.second);
        //it.print();
        //fprintf(stderr, "(before) global_max: (%d, %d) -> %d, max_leaf: %d\n", local2orig[curr], local2orig[leaf2v[it.max_leaf()]], it.global_max(), it.max_leaf());
        it.add(to_int, coef * bonus);
        assert(curr == i->first);
        //it.print();
        //fprintf(stderr, " Bonus update: bonus(%d, %d) -> %d updates the leaves [%d,%d)\n", curr, to, coef*bonus, to_int.first, to_int.second);

        //if (coef == +1) {
          //fprintf(stderr, "%d %d\n", local2orig[curr], curr);
          //assert(local2orig[curr] == curr);
          //assert(local2orig[leaf2v[it.max_leaf()]] == leaf2v[it.max_leaf()]);
          //fprintf(stderr, " global_max: (%d, %d) -> %d, max_leaf: %d\n", local2orig[curr], local2orig[leaf2v[it.max_leaf()]], it.global_max(), it.max_leaf());

        //}
      //}
    }
  }

  void trace_A(int prev, int curr, interval_tree &it) {
    int next;

    for (int i=0; i<g[curr].size(); i++)
      if ((next = g[curr][i]) != prev)
        trace_A(curr, next, it);

    update_bonuses_from(curr, +1, it);
  }
  
  Answer trace_B(int prev, int curr, interval_tree &it) {
    update_bonuses_from(curr, +1, it);
    traced_B[curr] = true;

    //if (v2leaves[curr] != interval()) {
    //  fprintf(stderr, "  v2leaves[%d] = (%d, %d)\n", curr, v2leaves[curr].first, v2leaves[curr].second);
    //}

    //assert(v2leaves[curr] == interval());
    //v2leaves[curr] = interval(0, A_leaves);

    Answer tmp, ans;
    int next, best_to = leaf2v[it.max_leaf()];
    ans = Answer(local2orig[curr], local2orig[best_to], it.global_max());

    //fprintf(stderr, " curr=%d: init ans=(%d, %d) -> %d\n", curr, ans.from, ans.to, ans.bonus);

    for (int i=0; i<g[curr].size(); i++)
      if ((next = g[curr][i]) != prev)
        if (ans < (tmp = trace_B(curr, next, it)))
          ans = tmp;

    //cerr << "trace_B(curr=" << curr << ")::ans: " << ans.from << " " << ans.to << " " << ans.bonus << endl;

    update_bonuses_from(curr, -1, it);
    //assert(v2leaves[curr] != interval());
    //v2leaves[curr] = interval();
    traced_B[curr] = false;

    return ans;
  }
    
 public:
  // finds the optimal path through the vertex 'center'
  Answer find_path_through(int B_root, int A_root) {
    int n = g.size();

    assert(n > 1);

    //is_valid(true);

    v2leaves.resize(n);
    leaf2v.resize(n, -1);
    traced_B.resize(n, false);

    assert( !g[B_root].empty() );

    //cerr << "A_root: " << A_root << endl;
    //cerr << "B_root: " << B_root << endl;

    A_leaves = init_v2leaves(B_root, A_root, 0);

    //cerr << "A_leaves: " << A_leaves << endl;

    interval_tree it(A_leaves);

    //cerr << "trace_A..." << endl;
    trace_A(B_root, A_root, it);
    //cerr << "trace_B..." << endl;
    return trace_B(A_root, B_root, it);
  }

  Answer divide_and_conquire() {
    // choose a center for splitting the tree into subtrees
    int center = find_center();

    if (g.size() <= 1)
      return Answer(0, 0, 0);

    cerr << "n: " << g.size() << endl;
    
    // lets suppose that the best path goes through the center
    Answer ans = find_path_through(center, g[center][0]); 

    // solve for subtrees
    for(int i=0; i<g[center].size(); i++) {
      //fprintf(stderr, "Getting subtree %d (%d->%d)...\n", i, center, g[center][i]);
      Tree subtree = get_subtree(center, g[center][i]);
      Answer subans = subtree.divide_and_conquire();
      if (ans.bonus < subans.bonus)
        ans = subans;
    }

    return ans;
  }
};

int main(int argn, char* argv[]) {
  Tree T;
  Answer ans(0, 0, 0);
  
  // p is the first edge
  pair<int, int> p = T.input();

  if (!T.check_bonuses()) {
    cerr << "Wrong bonuses!\n";
    return -1;
  }

  //if (argn > 1) {
  if (true) {
    cerr << "With P given" << endl;
    cerr << "p: " << p.first << " " << p.second << endl;
    ans = T.find_path_through(p.first, p.second);
  } else {
    /*
    Answer curr_ans;
    for(int i=0; i<20; i++) {
      Tree T_tmp = T;
      p.first = rand() % T_tmp.g.size();
      p.second = T_tmp.g[p.first][ rand() % T_tmp.g[p.first].size() ];
      curr_ans = T_tmp.find_path_through(p.first, p.second);

      if (T_tmp.calc_bonuses(curr_ans.from, curr_ans.to) != curr_ans.bonus) {
        cerr << "real bonus: " << T_tmp.calc_bonuses(curr_ans.from, curr_ans.to) << " index-tree bonus: " << curr_ans.bonus << endl;
        assert(false);
      }

      if (ans < curr_ans)
        ans = curr_ans;
    }
    */
    ans = T.divide_and_conquire();
  }
    
  printf("%d %d %d\n", ans.from+1, ans.to+1, ans.bonus);

  return 0;
}

