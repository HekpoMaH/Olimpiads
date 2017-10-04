#include<iostream>
#include<string>
using namespace std;
int n,p;
string a;
int main()
{
  cin>>n>>p;
  int ost;
  while(n>1)
  {
    ost=n%p;
    a+=ost+'0';
    n/=p;
  }
  a+=n+'0';
  reverse(a.begin(),a.end());
  while(a[0]=='0')a.erase(0,1);
  cout<<a<<endl;
  return 0;
}
