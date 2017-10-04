#include<iostream>
using namespace std;
int g[5004][5004],n,m,p[100005],b=1,e,st[5004],x,y,br,pointed;
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
  p[b]=1;
  for(int i=1;i<=n;i++)
  {
    if(st[i]%2==1)
    {
      br++;
      if(br==1)p[b]=i;
    }
  }
  e=m+1;
  if(br>2){cout<<"Sorry, Pesho"<<endl;return 0;}
  while(b!=e)
  {
    if(st[p[b]]==0)
    {
      p[e]=p[b];
      e--;
      b--;
    }
    if(st[p[b]]>0)
    {
      for(int i=1;i<=n;i++)
      {
        if(g[p[b]][i]==1)
        {
          pointed=i;
          break;
        }
      }
      st[pointed]--;st[p[b]]--;
      p[b+1]=pointed;
      g[p[b]][pointed]=0;
      g[pointed][p[b]]=0;
      b++;
    }
  }
  for(int i=1;i<=m+1;i++)
  {
    cout<<p[i]<<" ";
  }
  cout<<endl;
  return 0;
}
