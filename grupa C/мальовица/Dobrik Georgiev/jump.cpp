#include<iostream>
using namespace std;
long long a[100009],r[100009];
long long n,k;
int ppg(int z)
{
  for(long long i=0;i<100009;i++)r[i]=0;
  r[1]=a[1];
  int mx=-9999999;
  for(long long i=2;i<=100009;i++)
  {
    mx=-9999999;
    for(int p=1;p<=z;p++)if(i-p>=1)if(mx<r[i-p])mx=r[i-p];
    r[i]=mx+a[i];
  }
  mx=-9999999;
  int n1;
  for(int i=z;i>=1;i--)
  {if(mx<r[n-i+1]){mx=r[n-i+1];n1=n-i+1;}}
  return mx;
}
int main()
{
  cin>>n>>k;
  for(long long i=1;i<=n;i++)cin>>a[i];
  long long mx2=-9999999;
  long long p2;
  int v;
  for(long long i=1;i<=k;i++)
  {
    v=ppg(i);
    if(mx2<v){mx2=v;p2=i;}
  }
  cout<<mx2<<" "<<p2<<endl;
  return 0;
}
