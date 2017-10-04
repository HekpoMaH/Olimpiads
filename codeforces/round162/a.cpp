#include<iostream>
#include<string>
using namespace std;
string s;int ans;
int main()
{
    cin>>s;cin>>s;
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]==s[i+1])ans++;
    }
    cout<<ans<<endl;
}