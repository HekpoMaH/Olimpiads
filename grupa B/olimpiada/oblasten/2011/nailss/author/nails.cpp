/**
PROGRAM NAME: nails
AUTHOR: Stoyan Kapralov
*/

#include <iostream>
using namespace std;

struct Point
{ int x, y; };

const int NMAX = 1024;

Point A[NMAX], B[NMAX];
int n;

bool adj[NMAX][NMAX];
bool visited[NMAX];

int compSize;

int direction(Point A, Point B, Point C)
{ int a1=B.x-A.x, a2=B.y-A.y;
  int b1=C.x-A.x, b2=C.y-A.y;
  int p=a1*b2, q=a2*b1;
  if(p>q) return +1;
  if(p<q) return -1;
  return 0;
}

bool onSegment(Point A,Point B,Point C)
{ return min(A.x,B.x)<=C.x && C.x<=max(A.x,B.x) &&
         min(A.y,B.y)<=C.y && C.y<=max(A.y,B.y);
}

bool intersect(Point A, Point B, Point C, Point D)
{ int d1 = direction(A,B,C);
  int d2 = direction(A,B,D);
  int d3 = direction(C,D,A);
  int d4 = direction(C,D,B);
  if (d1*d2<0 && d3*d4<0)return true;
  if (d1==0 && onSegment(A,B,C)) return true;
  if (d2==0 && onSegment(A,B,D)) return true;
  if (d3==0 && onSegment(C,D,A)) return true;
  if (d4==0 && onSegment(C,D,B)) return true;
  return false;
}

void dfs(int i)
{ compSize++;
  visited[i]=true;
  for(int j=0; j<n; j++)
    if(adj[i][j] & !visited[j]) dfs(j);
}

int main()
{ n = 0;
  cin >> A[n].x >> A[n].y >> B[n].x >> B[n].y;
  while(cin.good())
  { n++;
    cin >> A[n].x >> A[n].y >> B[n].x >> B[n].y;
  }

  for(int i=0; i<n; i++)
    for(int j=i+1; j<n; j++)
	  adj[i][j] = adj[j][i] = intersect(A[i],B[i],A[j],B[j]);

  compSize=0;
  dfs(n-1);

  cout << n-compSize << endl;

  return 0;
}

