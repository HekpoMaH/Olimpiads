#include<iostream>
using namespace std;
long n,m,a[2000][2000],mn=60000,e,w,b[20000][2];
int main()
{
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    cin>>e>>w;
    b[i][0]=e;b[i][1]=w;
    a[e][w]=1;
    a[w][e]=1;
  }
  int u,v;
  for(int i=0;i<m;i++)
  {
    u=b[i][0];v=b[i][1];
    for(int j=0;j<n;j++)
    {
      if(a[u][j]==1&&a[v][j]==1)
      {
        if(u+v+j<mn)mn=u+v+j;
      }
    }
  }
  if(mn==60000)cout<<0<<endl;
  else cout<<mn<<endl;
  return 0;
}
