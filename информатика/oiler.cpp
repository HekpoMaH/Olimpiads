#include<iostream>
using namespace std;
long long n,m,a,r,br;
long long b,e;
long long g[105][105],st[105],p[105];
int main()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>a>>r;
    g[a][0]++;g[r][0]++;g[a][g[a][0]]=r;
    g[r][g[r][0]]=a;
    st[a]++;st[r]++;
  }
for(int i=1;i<=n;i++)
      {
        cout<<i<<"-> ";
        for(int j=1;j<=g[i][0];j++)
        {
          cout<<g[i][j]<<" ";
        }
        cout<<endl;
      }

  b=1;e=m+1;
  for(int i=1;i<=n;i++)
  {
    if(st[i]%2==1)
    {
      br++;
      if(br==1)
      {
        p[b]=i;
      }
    }
  }
  while(b!=e)
  {
    if(g[p[b]][0]==0)
    {
      p[e]=p[b];
      e--;b--;
    }
    else
    {
      p[b+1]=g[p[b]][g[p[b]][0]];
      g[p[b]][g[p[b]][0]]=0;
      g[p[b]][0]--;
      cout<<"g="<<g[b][0]<<endl;
      for(int i=1;i<=g[p[b+1]][0];i++)
      {
        if(g[p[b+1]][i]==p[b])
        {
          for(int j=i+1;j<=g[b+1][0];j++)g[p[b+1]][j-1]=g[p[b+1]][j];
          g[p[b+1]][g[p[b+1]][0]]=0;
          g[p[b+1]][0]--;
        }
      }
      for(int i=1;i<=n;i++)
      {
        cout<<i<<"-> ";
        for(int j=1;j<=g[i][0];j++)
        {
          cout<<g[i][j]<<" ";
        }
        cout<<endl;
      }
      system("pause");
      b++;
    }
  }
  if(br>2)cout<<"No way"<<endl;
  else
  {
    for(int i=1;i<=m+1;i++)
    {
      cout<<p[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
