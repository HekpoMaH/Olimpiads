#include<iostream>
using namespace std;
int t,a[55],n,s;
int main()
{
  cin>>t;
  for(int i=0;i<t;i++)
  {
    cin>>n;
    for(int j=0;j<n;j++)cin>>a[j];
    sort(a,a+n);
    s=0;
    for(int j=0;j<n-1;j++)s+=(a[n-1]-a[j]);
    cout<<s<<endl;
  }
  return 0;
}
