#include<iostream>
using namespace std;
long long e,f,w[504],p[504],n;
int main()
{
  cin>>e>>f;
  cin>>n;
  long long we=f-e;
  long long f[10000],mx;
  for(int i=0;i<n;i++)cin>>p[i]>>w[i];
  f[0]=0;
  for(int i=1;i<=we;i++)
  {
    mx=999999999LL;
    for(int j=0;j<n;j++)
    {
      //cout<<"i="<<i<<" f["<<i<<"-"<<w[j]<<"]="<<f[i-w[j]]<<endl;
      if(i-w[j]>=0&&f[i-w[j]]>=0)
      {

        mx=min(mx,f[i-w[j]]+p[j]);
      }
    }
    //cout<<"mx="<<mx<<endl;
    if(mx==999999999)f[i]=-1;
    else f[i]=mx;
  }
  if(f[we]==-1){cout<<"This is impossible"<<endl;return 0;}
  cout<<f[we]<<" ";
  f[0]=0;
  for(int i=1;i<=we;i++)
  {
    mx=-1;
    for(int j=0;j<n;j++)
    {
      if(i-w[j]>=0&&f[i-w[j]]>=0)
      {

        mx=max(mx,f[i-w[j]]+p[j]);
      }
    }
    f[i]=mx;
  }
  cout<<f[we]<<endl;
  return 0;
}
