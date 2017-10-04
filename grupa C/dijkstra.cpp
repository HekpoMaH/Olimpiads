#include<iostream>
using namespace std;
int g[100][100],n,m,v[100],i0,j0,used[100],pred[100],x,y,mn;
int main()
{
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=n;j++)
    {
      g[i][j]=999;
    }
  }
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    cin>>x>>y;
    g[x][y]=1;g[y][x]=1;
  }
  used[1]=1;
  pred[1]=-1;
  do
  {
    mn=999;
    for(int i=1;i<=n;i++)
    {
      if(used[i]==0)
      for(int j=1;j<=n;j++)
      {
        if(used[i]==1&&v[j]+g[i][j]<mn)
        {
          mn=v[j]+g[i][j];i0=i;j0=j;
        }
      }
    }
    if(mn<99)
    {
      used[i0]=1;
      v[i0]=mn;
      pred[i0]=j0;
    }
  }while(mn<99);
  int k;
  for(int i=2;i<=n;i++)
  {
    cout<<"mn pat m/u 1 & "<<i<<" e-"<<v[i]<<endl;
    cout<<"pytqt e"<<endl;
    k=i;
    while(k!=-1)
    {
      cout<<k<<" ";
      k=pred[k];
    }
    cout<<endl;
  }
  return 0;
}
