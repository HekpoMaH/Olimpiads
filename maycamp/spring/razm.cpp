#include<iostream>
using namespace std;
int main()
{
  unsigned long long int n,sum=1,a1=0,a2=1,a3=0;
  cin>>n;
  if(n==1){cout<<0<<endl;return 0;}
  if(n==2){cout<<1<<endl;return 0;}
  for(long long int i=3;i<=n;i++)
  {
    a3=((i-1)*(a2+a1))%9901;
    a1=a2;
    a2=a3;
    cout<<a1<<" "<<a2<<" "<<a3<<endl;
  }
  cout<<a3<<endl;
  return 0;
}
