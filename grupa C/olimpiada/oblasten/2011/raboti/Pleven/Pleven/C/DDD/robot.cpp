#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
int n,m,k,r,i,j,a[111][111],sum,x,y,b[111][111],ok,z;
queue<int> q;
void vmykni(int x1,int y1)
{
  if (x1>0 && x1<=n && y1>0 && y1<=m)
  {
    if (b[x1][y1]==0)
    {
      b[x1][y1]=b[x][y]+1;
      if (b[x1][y1]>=k+2) ok=1;
      else
      {
        sum+=a[x1][y1];
        q.push(x1);
        q.push(y1);
      }
    }
  }
}
int main()
{
  scanf ("%d%d%d%d",&n,&m,&r,&k);
  for (i=1;i<=n;i++)
  {
    for (j=1;j<=m;j++)
    {
      z++;
      a[i][j]=z;
    }
  }
  x=r/m;
  if (r%m==0) y=m;
  else {x++;y=r%m;}
  q.push(x);
  q.push(y);
  b[x][y]=1;
  while (!q.empty())
  {
    x=q.front();
    q.pop();
    y=q.front();
    q.pop();
    vmykni(x-1,y);
    vmykni(x,y+1);
    vmykni(x+1,y);
    vmykni(x,y-1);
    if (ok==1) break;
  }
  if (k%2==0) sum+=r;
  printf("%d\n",sum);
  return 0;
}
/*
3 4 6 1
*/
//24
/*
4 3 6 1
*/
//17
/*
4 3 6 2
*/
//32
