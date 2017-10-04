#include<iostream>
#include<string>
using namespace std;string s;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    if(s[i]!='1'&&s[i]!='4'){cout<<"NO"<<endl;return 0;}
    cout<<"YES"<<endl;
}
