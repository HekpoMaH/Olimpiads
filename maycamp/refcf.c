#include<iostream>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
  long long int n,k;
  cin>>n>>k;
  long long int a[n];
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  int l=0,r=n-1;
  int br=0;
  while(l<=r)
  {
    br++;
    if(a[l]+a[r]<=k)l++;
    r--;
  }
  cout<<br<<endl;
  return 0;
}
