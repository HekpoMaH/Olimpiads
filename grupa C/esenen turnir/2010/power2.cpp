#include <iostream>
using namespace std;
long long st(long long a,long long n,long long m)
{
  long long f=1,c=a;
  while(n>0)
  {
    if(n%2)f=(f*c)%m;
    n=n/2;
    c=(c*c)%m;
  }
  return f%m;
}
long long x[1000002];
long long n,s=0,m;
int main()
{
  cin>>n;
  cin>>m;
  for(int i=1;i<=n;i++)cin>>x[i];
  for(int i=1;i<=n;i++)
  {
    s=(s+st(x[i],i+1,m))%m;
  }
  cout<<s<<endl;
  return 0;
}
