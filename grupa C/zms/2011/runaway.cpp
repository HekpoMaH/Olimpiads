#include<iostream>
using namespace std;
int a[1000][1000],n,k,b;
void solve()
{
  int red=0,kol=n-1,ans=0;
  while(1==1)
  {
    if(a[red][kol]==b)
    {
      ans=red+n-1-kol;
      cout<<ans<<"\n";
      return;
    }
    if(a[red][kol]>b)kol--;
    else red++;
    if(red==n||kol<0)
    {
      cout<<"No Solutoin"<<"\n";
      return;
    }
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin>>n;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>a[i][j];
    }
  }
  cin>>k;
  for(int i=0;i<k;i++)
  {
    cin>>b;
    solve();
  }
  return 0;
}
