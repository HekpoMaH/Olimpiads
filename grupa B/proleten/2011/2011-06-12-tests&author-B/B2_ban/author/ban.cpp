#include<cstdio>
#include<cstring>
using namespace std;

const int N=2000;
short int a[N+1][N+1];
short int b[N+1][N+1];
int n,m;

int input()
{
  scanf("%d%d", &n, &m);
  for(int i=1;i<=m;i++)
   { int v,w; scanf("%d%d", &v, &w);
     a[v][w]=a[w][v]=1;
   }
}

int v[N];
bool flag;
int s;
void dfs(int j)
{
  if(j==s) {flag=true;return;}
  v[j]=1;
  for(int i=1;i<=n;i++)
   if(!v[i])
    if(a[j][i]==1) 
     {b[j][i]=b[i][j]=1; 
      dfs(i); 
      if(flag) return; else b[j][i]=b[i][j]=0;
     }
}

int counter=0;
void dodfs()
{
  for(int i=1;i<=N;i++)
  for(int j=i+1;j<=N;j++)
  if(a[i][j]==1)
  if(b[i][j]==0)
  {
    flag=false;
    a[i][j]=a[j][i]=0;
    memset(v,0,sizeof(int)*N);
    s=j;
    dfs(i);
    if(!flag) counter++;
    else b[i][j]=1;
    a[i][j]=a[j][i]=1;
   }
}

int main()
{
 input();
 dodfs();
 printf("%d\n",counter);
}
