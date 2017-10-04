#include<iostream>
using namespace std;
int n,m,r1,r2,a[105][105],used[105],br;
void dfs(int vrah)
{
  used[vrah]=1;
  for(int i=1;i<=a[vrah][0];i++)
  {
    if(used[a[vrah][i]]==0){dfs(a[vrah][i]);}
  }
}
void input()
{
  cin>>n>>m;
  br=0;
  for(int i=1;i<=n;i++){a[i][0]=0;used[i]=0;}
  for(int i=0;i<m;i++)
  {
    cin>>r1>>r2;
    a[r1][0]++;
    a[r1][a[r1][0]]=r2;
    a[r2][0]++;
    a[r2][a[r2][0]]=r1;
  }
}
int main()
{
  input();
  for(int i=1;i<=n;i++)
  {
      if(used[i]==0){dfs(i);br++;}
  }
  cout<<br<<endl;
  return 0;
}
