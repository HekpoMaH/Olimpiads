#include <cstdio>
#include <string>
#include <vector>
#include <memory.h>
#include <assert.h>

#include <set>
#include <cmath>

using namespace std;

const int MAX_N = 1000+1;
const int MAX_E = 2*MAX_N;

struct Edge {
  int from;   // vertex number
  int to;     // vertex number
  int num;    // edge number in [0, 2*E], E=N-1, multiplier '2' because of the orientation

  Edge() {}
  Edge(int _from, int _to, int _num)
    : from(_from), to(_to), num(_num) {}

  // an edge and its reverse have consecutive indexes
  // (2*k) num edge is opposite to (2*k+1) num edge
  // so XOR(^) with 1 gives the reverse edge 
  Edge rev() { return Edge(to, from, num^1); }
};

struct Tree {
  int N, E;                   // number of vertices, number of edges 
  vector<Edge> neigh[MAX_N];  // list of neighbours
  string label[MAX_N];        // names of the leaves (empty string if not a leaf)
  Edge edge[MAX_E];           // beginning vertex of the edge

  void add_edge(int from, int to) {
    edge[E] = Edge(from, to, E);
    neigh[from].push_back( edge[E] );
    E++;
  }

  // returns the index in T.neight[e.to] of the edge coming back to e.from
  int prev_index(Edge e)
  {
    assert(neigh[e.to].size() == 1 || neigh[e.to].size() == 3);

    for (int i=0; i<neigh[e.to].size(); i++) {
      Edge next_e = neigh[e.to][i];
      if (next_e.to == e.from)
        return i;
    }
   
    assert(false);
    return -1;
  }
};

// both trees not to be changed through the algorithm
Tree P, Q;

// dp[edgeP_num][edgeQ_num] -- the number of leaves in a maximal agreement tree
//   of the subtree of P with root P.edge[edgeP_num].to and not including vertex .from
//  and the subtree of Q with root Q.edge[edgeQ_num].to and not including vertex .from
int dp[MAX_E][MAX_E];

Tree read_tree()
{
  Tree T;
  int a, b;

  // edges
  T.E = 0; // important to start from an even number because of the num^1 hack
  scanf("%d", &T.N);
  for (int i=0; i<T.N-1; i++) {
    scanf("%d %d", &a, &b);
    T.add_edge(a, b);
    T.add_edge(b, a);
  }

  // leaves
  int L;
  scanf("%d", &L);
  for (int i=0; i<L; i++) {
    char label[11];
    scanf("%d %s", &a, label);
    T.label[a] = label;
  }

  return T;
}

// Matching:
// subtree of P with root ep.to not including ep.from
// subtree of Q with root eq.to not including eq.from
int solve_subtrees(Edge ep, Edge eq)
{
  int &ans = dp[ep.num][eq.num];
  if (ans != -1) return ans;

  int pb(ep.to), qb(eq.to);

  string leafP = P.label[pb];
  string leafQ = Q.label[qb];

  // if both subtrees contain just a single leaf
  if (leafP != "" && leafQ != "") {
    // these leaves are eighter the same or not the same :")
    ans = (leafP == leafQ) ? 1 : 0;
  } else {
    int psize = P.neigh[pb].size();
    int qsize = Q.neigh[qb].size();

    assert(psize == 1 || psize == 3);
    assert(qsize == 1 || qsize == 3);

    // get the indices of the returning/useless edges
    int ep_prev_ind = P.prev_index(ep);
    int eq_prev_ind = Q.prev_index(eq);

    // get the 4 subtrees
    // repetition will occur if one of the currect vertices is a leaf
    Edge next_ep[2], next_eq[2];
    for (int i=0; i<2; i++) {
      next_ep[i] = psize==1 ? ep : P.neigh[pb][ (ep_prev_ind+i+1) % psize ];
      next_eq[i] = qsize==1 ? eq : Q.neigh[qb][ (eq_prev_ind+i+1) % qsize ];
    }

    // test two ways of combining the pairs of subtrees in P and Q
    //   solve_subtrees(left of P, left of Q)  + solve_subtrees(right of P, right of Q)
    //   solve_subtrees(left of P, right of Q) + solve_subtrees(right of P, left of Q)
    // note: in fact, there is not 'left' and 'right' but 'one' and 'another'
    // if we are in a leaf in P or Q then this same leaf is passed instead of a subtree
    for (int i=0; i<2; i++)
      ans = max(ans, solve_subtrees(next_ep[0], next_eq[i])
          + solve_subtrees(next_ep[1], next_eq[(i+1)%2]));
   
    // combine the current ep tree with the subtrees of eq
    //     and the current eq tree with the subtrees of ep
    for (int i=0; i<2; i++) {
      ans = max(ans, solve_subtrees(ep, next_eq[i]));
      ans = max(ans, solve_subtrees(next_ep[i], eq));
    }
  }

  return ans;
}

int solve()
{
  int ans=0;
  //multiset<int> rootans;

  memset(dp, -1, sizeof(dp));
  
  // for every edge from P and every edge from Q
  for (int p=0; p<P.E; p++)
    for (int q=0; q<Q.E; q++) {
      // fixing a rooted subtree of P and a rooted subtree of Q
      int curr = solve_subtrees(P.edge[p], Q.edge[q])
          + solve_subtrees(P.edge[p].rev(), Q.edge[q].rev());
      ans = max(ans, curr);

      //rootans.insert(curr);
    }

  //for (int i=0; i<=ans; i++)
  //  fprintf(stderr, "Answer %d: %d times (%.5lf%%)\n", i, rootans.count(i), 100.0*rootans.count(i)/(P.E*P.E));

  //double prob = 1.0*rootans.count(ans)/(P.E*P.E);
  //fprintf(stderr, "Probability for    1 random root guess:   %.5lf\n", prob);
  //fprintf(stderr, "Probability for  100 random root guesses: %.5lf\n", 1.0-pow(1.0-prob, 100));
  
  return ans;
}

int main ()
{
  P = read_tree();
  Q = read_tree();
  printf("%d\n", solve());

  return 0;
}
