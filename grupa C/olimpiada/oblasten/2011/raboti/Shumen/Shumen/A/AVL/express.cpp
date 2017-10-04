#include<iostream>
#include<string>
using namespace std;
int main()
{int n,i,j,o;string s;cin>>s;n=s.size();o=int(s[0])-48;
for(i=1;i<n;i++)if(s[i]=='+')o+=int(s[i+1])-48;else
if(s[i]=='-')o-=int(s[i+1])-48;else o*=int(s[i+1])-48;
cout<<o<<endl;
system("express.exe");}
