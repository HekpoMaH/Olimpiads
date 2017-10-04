#include<iostream>
using namespace std;
long long a[1002][1002],v[1002][1002],h[1002][1002],n,k,i0,j0,p;
long long ts,ms;
int main()
{
  cin>>n>>k;
  for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
  for(int i=0;i<n;i++)
  {
    h[i][n-1]=a[i][n-1];
    p=0;
    while(p<k){h[i][n-p-1]=a[i][n-p-1]+h[i][n-p];p++;}
    while(p<n){h[i][n-p-1]=a[i][n-p-1]+h[i][n-p]-a[i][n-p+k];p++;}
  }
  for(int i=0;i<n;i++)
  {
    v[n-1][i]=a[n-1][i];
    p=0;
    while(p<k){v[n-p-1][i]=a[n-p-1][i]+v[n-p][i];p++;}
    while(p<n){v[n-p-1][i]=a[n-p-1][i]+v[n-p][i]-a[n-p+k][i];p++;}
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      ts=h[i][j]+v[i][j]-a[i][j];
      if(ts>ms){ms=ts;i0=i;j0=j;}
    }
  }
  cout<<i0+1<<" "<<j0+1<<endl;
  return 0;
}
