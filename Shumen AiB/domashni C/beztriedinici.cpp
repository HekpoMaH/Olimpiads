#include<iostream>
using namespace std;
int n,f1=2,f2=4,f3=7,f4;
int main()
{
  cin>>n;
  if(n==1){cout<<2<<endl;return 0;}
  if(n==2){cout<<4<<endl;return 0;}
  if(n==3){cout<<7<<endl;return 0;}
  for(int i=3;i<n;i++)
  {
    f4=f1+f2+f3;
    f1=f2;
    f2=f3;
    f3=f4;
  }
  cout<<f4<<endl;
  return 0;
}
