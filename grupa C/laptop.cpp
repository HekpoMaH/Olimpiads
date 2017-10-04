#include<iostream>
using namespace std;
int n,m,st[5000],a[5000][5000],p[100001],x,y;
int main()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>x>>y;
    st[x]++;
    st[y]++;
    a[x][y]=1;
    a[y][x]=1;
  }
  int b=1,e=m+1,pointed,br=0;
  p[b]=1;
  for(int i=1;i<=n;i++)
  {
    if(st[i]%2==1)
    {
      br++;
      if(br==1)p[b]=i;
    }
  }
  for(int i=1;i<=n;i++)cout<<"st["<<i<<"]="<<st[i]<<" ";
  cout<<endl;
  if(br>2||br==1){cout<<"No w@Y"<<endl;return 0;}
  while(b!=e)
  {
    if(st[p[b]]==0)
    {
      p[e]=p[b];
      e--;b--;
    }
    else
    {
      for(int i=1;i<=n;i++)
      {
        if(a[p[b]][i]==1)
        {
          pointed=i;
          break;
        }
      }
      st[pointed]--;st[p[b]]--;
      a[p[b]][pointed]=0;
      a[pointed][p[b]]=0;
      p[++b]=pointed;
    }
  }
  for(int i=1;i<=m+1;i++)cout<<p[i]<<" ";
  cout<<endl;
  return 0;
}
