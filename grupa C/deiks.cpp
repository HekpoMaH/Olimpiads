#include<iostream>
using namespace std;
int g[10][10],used[10],v[10],pred[10],n,m,a,b,mn,i0,j0;
int main()
{
  cin>>n>>m;
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=n;j++)
    {
      g[i][j]=999;

    }
  }
  for(int i=1;i<=m;i++)
  {
    cin>>a>>b;
    g[a][b]=1;
    g[b][a]=1;
  }
  used[1]=1;
  pred[1]=-1;
  do
  {
    mn=99;
    for(int i=1;i<=n;i++)
    {
      if(used[i]==0)
      {
        for(int j=1;j<=n;j++)
        {
          if(used[j]==1)
          {
            if(v[j]+g[i][j]<mn)
            {
              mn=v[j]+g[i][j];i0=i;j0=j;
            }
          }
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
