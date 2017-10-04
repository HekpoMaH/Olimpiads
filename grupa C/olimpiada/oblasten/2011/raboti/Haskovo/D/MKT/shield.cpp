#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int n,a[220],b[220],aa,bb;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  for(int i=0;i<n;i++)
  {
    cin>>b[i];
  }
  //sort(a,a+n);
  //sort(b,b+n);
  if(b[0]>b[n-1])bb=b[0];
  else bb=b[n-1];
  if(a[0]<a[n-1])aa=a[0];
  else aa=a[n-1];
  cout<<aa+bb<<endl;
  return 0;
}