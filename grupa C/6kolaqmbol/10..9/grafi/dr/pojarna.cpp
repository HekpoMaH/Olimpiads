#include<iostream>
using namespace std;
struct mn
{
  int vr,x[100],d;
};
mn g[100];
long long m,n,mat[100][100],g1,g2,used[100],zadob[100],br,br2;
void dfs(int nvr)
{
  used[nvr]=1;
  for(int i=1;i<=n;i++)
  {
    if(used[nvr]==0&&mat[nvr][i]==1)
    {
      zadob[br]=i;
      br++;
      dfs(i);
    }
  }cout<<"br="<<br<<endl;
}
int main()
{
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    cin>>g1>>g2;
    mat[g1][g2]=1;
  }
  for(int i=1;i<=n;i++)
  {
    if(used[i]==0)
    {

    }
  }
  for(int i=0;i<br2;i++)
  {
    for(int j=1;j<g[i].d;j++)
    {
      cout<<g[i].x[j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
