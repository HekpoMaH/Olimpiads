#include<iostream>
#include<algorithm>
using namespace std;
long long g[1004][1004];
long long n,m;
bool used[1009];
long long v[1009];
long long pred[1009];
long long mn,i0,j0,a,b,k;
int main()
{
  cin>>n>>m;
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=n;j++)
    {
      g[i][j]=9999999999999LL;

    }
  }
  for(int i=0;i<m;i++)
  {
    cin>>a>>b>>k;
    g[a][b]=k;
    g[b][a]=k;
  }
  used[1]=1;
  pred[1]=-1;
  do
  {
    mn=999999999;
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
    if(mn<999999999)
    {
      used[i0]=1;
      v[i0]=mn;
      pred[i0]=j0;
    }

  }while(mn<999999999);
  int f,izh[100004],br=0;
  f=n;
  for(int i=2;i<=n;i++)
  {
      cout<<v[i]<<endl;
      f=i;
      while(f!=-1)
      {
        cout<<f<<" ";
        f=pred[f];
      }
      cout<<endl;
  }
  return 0;
}
