#include <cstdio>
#include <algorithm>

using namespace std;

const int NMAX = 1000000+10;

struct Point
{ int x,y; } A[NMAX];

int   d[NMAX];

int n;
        
bool compXY(const Point &A, const Point &B) 
{ if(A.x<B.x) return true;
  if(A.x>B.x) return false;
  if(A.y<B.y) return true;
  return false;
}

int main()
{ scanf("%d",&n);
  for(int i=0; i<n; i++)
    scanf("%d%d", &A[i].x, &A[i].y);

  int dmax;

  sort(A,A+n,compXY);
  d[0]=1;
  for(int i=1; i<n; i++)
    if(A[i-1].x < A[i].x || A[i-1].y < A[i].y) 
    { int max = 0;
      for(int j=0; j<i; j++)
        if(A[j].y <= A[i].y && max < d[j]) 
          max = d[j];
      d[i]=max+1; 
    }    

  dmax=d[n-1];
  for(int i=n-2; i>=0; i--)
    if(dmax < d[i]) dmax = d[i];
  printf("%d\n",dmax);
   
  return 0;
}

