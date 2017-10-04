#include<iostream>
#include<string>
using namespace std;
int l,r;
string s;
int main()
{
  cin>>s;
  l=0;r=1;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='L')l++;
    if(s[i]=='R')r++;
    if(s[i]=='B'){l++;r++;}
    if(l-r==2)l--;
    if(r-l==2)r--;
  }
  cout<<r<<endl;
  return 0;
}
