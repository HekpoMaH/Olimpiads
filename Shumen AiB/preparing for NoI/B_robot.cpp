#include<iostream>
#include<string>
using namespace std;
string s;
long long br,ans,k;
int main()
{
    cin>>k;
    cin>>s;
    for(int i=k;i<s.size();i++)
    {
        if(s[i]==s[i-k])br++;
        else br=0;
        ans+=br;
    }
    cout<<ans<<endl;
}
