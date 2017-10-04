#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
int g[10][10],used[10],n,m,a,b;
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
  used[1]=1;
  q.push(1);
  while(!q.empty())
  {
    a=q.front();q.pop();
    for(int i=1;i<=g[a][0];i++)
    {
      if(used[g[a][i]]==0)
      {
        q.push(g[a][i]);
        used[g[a][i]]=used[a]+1;
      }
    }
  }
  cout<<used[n]<<endl;
  return 0;
}
