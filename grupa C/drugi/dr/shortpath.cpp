#include<iostream>
#include<queue>
using namespace std;
int a[105][105],used[105],br,m,n,r1,r2,st,end,b;
void bfs(int st,int end)
{
  queue<int> q;
  int curr;
  q.push(st);
  used[st]=1;
  while(!q.empty())
  {
    curr=q.front();
    q.pop();
    for(int i=1;i<=a[curr][0];i++)
    {
      b=a[curr][i];
      if(used[b]==0)
      {
        //cout<<curr<<" "<<used[curr]<<endl;
        used[b]=used[curr]+1;
        //cout<<b<<" "<<used[b]<<endl;
        q.push(b);
      }
    }
  }
}
void input()
{
  cin>>n>>m;
  br=0;
  for(int i=0;i<=n;i++)
  {
    used[i]=0;a[i][0]=0;
  }
  for(int i=0;i<m;i++)
  {
    cin>>r1>>r2;
    a[r1][0]++;
    a[r1][a[r1][0]]=r2;
    a[r2][0]++;
    a[r2][a[r2][0]]=r1;
  }
  cin>>st>>end;
}
int main()
{
  input();
  bfs(st,end);
  cout<<used[end]-1<<endl;
  return 0;
}
