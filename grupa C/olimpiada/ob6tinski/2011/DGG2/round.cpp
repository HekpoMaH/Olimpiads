#include<iostream>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
long long k,k1;
string ch;
//hahahaha
int main()
{
  cin>>k;k1=k-1;
  while(k1/2>0)
  {
    ch+=(k1%2)+'0';k1/=2;
  }
  ch+=k1+'0';
  reverse(ch.begin(),ch.end());
  for(int i=0;i<ch.size();i++)
  {
    if(ch[i]=='0')cout<<0;
    else cout<<6;
  }
  cout<<endl;
  //cout<<ch<<endl;
  return 0;
}
