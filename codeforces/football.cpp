#include<iostream>
#include<string>
using namespace std;
string s;
int l;
int main()
{
    cin>>s;
    if(s.size()>=7)for(int i=0;i<=s.size()-7;i++)
    {
        l=0;
        for(int j=i;j<i+7;j++)if(s[j]=='1')l=1;
        if(l==0){cout<<"YES"<<endl;return 0;}
        l=0;
        for(int j=i;j<i+7;j++)if(s[j]=='0')l=1;
        if(l==0){cout<<"YES"<<endl;return 0;}
    }
    cout<<"NO"<<endl;
    return 0;
}