#include<iostream>
using namespace std;
int lab[100][100],path[100][100],used[100][100],n;
void solve(int ci,int cj,int used[100][100],int path[100][100])
{
  used[ci][cj]=1;
  path[ci][cj]=1;
  if(ci==n&&cj==n)
  {
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        cout<<path[i][j];
      }
      cout<<endl;
    }
  }
  if(ci<n&&lab[ci+1][cj]==0&&used[ci+1][cj]==0)
  {
    solve(ci+1,cj,used,path);
    path[ci+1][cj]=0;
  }
  if(cj<n&&lab[ci][cj+1]==0&&used[ci][cj+1]==0)
  {
    solve(ci,cj+1,used,path);
    path[ci][cj+1]=0;
  }
  if(ci>1&&lab[ci-1][cj]==0&&used[ci-1][cj]==0)
  {
    solve(ci-1,cj,used,path);
    path[ci-1][cj]=0;
  }
  if(cj>1&&lab[ci][cj-1]==0&&used[ci][cj-1]==0)
  {
    solve(ci,cj-1,used,path);
    path[ci][cj-1]=0;
  }
}
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cin>>lab[i][j];
    }
  }
  solve(1,1,used,path);

  return 0;
}
