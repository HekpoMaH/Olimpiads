#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
  long long s,a[110],o=0;
  int n,j,i;
  cin>>s>>n;
  for(i=0;i<n;i++)
  {
    cin>>a[i];
  }
  sort(a,a+n);
  for(i=n-1;i>=0;i--)
  {
    if(s==0)break;
    o+=s/a[i];
    s=s%a[i];
  }
  cout<<o<<endl;
}