#include <cstdio>
#include <queue>
using namespace std;

int a[1000000];
int d[1000000]; 
int n;

queue<int> q;


int getRow(int z)
{ return 1+(z-1)/n; }

int main()
{ int x,y,b;
  scanf("%d%d%d",&n,&x,&y);

  scanf("%d",&b);  
  for(int i=1; i<=b; i++)
  { int z; 
    scanf("%d",&z);
    a[z] = 1;
  }  
  
  for(int i=1; i<=n*n; i++)
    d[i] = -1;
    
  d[x] = 0;
  q.push(x);
  
  while(!q.empty())
  { int z = q.front();
    q.pop();

    int p;
    p = z-1; 
    while(getRow(p)==getRow(z) && a[p]==0)
    { if(d[p]==-1) { d[p]=d[z]+1; q.push(p); }
      p--;
    }  
    
    p = z+1; 
    while(getRow(p)==getRow(z) && a[p]==0)
    { if(d[p]==-1) { d[p]=d[z]+1; q.push(p); }
      p++;
    }  
      
    p = z-n; 
    while(p>=0 && a[p]==0)
    { if(d[p]==-1) { d[p]=d[z]+1; q.push(p); }
      p = p-n;
    }  

    p = z+n; 
    while(p<=n*n && a[p]==0)
    { if(d[p]==-1) { d[p]=d[z]+1; q.push(p); }
      p = p+n;
    }  
  }
  
  printf("%d\n",d[y]);
  
  return 0;   
}
  
