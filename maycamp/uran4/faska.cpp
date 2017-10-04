#include<iostream>
using namespace std;
unsigned long long gl[95],sand[95],dg,tgl;
int main()
{
  cin>>dg;
  gl[0]=3;sand[0]=2;
  gl[1]=5;sand[1]=3;
  gl[2]=7;sand[2]=4;
  for(int i=3;i<dg;i++)
  {
    gl[i]=gl[i-1]+sand[i-2];
    sand[i]=gl[i]-i-1;
  }
  cout<<gl[dg-1]<<endl;
  return 0;
}
