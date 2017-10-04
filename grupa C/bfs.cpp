#include<iostream>
#include<queue>
using namespace std;
int m,n,a[20][20],used[20],x,y,t;
queue<int> q;
int main()
{
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    cin>>x>>y;
    a[x][y]=1;a[y][x]=1;
  }
  q.push(1);
  used[1]=1;
  while(!q.empty())
  {
    t=q.front();
    q.pop();
    for(int i=1;i<=n;i++)
    {
      if(used[i]==0&&a[i][t]==1)
      {
        q.push(i);
        used[i]=used[t]+1;
      }
    }
  }
  cout<<used[n]-1<<endl;
  return 0;
}
