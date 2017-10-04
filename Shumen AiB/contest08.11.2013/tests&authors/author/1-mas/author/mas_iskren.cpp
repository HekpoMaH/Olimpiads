#include <stdio.h>
#include <assert.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <utility>
#include <vector>

/**
 * hash_t will represent a tree in a easy-to-compare way.
 * Leaves hashes are computed by the name, higher order trees are computed
 * using hash_combine.
 */
typedef std::pair<unsigned long long, unsigned long long> hash_t;
const hash_t NONE = hash_t(-1, -1);
const hash_t HBASE = hash_t(29, 31);
const hash_t HBASE2 = hash_t(999999929, 999999937);

hash_t dup(unsigned long long a) {
  return hash_t(a, a+3);
}

std::map<hash_t, std::string> hash2str;
const char *h2s(hash_t h) {
  const int BUFFER_COUNT = 16;
  static char buffers[BUFFER_COUNT][100];
  static char bid = 0;

  char *res = buffers[bid];
  if (hash2str.find(h) != hash2str.end()) {
    sprintf(res, "%s", hash2str[h].c_str());
  } else {
    sprintf(res, "(%Lx, %Lx)", h.first, h.second);
  }
  ++ bid;
  bid &= BUFFER_COUNT-1;
  return res;
}

hash_t &operator += (hash_t &lvalue, const hash_t &rvalue) {
  lvalue.first += rvalue.first;
  lvalue.second += rvalue.second;
  return lvalue;
}

hash_t &operator -= (hash_t &lvalue, const hash_t &rvalue) {
  lvalue.first -= rvalue.first;
  lvalue.second -= rvalue.second;
  return lvalue;
}

hash_t &operator *= (hash_t &lvalue, const hash_t &rvalue) {
  lvalue.first *= rvalue.first;
  lvalue.second *= rvalue.second;
  return lvalue;
}

const hash_t operator + (const hash_t &lvalue, const hash_t &rvalue) {
  hash_t result = lvalue;
  result += rvalue;
  return result;
}

const hash_t operator - (const hash_t &lvalue, const hash_t &rvalue) {
  hash_t result = lvalue;
  result -= rvalue;
  return result;
}

const hash_t operator * (const hash_t &lvalue, const hash_t &rvalue) {
  hash_t result = lvalue;
  result *= rvalue;
  return result;
}

const int MAXN = 1 << 13;
const int MAXE = 2 * MAXN;
const int NAMELEN = 16;

/**
 * Node in neighbours list graph.
 */
struct el {
  int to;
  int next;
  el() {}
  el(int to, int next) : to(to), next(next) {}
};

int N[2], E[2], L[2];
el buf[2][MAXE];
int vec[2][MAXN];

/**
 * Keep node in tree with computed hash.
 *
 * Check hash_tree for more details.
 */
struct queue_t {
  int v;
  hash_t hash;
  queue_t() {}
  queue_t(int v, hash_t hash) : v(v), hash(hash) {}
};

std::vector<hash_t> common_leaves;

hash_t leaf2hash[2][MAXN];

std::map<hash_t, int> hash2leaf[2];
typedef std::map<hash_t, std::pair<hash_t, hash_t> > h2h2_t;
h2h2_t hash2hashes;

/**
 * Generate a hash given leaf name.
 */
hash_t hash_string(const char *s) {
  // printf("%s -> ", s);
  hash_t res = dup(0);
  while (*s) {
    res *= HBASE;
    res += dup(*s++ - 'A');
  }
  // printf("%s\n", h2s(res));
  return res;
}

/**
 * Generate a binary tree hash, given the hashes of both children.
 */
hash_t hash_combine(hash_t a, hash_t b) {
  hash_t aa = std::min(a, b),
         bb = std::max(a, b);

  if (bb == NONE)
    return aa;

  hash_t res;
  res = hash_t(
      aa.first * bb.second + aa.first * HBASE2.first + bb.second,
      aa.second * bb.first + bb.first * HBASE2.second + aa.second);

  h2h2_t::iterator it = hash2hashes.find(res);
  if (it != hash2hashes.end()) {
    // if (it->second.first != aa
    //     || it->second.second != bb) {
    //   printf("BAD ");
    //   printf("%s %s (%s)-- %s %s\n",
    //       h2s(it->second.first), h2s(it->second.second), h2s(res),
    //       h2s(aa), h2s(bb));
    // }
    assert(it->second.first == aa);
    assert(it->second.second == bb);
  } else {
    hash2hashes[res] = std::make_pair(aa, bb);
    // printf("GOOD ");
    // printf("%s %s --> %s\n", h2s(aa), h2s(bb), h2s(res));
  }
  //printf("%x %x --> %x\n", a, b, res);
  return res;
}

/**
 * Build a tree given a root hash
 */
class TreeBuilder {
 public:
  std::vector<el> buf;
  std::vector<hash_t> node_hash;
  std::vector<int> vec;

  void build(hash_t hash) {
    _build(hash, -1);
  }

  int add_node(hash_t h) {
    int node_id = vec.size();
    vec.push_back(-1);
    node_hash.push_back(h);
    return node_id;
  }

  void add_edge(int a, int b) {
    buf.push_back(el(b, vec[a]));
    vec[a] = buf.size() - 1;
    buf.push_back(el(a, vec[b]));
    vec[b] = buf.size() - 1;
  }

  void print() {
    printf("%d\n", buf.size() / 2);
    for (int i = 0; i < buf.size(); i += 2) {
      printf("%d %d\n", buf[i].to, buf[i+1].to);
    }
    int leaves = 0;
    for (int i = 0; i < vec.size(); ++i) {
      if (hash2str.find(node_hash[i]) != hash2str.end()) {
        ++ leaves;
      }
    }
    printf("%d\n", leaves);
    for (int i = 0; i < vec.size(); ++i) {
      if (hash2str.find(node_hash[i]) != hash2str.end()) {
        printf("%d %s\n", i, hash2str[node_hash[i]].c_str());
      }
    }
  }

 private:
  void _build(hash_t hash, int parent) {
    if (hash == NONE) return;

    int node_id = add_node(hash);
    if (parent != -1) {
      add_edge(parent, node_id);
    }

    std::pair<hash_t, hash_t> kids = hash2hashes[hash];
    _build(kids.first, node_id);
    _build(kids.second, node_id);
  }
};

/**
 * internal function used by hash_tree
 */
el find_free(int v, int *cvec, el *cbuf, int *deg) {
  for (int e = cvec[v]; e != -1; e = cbuf[e].next)
    if (deg[cbuf[e].to] > 1)
      return cbuf[e];
  return el(-1, -1);
}

/**
 * Given tree id t (0 or 1) and a set of chosen leaves, compute the hash of
 * the subtree containing only those leaves. A bfs is done from the leaves
 * upward, that combines nodes with already known hashes.
 *
 * Non chosen leaves are given the special value NONE, that when combined with
 * a non-NONE hash produces the other hash (check hash_combine).
 *
 * In the end there is either one hash or three hashes. common_tree_exists
 * combines them properly. */
std::vector<hash_t> hash_tree(int t, const std::set<int> &leaves) {
  static int deg[MAXN];
  static queue_t queue[MAXN];
  static std::vector<hash_t> hashes[MAXN];

  //printf("leaves size: %d\n", (int) leaves.size());
  for (std::set<int>::const_iterator it = leaves.begin(); it != leaves.end(); ++it) {
    //printf(" %d", *it);
  }
  //puts("");
  /* std::copy(leaves.begin(), leaves.end(), std::output_iterator(std::cout, " ")); */
  /* std::cout << std::endl; */

  int qend = 0;
  int *cvec = vec[t];
  el *cbuf = buf[t];
  // put all leaves in queue and initialize input degrees
  for (int v = 0; v < N[t]; ++v) {
    hashes[v].clear();

    if (cbuf[cvec[v]].next == -1) {
      deg[v] = -1;
      if (leaves.find(v) != leaves.end()) {
        //printf("adding leaf %d %x\n", v, leaf2hash[t][v]);
        queue[qend++] = queue_t(v, leaf2hash[t][v]);
      } else {
        queue[qend++] = queue_t(v, NONE);
      }
    } else {
      deg[v] = 3;
    }
  }

  // bfs
  int c;
  for (c = 0; c < qend; ++c) {
    queue_t cq = queue[c];
    //printf("queue -> %d %x (hashes %d)\n", cq.v, cq.hash, (int) hashes[cq.v].size());
    if (hashes[cq.v].size() == 3) {
      break;
    }
    // assert(hashes[cq.v].size() == 2);
    // find edge that points to non traversed node
    el edge = find_free(cq.v, cvec, cbuf, deg);
    if (edge.to == -1) {
      // no more left
      break;
    }
    hashes[edge.to].push_back(cq.hash);
    if (--deg[edge.to] == 1) {
      // push in queue
      queue[qend++] = queue_t(edge.to, hash_combine(hashes[edge.to][0], hashes[edge.to][1]));
    }
  }

  if (hashes[queue[c].v].size() == 3) {
    return hashes[queue[c].v];
  } else {
    assert(qend - c == 2);
    std::vector<hash_t> res;
    res.push_back(hash_combine(queue[c].hash, queue[c+1].hash));
    return res;
  }
}

/**
 * Checks if there exists a common subtree, that has all the given leaves.
 *
 * This is a thin wrapper around hash_tree, that takes care of combining the
 * 3 hashes that hash_tree may produce.
 *
 * 3 hashes (trees) can be combined in 3 ways to produce one three: if a,
 * b and c denote the trees, then:
 *
 *   /\     /\     /\
 *  /\ \   /\ \   /\ \
 * a  b c a  c b b  c a
 *
 * are all valid trees.
 *
 * Possible tree hashes for one of the trees are intersected with possible tree
 * hashes of the other tree to see if there is a common hash (tree).
 */
bool common_tree_exists(const std::vector<hash_t> &leaves) {
  std::vector<hash_t> hashes[2];

  //printf("leaves hashes ->");
  for (std::vector<hash_t>::const_iterator it = leaves.begin(); it != leaves.end(); ++it) {
    //printf(" %x", *it);
  }
  //puts("");

  for (int t = 0; t < 2; ++t) {
    std::set<int> leaveIds;
    for (int i = 0; i < (int) leaves.size(); ++i) {
      leaveIds.insert(hash2leaf[t][leaves[i]]);
    }
    hashes[t] = hash_tree(t, leaveIds);

    //printf("got hashes:");
    for (int i = 0; i < (int) hashes[t].size(); ++i) {
      //printf(" %x", hashes[t][i]);
    }
    //puts("");

    if (hashes[t].size() == 3) {
      // combine those in 3 different ways to produce 1 hash
      std::vector<hash_t> upd_hashes;
      for (int i = 0; i < 3; ++i) {
        upd_hashes.push_back(hash_combine(
              hashes[t][i], hash_combine(
                hashes[t][(i+1)%3], hashes[t][(i+2)%3])));
      }
      hashes[t] = upd_hashes;
    } else {
      assert(hashes[t].size() == 1);
    }
  }

  // intersect possible hashes and hope for a match
  std::vector<hash_t> common;
  set_intersection(
      hashes[0].begin(), hashes[0].end(),
      hashes[1].begin(), hashes[1].end(),
      back_inserter(common));

  return !common.empty();
}

/**
 * Reads the 2 given trees.
 * Computes hashes for all leaves.
 * Computes the set of common leaves, used later for finding subtrees.
 */
void input(FILE *in) {
  std::set<hash_t> leaves[2];

  for (int t = 0; t < 2; ++t) {
    //printf("t = %d\n", t);
    fscanf(in, "%d", N + t);
    E[t] = N[t] - 1;
    int bp = 0;
    el *cbuf = buf[t];
    int *cvec = vec[t];
    memset(cvec, -1, sizeof(int) * MAXN);
    for (int e = 0; e < E[t]; ++e) {
      //printf("e = %d\n", e);
      int a, b;
      fscanf(in, "%d %d", &a, &b);
      --a; --b;

      cbuf[bp] = el(b, cvec[a]);
      cvec[a] = bp++;

      cbuf[bp] = el(a, cvec[b]);
      cvec[b] = bp++;
    }

    fscanf(in, "%d", L + t);
    //printf("got L: %d\n", L[t]);
    for (int l = 0; l < L[t]; ++l) {
      //printf("l = %d\n", l);
      static char name[NAMELEN];
      int v;
      fscanf(in, "%d %s", &v, name);
      --v;

      // compute hash and hash2leaf mapping
      hash_t hash = hash_string(name);
      leaf2hash[t][v] = hash;
      leaves[t].insert(hash);
      hash2leaf[t][hash] = v;
      hash2str[hash] = std::string(name);
    }

    for (int v = 0; v < N[t]; ++v) {
      //printf("%d ->", v);
      for (int e = cvec[v]; e != -1; e = cbuf[e].next) {
        //printf(" %d", cbuf[e].to);
      }
      //puts("");
    }
  }

  // compute common_leaves
  std::set_intersection(
      leaves[0].begin(), leaves[0].end(),
      leaves[1].begin(), leaves[1].end(),
      std::back_inserter(common_leaves));
}

// set of leaves that yield the best solution
std::vector<hash_t> besttaken;
/**
 * Tries to build a large subtree by shuffling all the common leaves, and then
 * greedily adding leaves while there exists a common subtree containing those
 * leaves.
 */
int solve() {
  // shuffle leaves, and iterate linearly, adding every one that can be added.
  int best = 0;
  for (int iter=0; iter<20; iter++) {
    std::random_shuffle(common_leaves.begin(), common_leaves.end());
    std::vector<hash_t> taken;
    taken.push_back(common_leaves[0]);
    for (int l = 1; l < (int) common_leaves.size(); ++l) {
      taken.push_back(common_leaves[l]);
      if (!common_tree_exists(taken)) {
        taken.pop_back();
      }
    }
    best = std::max(best, (int) taken.size());

    if (best == taken.size())
      besttaken = taken;

    // one iteration -- maybe increase if it fits TL
    //break;
  }

  for (int i=0; i<besttaken.size(); i++) {
    for (int t=0; t<2; t++) {
      int v = hash2leaf[t][ besttaken[i] ] + 1;
      // fprintf(stderr, "Number of the %d-th chosen leaf in tree #%d = %d\n", i, t, v);
    }
  }

  return best;
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    // solution mode
    input(stdin);
    int res = solve();
    printf("%d\n", res);
    for (int i = 0; i < besttaken.size(); ++i) {
      printf("%s\n", hash2str[besttaken[i]].c_str());
    }
  } else {
    // checker mode
    FILE *in = fopen(argv[1], "r");
    input(in);
    fclose(in);
    FILE *out = fopen(argv[2], "r");

    int N;
    fscanf(out, "%d", &N);
    static char name[1024];
    std::vector<hash_t> leaves;
    for (int i = 0; i < N; ++i) {
      fscanf(out, " %s", name);
      hash_t h = hash_string(name);
      leaves.push_back(h);
    }
    fclose(out);
    if (common_tree_exists(leaves)) {
      printf("10\nOK\n");
    } else {
      printf("0\nCommon tree does not exist\n");
    }
  }

  return 0;
}
