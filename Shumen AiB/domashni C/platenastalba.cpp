#include<iostream>
using namespace std;
int n,a[103];
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=2;i<n;i++)a[i]=min(a[i-1],a[i-2])+a[i];
  cout<<a[n-1]<<endl;
  return 0;
}
