#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
int n,m,g[20][20],used[20];
int a,b;
int main()
{
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    cin>>a>>b;
    g[a][b]=1;
    g[b][a]=1;
  }
  q.push(1);
  used[1]=1;
  while(!q.empty())
  {
    a=q.front();
    cout<<a<<endl;
    q.pop();
    for(int i=1;i<=n;i++)
    {
      b=i;
      if(used[b]==0&&g[a][b]==1)
      {
        used[b]=used[a]+1;
        q.push(b);
      }
    }
  }
  return 0;
}
