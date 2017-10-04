#include<iostream>
using namespace std;
int g[10][10],a,b,used[10],m,n,br;
void dfs(int vrah,int pos)
{
  used[vrah]=1;
  if(vrah==pos)br++;
  for(int i=1;i<=g[vrah][0];i++)
  {
    if(used[g[vrah][i]]==0){dfs(g[vrah][i],pos);used[g[vrah][i]]=0;}
  }
}
int main()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>a>>b;
    g[a][0]++;g[a][g[a][0]]=b;
    g[b][0]++;
    g[b][g[b][0]]=a;
  }
  dfs(1,n);
  cout<<br<<endl;
  return 0;
}
