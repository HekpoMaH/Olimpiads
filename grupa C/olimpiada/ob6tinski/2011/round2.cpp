#include<iostream>
#include<string>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
long long k,k1;
string s;
int main()
{
  cin>>k;k1=k-1;
  while(k1/2>0)
  {
    s+=(k1%2)+'0';k1/=2;
  }
  s+=k1+'0';
  reverse(s.begin(),s.end());
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='0')cout<<0;
    else cout<<6;
  }
  cout<<endl;
  return 0;
}
