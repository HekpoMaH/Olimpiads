#include<iostream>
#include<string>
using namespace std;
int k,k1;
string a;
int main()
{
  cin>>k;
  k1=k-1;
  while(k1/2>0)
  {
    k1%2;
    a+=(k1%2)+'0';
    k1/=2;
  }
  a+=k1+'0';
  reverse(a.begin(),a.end());
  for(int i=0;i<a.size();i++)
  {
    if(a[i]=='0')cout<<0;
    if(a[i]=='1')cout<<6;
  }
  cout<<endl;
  return 0;
}
