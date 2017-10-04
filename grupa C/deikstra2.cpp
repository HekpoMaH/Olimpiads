#include<iostream>
using namespace std;
int n,m,g[20][20];
int mn,v[20],pred[20],c,i0,j0,used[20];
int a,b;
int main()
{
  cin>>n>>m;
  for(int i=0;i<=20;i++)
  {
    for(int j=0;j<=20;j++)
    {
      g[i][j]=999;
    }
  }
  for(int i=0;i<=20;i++)
  {
    v[i]=0;
  }
  for(int i=0;i<m;i++)
  {
    cin>>a>>b>>c;
    g[a][b]=c;
    cout<<g[a][b]<<endl;
    g[b][a]=c;cout<<g[a][b]<<endl;
  }
  /*for(int i=0;i<=20;i++)
  {
    for(int j=0;j<=20;j++)
    {
      cout<<g[i][j]<<endl;
    }
  }*/
  pred[1]=-1;
  //v[1]=0;
  used[1]=1;
  do
  {
    mn=999;
    for(int i=1;i<=n;i++)
    {
      if(used[i]==0)
      {
        for(int j=1;j<=n;j++)
        {
          if(used[j]==1)
          {cout<<used[j]<<"=used["<<j<<"]"<<endl<<v[j]+g[i][j]<<"=mn"<<endl;
            if(v[j]+g[i][j]<mn){mn=g[i][j]+v[j];i0=i;j0=j;}
          }
        }
      }
    }
    if(mn<999)
    {
      used[i0]=1;
      pred[i0]=j0;
      v[i0]=mn;
    }
  }while(mn!=999);
  cout<<v[3]<<endl;
  for(int i=2;i<=n;i++)
  {
    cout<<i<<"->"<<v[i]<<endl;
  }
  return 0;
}
