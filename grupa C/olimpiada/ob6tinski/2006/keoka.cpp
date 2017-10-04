#include<iostream>
#include<string>
using namespace std;
string s;
int l1=0,l2=1,l3=1,l4=1;
int main()
{
  cin>>s;
  int r=s.size();
  int otg=0;
  s+=' ';
  for(int i=0;i<r;i++)
  {
    if(s[i]=='A'||s[i]=='O'||s[i]=='E')l1=1;
    if(s[i]==s[i+1]){l2=0;otg=i+2;cout<<otg<<endl;return 0;}
    if((s[i]=='A'||s[i]=='O'||s[i]=='E')&&(s[i+1]=='A'||s[i+1]=='O'||s[i+1]=='E')&&(s[i+2]=='A'||s[i+2]=='O'||s[i+2]=='E')){l3=0;otg=i+3;cout<<otg<<endl;return 0;}
    if(s[i]=='A'&&(s[i+1]=='A'||s[i+1]=='O'||s[i+1]=='E')){l4=0;otg=i+2;cout<<otg<<endl;return 0;}
  }
  if(l1==0)cout<<r<<endl;
  if(l1==1&&l2==1&&l3==1&&l4==1)cout<<0<<endl;
  return 0;
}
