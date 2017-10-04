#include<iostream>
using namespace std;
int a[104][104],n,m,r1,r2,pr,nov[104],vl[104];
void solve(int vrah)
{
  pr++;
  nov[vrah]=pr;
  for(int i=1;i<=a[vrah][0];i++)
  {
    vl[a[vrah][i]]--;
    if(vl[a[vrah][i]]==0)solve(a[vrah][i]);
  }
}
void input()
{
  cin>>n>>m;
  for(int i=1;i<=n;i++){a[i][0]=0;vl[0]=0;}
  for(int i=1;i<=m;i++)
  {
    cin>>r1>>r2;
    a[r1][0]++;
    a[r1][a[r1][0]]=r2;
    vl[r2]++;
  }
}
int main()
{
  input();
  for(int i=1;i<=n;i++)if(vl[i]==0)solve(i);
  for(int i=1;i<=n;i++)cout<<i<<" "<<nov[i]<<endl;
  return 0;
}
