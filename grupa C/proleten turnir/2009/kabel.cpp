#include<iostream>
using namespace std;
long long a[150][150];
long long p,r,q,f,n,l,t,d;
int main()
{
  ios::sync_with_stdio(false);
  cin>>n>>l;
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=l;j++)
    {
      a[i][j]=1<<30;
    }
  }
  a[0][0]=0;
  for(int i=1;i<=n;i++)
  {
    cin>>p>>r>>q>>f;
    for(int j=1;j<=f;j++)
    for(int k=0;k+j<=l;k++)
    {
      t=a[i-1][k];
      if(j>=r)t+=j*q;
      else t+=j*p;
      if(a[i][k+j]>t)a[i][k+j]=t;
    }
    for(int j=0;j<=l;j++)if(a[i-1][j]<a[i][j])a[i][j]=a[i-1][j];
  }
  d=l;
  for(int i=l+1;i<=l;i++)if(a[n][i]<a[n][d])d=i;
  if(a[n][d]==1073741824)cout<<-1<<endl;
  else cout<<a[n][d]<<endl;
  return 0;
}
/*
2 14
7 9 6 10
7 8 6 10
*/
