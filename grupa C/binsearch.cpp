#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
long long  a[10000],n,k;
int main()
{
  cin>>n;
  for(long long i=0;i<n;i++)cin>>a[i];
  cin>>k;
  sort(a,a+n);
  long long l,r,m,l1=0;
  l=0;
  r=n-1;
  while(l<=r)
  {
    m=(l+r)/2;
    if(k<a[m])r=m-1;
    if(k>a[m])l=m+1;
    if(k==a[m]){cout<<"yes"<<endl;l1=1;break;}
  }
  if(l1==0)cout<<"no"<<endl;
  return 0;
}
