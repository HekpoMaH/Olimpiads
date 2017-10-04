#include<iostream>
using namespace std;
struct coins
{
  int w,p;
};
int n,e,f,t,mn=500000001;
coins coin[505];
void solve(int cw,int cp)
{
  //cout<<cw<<" "<<cp<<endl;
  if(cw==t)
  {
    if(cp<mn)mn=cp;
  }
  else
  {
    for(int i=1;i<=n;i++)
    {
      if(cp+coin[i].p<mn)
      {
        //cout<<coin[i].p<<" "<<coin[i].w<<" "<<cw<<endl;
        if(cw+coin[i].w<=t)
        {

          solve(cw+coin[i].w,cp+coin[i].p);
        }
      }
      else break;
    }
  }
}
bool cmp(coins a,coins b)
{
  if(a.w<b.w)return true;
  return false;
}
int main()
{
  cin>>e>>f;
  cin>>n;
  t=f-e;
  for(int i=1;i<=n;i++)
  {
    cin>>coin[i].p;
    cin>>coin[i].w;
  }
  sort(coin+1,coin+n+1,cmp);
  solve(0,0);
  cout<<mn<<endl;
  return 0;
}
