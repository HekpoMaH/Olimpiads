#include<iostream>
#include<string>
using namespace std;
string s1,s2;
int br=0;
int main()
{
    cin>>s1>>s2;if(s1==s2){cout<<"YES"<<endl;return 0;}
    if(s1.size()!=s2.size()){cout<<"NO"<<endl;return 0;}
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]=='1')br++;
    }
    if(br==0){cout<<"NO"<<endl;return 0;}
    br=0;
    for(int i=0;i<s2.size();i++)
    {
        if(s2[i]=='1')br++;
    }
    if(br==0){cout<<"NO"<<endl;return 0;}
    cout<<"YES"<<endl;//hell'yea'
}
