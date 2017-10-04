#include<iostream>
#include<string>
using namespace std;
string s;
//long long ans=99999999999999999;
int a[3];
void read()
{
     cin>>s;
}
void solve()
{
     int sz=s.size();
     long long sum=0;
     sum+=s[0]-'0';
     for(int i=1;i<sz-1;i+=2)
     {
     if(s[i]=='+')sum+=(s[i+1]-'0');
     else
     if(s[i]=='-')sum-=(s[i+1]-'0');
     else
     if(s[i]=='*')sum*=(s[i+1]-'0');
     }
     cout<<sum<<endl;
}
int main()
{
    read();
    solve();
    return 0;
}
