/**
PROGRAM NAME: nails-evg
AUTHOR: Evgenii Vassilev
*/
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAXSEGS 1001
#define OS(a,b,c) (a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))
#define IS(d,e,f,g) (max(max(d,e),max(f,g))-min(min(d,e),min(f,g)) <= max(d,e)-min(d,e)+max(f,g)-min(f,g))
using namespace std;

typedef vector<int> Tvint;
struct TPoint {int x,y;};

struct TSegment{
  TPoint a,b;
  bool have_common_point_with(const TSegment& s);
  Tvint neighbours;
} A[MAXSEGS];

int n, visited[MAXSEGS];

void read_data() {
  for ( ; scanf("%i %i %i %i", &A[n].a.x, &A[n].a.y, &A[n].b.x, &A[n].b.y)==4; n++ )
    for (int i=0; i<n; i++) if (A[n].have_common_point_with(A[i])) {
      A[n].neighbours.push_back(i);
      A[i].neighbours.push_back(n);
    }
}

int BFS(const int s){
  Tvint q;
  q.reserve(n);
  q.push_back(s);
  visited[s]=1;
  int i,j,k;
  for (i=0; i<q.size(); i++) for (j=0; j<A[q[i]].neighbours.size(); j++)
    if (visited[k=A[q[i]].neighbours[j]]==0){
      visited[k]=1;
      q.push_back(k);
    }
  return q.size();
}

int main(){
  read_data();
  printf("%i\n",n-BFS(n-1));
  return 0;
}

bool TSegment::have_common_point_with(const TSegment& s){
  long long s1 = OS(a,b,s.a), s2 = OS(a,b,s.b), s3 = OS(s.a,s.b, a), s4 = OS(s.a,s.b,b);
  if (s1*s2>0 || s3*s4>0) return false;
  else {
    if (s1==0 && s2==0) {
      if (a.x==b.x) return IS(a.y,b.y,s.a.y,s.b.y);
      else return IS(a.x,b.x,s.a.x,s.b.x);
    }
    return true;
  }
}
