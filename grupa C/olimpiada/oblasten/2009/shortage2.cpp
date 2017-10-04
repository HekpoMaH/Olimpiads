#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string s1,s2;
int br,sz;
int main()
{
  ios::sync_with_stdio(false);
  cin>>s1;
  sz=s1.size();
  if(sz==1){cout<<0<<endl;return 0;}
  for(int i=0;i<sz;i++)s2+=s1[sz-i-1];
  //cout<<s2<<endl;
  for(int i=0;i<sz;i++)
  {
    //cout<<"1c="<<s.substr(i,(sz-i)/2)<<" "<<"2c="<<s2.substr(0,(sz-i)/2)<<endl<<s[i]<<" "<<s[sz-i]<<endl<<endl;
    if(s1[i]==s1[sz-1]&&s1.substr(i,(sz-i)/2)==s2.substr(0,(sz-i)/2)){cout<<i<<endl;return 0;}
  }
  return 0;
}
