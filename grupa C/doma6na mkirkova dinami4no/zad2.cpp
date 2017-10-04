#include<iostream>
using namespace std;
int n,f1=1,f2=1,f3;
int main()
{
  cin>>n;
  if(n==1||n==2){cout<<1<<endl;return 0;}
  for(int i=2;i<n;i++)
  {
    f3=f1+f2;
    f1=f2;
    f2=f3;
  }
  cout<<f3<<endl;
  return 0;
}
