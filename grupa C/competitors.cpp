#include<iostream>
using namespace std;
int know[25],n,k;
struct par
{
  int t[25],p;
};
par u[25];
int used[25],mnu4=999,te[25],br;
int includ[25],counted[25];
void input()
{
  cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    cin>>u[i].p;
    for(int j=1;j<=u[i].p;j++)cin>>u[i].t[j];
  }
}
void solve(int u4,int includ[25],int counted[25],int used[25])
{
  int fl=1;
  for(int i=1;i<=k;i++)if(counted[i]==0){fl=0;break;}
  if(fl==1)if(u4<mnu4)
  {

    mnu4=u4;
    for(int i=1;i<=u4;i++)te[i]=includ[i];
    return;
  }
  for(int i=1;i<=n;i++)
  {
    if(used[i]==0&&u4+1<mnu4)
    {
      for(int j=1;j<=u[i].p;j++)counted[u[i].t[j]]++;
      includ[u4+1]=i;
      used[i]=1;
      solve(u4+1,includ,counted,used);
      includ[u4+1]=0;
      used[i]=0;
      for(int j=1;j<=u[i].p;j++)counted[u[i].t[j]]--;
    }
  }
}
int main()
{
  //ebahti kak ma marzi
  input();
  solve(0,includ,counted,used);
  cout<<mnu4<<endl;
  for(int i=1;i<=mnu4;i++)cout<<te[i]<<" ";
  cout<<endl;
  return 0;
}
