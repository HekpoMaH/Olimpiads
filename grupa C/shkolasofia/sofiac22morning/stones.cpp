#include<iostream>
using namespace std;
long long m,n,g[1000004],mm=3;
void solve(long long m)
{
  if(mm>=m)
  {
    //cout<<mm<<" "<<m<<" "<<g[m]<<endl;
    if(g[m]==1)cout<<1;
    if(g[m]==0)cout<<2;
    return;
  }
  if(mm<m)mm=m;
  for(int i=4;i<=m;i++)
  {
    if(i%3==0)
    {
      if(g[i-1]==0||g[i-2]==0)g[i]=1;
    }
    if(i%3==1)
    {
      if(g[i-1]==0||g[i-3]==0)g[i]=1;
    }
    if(i%3==2)
    {
      if(g[i-1]==0||g[i-2]==0||g[i-3]==0)g[i]=1;
    }
  }
  if(g[m]==1)cout<<1;
  if(g[m]==0)cout<<2;
}
int main()
{
  ios::sync_with_stdio(false);
  cin>>n;
  g[0]=1;
  g[1]=1;
  g[2]=1;
  g[3]=0;
  for(int i=0;i<n;i++)
  {
    cin>>m;
    solve(m);
  }
  cout<<endl;
  return 0;
}
