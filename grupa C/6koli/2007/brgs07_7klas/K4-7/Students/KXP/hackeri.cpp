#include<iostream>
#include<string.h>
using namespace std;
string s,s1;
bool pal(int l,int r)
{
int i;
for(i=l;i<=(l+r)/2;i++)if(s[i]!=s[r-i+l])return 0;
return 1;
}
int main()
{
cin>>s;
int i;
bool p=1;
int d=s.size();
if(d==1)cout<<s<<s<<endl;
else
{
for(i=1;i<d;i++)
{
if(s[i]==s[d-1] && pal(i+1,d-2))
{
p=0;
s1=s;
s.erase(i,d+1-i);
int j;
reverse(s.begin(),s.end());
string f=s1+s;
cout<<f<<endl;
break;
}
}
}
}
