#include<iostream>
using namespace std;
int st[5004],g[5004][5004],p[100002],n,m,x,y,br;
int main()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>x>>y;
    g[x][y]=1;
    g[y][x]=1;
    st[x]++;st[y]++;
  }
  int b=1,e=m+1,pointed;
  p[b]=1;
  for(int i=1;i<=n;i++)
  {
    if(st[i]%2==1)
    {
      br++;
      if(br==1)p[b]=i;
    }
  }
  for(int i=1;i<=n;i++)
  {
    cout<<"st["<<i<<"]="<<st[i]<<" ";
  }
  cout<<endl;
  while(b!=e)
  {
    if(st[b]==0)
    {
      p[e]=p[b];
      e--;
      b--;
    }
    if(st[b]>0)
    {
      for(int i=1;i<=n;i++)
      {
        if(g[p[b]][i]==1)
        {
          pointed=i;

          break;
        }
      }
      cout<<p[b]<<" "<<pointed<<endl;
      st[pointed]--;st[p[b]]--;
      p[b+1]=pointed;
      g[p[b]][pointed]=0;
      g[pointed][p[b]]=0;
      b++;
    }
    for(int i=1;i<=n;i++)
    {
      cout<<"st["<<i<<"]="<<st[i]<<" ";
    }
    cout<<endl;
    cout<<"b="<<b<<endl;
    /*for(int i=1;i<=m+1;i++)
    {
      cout<<"p["<<i<<"]="<<p[i]<<" ";
    }
    cout<<endl;*/
  }
  for(int i=1;i<=m+1;i++)
  {
    cout<<p[i]<<" ";
  }
  cout<<endl;
  return 0;
}
