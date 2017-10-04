#include<iostream>
#include<string>
using namespace std;
string s;
int main()
{
    cin>>s;
    for(int i=1;i<s.size();i++)if(s[i]>='a'&&s[i]<='z'){cout<<s<<endl;return 0;}
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='A'&&s[i]<='Z')s[i]=tolower(s[i]);
        else s[i]=toupper(s[i]);
    }
    cout<<s<<endl;
    return 0;
}