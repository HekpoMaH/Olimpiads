#include<iostream>
#include<vector>
using namespace std;
vector<int> g[100];
int used[100],a,b;
int n,m;
void dfs(int k)
{
  cout<<k<<endl;
  used[k]=1;
  for(int i=g[k].size()-1;i>=0;i--)
  {
    if(used[g[k][i]]==0)
    {
      //cout<<i<<endl;
      dfs(g[k][i]);
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
