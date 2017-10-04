#include<iostream>
using namespace std;
int n,m,a[20][20],st,end,used[20],br,path[20],br2;
void dfs(int st,int end)
{
  path[br2]=st;
  br2++;
  used[st]=1;
  if(st==end)
  {
    br++;
    for(int i=0;i<br2;i++)cout<<path[i]<<" ";
    cout<<endl;
  }
  for(int i=1;i<=n;i++)
  {
    if(used[i]==0&&a[st][i]==1)
    {
      dfs(i,end);
      used[i]=0;
      br2--;
    }
  }
}
int main()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>st>>end;
    a[st][end]=1;
    a[end][st]=1;
  }
  cin>>st>>end;
  //used[st]=1;
  //s.push(1);
  dfs(st,end);
  cout<<br<<endl;
  return 0;
}
