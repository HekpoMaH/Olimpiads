#include<iostream>
#include<string>
using namespace std;
long long w;
string s;
int main()
{
    cin>>w;
    for(int i=1;i<=w;i++)
    {
        cin>>s;
        if(s.size()<=10)cout<<s<<endl;
        if(s.size()>10)cout<<s[0]<<s.size()-2<<s[s.size()-1]<<endl;
    }
    return 0;
}