#include<iostream>
using namespace std;
int g[10][10],vl[10],m,n,a,b,nov[10],pr;
void solve(int vrah)
{
  pr++;
  if(nov[vrah]==0)nov[vrah]=pr;
  for(int i=1;i<=g[vrah][0];i++)
  {
    vl[g[vrah][i]]--;
    if(vl[i]==0)solve(g[vrah][i]);
  }
}
int main()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>a>>b;
    g[a][0]++;
    g[a][g[a][0]]=b;
    vl[b]++;
  }
  for(int i=1;i<=n;i++)if(vl[i]==0)solve(i);
  for(int i=1;i<=n;i++)cout<<i<<" "<<nov[i]<<endl;
  return 0;
}
