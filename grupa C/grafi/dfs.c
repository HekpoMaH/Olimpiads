#include<iostream>
#include<vector>
using namespace std;
vector<int>g[105];
int n,m,a,b,used[105];
void dfs(int v)
{
  cout<<v<<endl;
  used[v]=1;
  for(int i=g[v].size()-1;i>=0;i--)
  {
    if(used[g[v][i]]==0)
    {
      dfs(g[v][i]);
    }
  }
  return;
}
int main()
{
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1);
  return 0;
}
