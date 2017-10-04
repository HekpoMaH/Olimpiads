#include<iostream>
//#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long a[100000],n,mn=9999999999LL;
int main()
{
  ios::sync_with_stdio(false);
  cin>>n;
  //cout<<mn<<endl;
  for(long long i=0;i<n;i++)cin>>a[i];
  //cout<<a[3]<<endl;
  sort(a,a+n);
  //cout<<a[3]<<endl;
  for(long long i=0;i<n-1;i++)
  {
    for(long long j=i;j<n;j++)
    {
      if(abs(a[i]+a[j])<mn)
      {
        mn=abs(a[i]+a[j]);
        //cout<<mn<<" "<<abs(a[i]+a[j])<<endl;
      }
      //cout<<mn<<endl;br++;
    }
  }
  cout<<mn<<endl;
  return 0;
}
