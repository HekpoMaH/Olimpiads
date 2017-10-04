#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<string>
#include<vector>
#include<set>
#include<sstream>
#include<algorithm>
using namespace std;

const int MAX_N = 10000;

// generate trees as rooted
struct Tree {
  int N, L;

  // edges
  int parent[MAX_N];
  vector<int> children[MAX_N];

  // names of the leaves (empty string if not a leaf)
  string label[MAX_N];
};

string itos(int a)
{
  stringstream out;
  out << a;
  return out.str();
}

// N -- #vertices
// L -- #leaves
// K -- max degree (# of children in a rooted tree)
Tree gen(int N, int K)
{
  // queue with vertices which haven't yet been used as children
  vector<int> V;
 
  assert(N%2 == 1);

  Tree T;
  
  V.push_back(1);
  T.parent[1] = 0;
  T.label[1] = "";

  for(int j=2; j<=N; ) {
    assert(V.size()>0);
    int r = rand() % V.size();
    int i = V[r];

    swap(V[r], V.back());
    V.pop_back();
   
    int cnt=0;
    for(; cnt<K && j<=N; cnt++, j++) {
      V.push_back(j);

      T.parent[j] = i;
      T.label[i] = "";
      T.children[i].push_back(j);
    }

    if (cnt != K) {
      fprintf(stderr, "Warning: some node degree < K\n");
    }
  }

  int L = V.size();

  for(int i=0; i<L; i++) {
    string label = string("LEAF")+itos(i+1);
    T.label[ V[i] ] = label;
  }

  T.N = N;
  T.L = L;

  return T;
}

bool is_correct(const Tree &T)
{
  int N = T.N;
  int L = T.L;
  int roots = 0;
  int root = -1;

  set<string> labels;

  for(int i=1; i<=N; i++) {
    int father = T.parent[i];
    if (father != 0) {
      const vector<int> &brothers = T.children[father];
      vector<int>::const_iterator myit = find(brothers.begin(), brothers.end(), i);  
      if (myit == brothers.end()) {
        fprintf(stderr, "Not correct: Vertex %d is not in the list of father's children (father %d).\n", i, father);
        return false;
      }
    } else {
      roots++;
      root = i;
    }

    string mylabel = T.label[i];
    if (mylabel != "")
      labels.insert(mylabel);
  }

  if (labels.size() != L) {
    fprintf(stderr, "Not correct: Not in the list of father's children.\n");
    return false;
  }

  if (roots < 1) {
    fprintf(stderr, "Not correct: The tree doesn't have a root.\n");
    return false;
  }

  if (roots > 1) {
    fprintf(stderr, "Not correct: The tree has >1 roots.\n");
    return false;
  }

  // TODO: check for cycles

  return true;
}

void tree2file(const Tree &T, FILE* f)
{
  int N = T.N;
  int L = T.L;
  int root;

  for (root=1; root<=N; root++)
    if (T.parent[root] == 0)
      break;

  assert(root <= N);
  assert(T.children[root].size() == 2);
  
  fprintf(f, "%d\n", N-1);
 
  int child1 = T.children[root][0];
  int child2 = T.children[root][1];
  fprintf(f, "%d %d\n", child1-(child1>root), child2-(child2>root));

  for(int i=1; i<=N; i++)
    if (i!=root)
      for(vector<int>::const_iterator it=T.children[i].begin(); it!=T.children[i].end(); it++) {
        int j=*it;
        fprintf(f, "%d %d\n", i-(i>root), j-(j>root));
      }
  
  fprintf(f, "%d\n", L);
  
  for(int i=1; i<=N; i++)
    if (T.label[i] != "") {
      fprintf(f, "%d %s\n", i-(i>root), T.label[i].c_str());
      L--;
    }

  assert(L==0);
}

// invariant: I am not a leaf
// swaps me with my father
// grand -> father -> me
void rotate(Tree &T, int me)
{
  assert(T.label[me]==""); // not a leaf
  int father = T.parent[me];

  assert(T.children[me].size() == 2);
  
  if (father != 0) {
    int grand = T.parent[father];
    
    // add at random one of my children to my father 
    int rand_index = rand() % 2;
    int rand_child = T.children[me][rand_index];
    T.children[father].push_back(rand_child);
    T.children[me].erase(T.children[me].begin() + rand_index);
    T.parent[rand_child] = father;
    
    // add my father as a child of me
    T.parent[father] = me;
    T.children[me].push_back(father);

    // erase myself from the list of my father's children
    vector<int> &brothers = T.children[father];
    vector<int>::iterator myit = find(brothers.begin(), brothers.end(), me);  
    assert (myit != brothers.end());
    brothers.erase(myit);

    // if I have a grandfather, replace my father with me as his child
    T.parent[me] = grand;
    if (grand != 0) {
      vector<int> &uncles = T.children[grand];
      vector<int>::iterator fatherit = find(uncles.begin(), uncles.end(), father);
      assert (fatherit != uncles.end());
      *fatherit = me;
    }
  }

  if (!is_correct(T))
    tree2file(T, stderr);

  assert(is_correct(T));
}

Tree modify(Tree T, int rotations)
{
  fprintf(stderr, "rotations: %d\n", rotations);
  for(int i=0; i<rotations; i++) {
    int v;
    while (v=rand() % T.N + 1, T.label[v]!="") ;
    rotate(T, v);
  }

  return T;
}

int main(int argn, char *args[])
{
  if (argn != 4 ) {
    printf("args: <output file> <number of vertices> <rotations>\n");
    return 1;
  }

  FILE *fout = fopen(args[1], "w");
  int N = atoi(args[2]);
  int rotations = atoi(args[3]);

  Tree T1, T2;
  T1 = gen(N, 2);
  tree2file(T1, fout);

  T2 = modify(T1, rotations);
  tree2file(T2, fout);

  fclose(fout);

  return 0;
}

