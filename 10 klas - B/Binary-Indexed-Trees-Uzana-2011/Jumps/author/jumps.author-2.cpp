#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int NMAX = 1000000+10;

struct Point
{ int x,y; } A[NMAX];

int   d[NMAX];

int n,m;
        
bool compXY(Point A, const Point B) 
{ if(A.x<B.x) return true;
  if(A.x>B.x) return false;
  if(A.y<B.y) return true;
  return false;
}

bool compYX(Point A, Point B) 
{ if(A.y<B.y) return true;
  if(A.y>B.y) return false;
  if(A.x<B.x) return true;
  return false;
}

int getMax(int y)
{ int res = d[y];
  y = y & (y-1);
  while(y>0)
  { if(res<d[y]) res = d[y];
    y = y & (y-1);
  }
  return res;
}

void update(int y, int d1)
{ while(y<=m && d[y]<d1)
  { d[y] = d1;
    y = y + (y & (-y));
  }
}  
   
int main()
{ scanf("%d",&n);
  for(int i=0; i<n; i++)
    scanf("%d%d", &A[i].x, &A[i].y);

  int dmax;
   
  sort(A,A+n,compYX);  
  m=1;
  int p=A[0].y;
  for(int i=0; i<n; i++)
  { if(A[i].y > p) 
    { p=A[i].y; m++; }
    A[i].y = m;
  }
    
  sort(A,A+n,compXY);
  for(int i=1; i<=m; i++) d[i]=0;

  update(A[0].y,1);
  for(int i=1; i<n; i++)
    if(A[i-1].x < A[i].x || A[i-1].y < A[i].y) 
      update(A[i].y,1+getMax(A[i].y));
   
  printf("%d\n",getMax(m));

  return 0;
}

