#include<iostream>
using namespace std;
long long f[1000005],a,b=1,c,n;
int main()
{
  cin>>n;
  if(n==1)cout<<0<<endl;
  if(n==2)cout<<1<<endl;
  if(n>2)
  {
    for(int i=3;i<=n;i++)
    {
      a=((i-1)*(b+c))%9901;
      c=b;
      b=a;
    }
    cout<<a<<endl;
  }
  return 0;
}

