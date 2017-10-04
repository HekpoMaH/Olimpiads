#include<iostream>
#include<algorithm>
using namespace std;
long long s,n,a[109],b,c,k;
int main()
{
  cin>>s;
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  k=n-1;
  while(s!=0)
  {
    c=s/a[k];
    b+=c;
    s%=a[k];
    k--;
  }
  cout<<b<<endl;
  return 0;
}
