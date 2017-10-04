#include<iostream>
using namespace std;
int a[105][105],n,m,vl[105],v1,v2,pr,nov[105];
void input()
{
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    cin>>v1>>v2;
    a[v1][0]++;
    a[v1][a[v1][0]]=v2;
    vl[v2]++;
  }
}
void solve(int vrah)
{
  pr++;
  nov[vrah]=pr;//cout<<pr<<endl;
  for(int i=1;i<=a[vrah][0];i++)
  {
    vl[a[vrah][i]]--;
    if(vl[a[vrah][i]]==0)solve(a[vrah][i]);
  }
}
int main()
{
  input();
  for(int i=1;i<=n;i++)if(vl[i]==0)solve(i);
  for(int i=1;i<=n;i++)cout<<i<<" "<<nov[i]<<endl;
  return 0;
}
