#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int NMAX = 1024;

struct Circle
{ int x,y;
  int r;
};

Circle C[NMAX];
vector<int> a[NMAX]; 
int d[NMAX];
int n;    

bool intersect(Circle A, Circle B)
{ int dx = B.x - A.x;
  int dy = B.y - A.y;
  int d2 = dx*dx + dy*dy;
  int p = A.r - B.r;
  int q = A.r + B.r;
  return (p*p < d2 && d2 < q*q);
}  
  
void bfs(int x)
{ for(int i=1; i<=n; i++)
    d[i] = -1;
  d[x] = 0;
  queue<int> q;
  q.push(x);
  
  while(!q.empty())
  { x = q.front(); 
    q.pop();
    
    for(int i=0; i<a[x].size(); i++)
    { int y = a[x][i];
      if(d[y]==-1)
      { d[y] = d[x] + 1;
        q.push(y);
      }
    }
  } 
}       
  
int main()
{ cin >> n;
  for(int i=1; i<=n; i++)
   cin >> C[i].x >> C[i].y >> C[i].r;
  
  for(int i=1; i<n; i++)
    for(int j=i+1; j<=n; j++)
      if(intersect(C[i],C[j]))
      { a[i].push_back(j);
        a[j].push_back(i);
      }
  
  bfs(1); 
  cout << d[n] << endl;
       
  return 0;
}    
