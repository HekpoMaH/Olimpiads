#include<bits/stdc++.h>
using namespace std;
string s;
int ans;
int br;
int main()
{
    cin>>s;
    br=1;
    for(int i=1;i<s.size();i++)
    {
        //cout<<br<<" "<<i<<endl;
        if(s[i]==s[i-1]) br++;
        if(s[i]!=s[i-1]||i==s.size()-1)
        {
            if(br%2==0)ans++;
            br=1;
        }
        //else br++;
    }
    cout<<ans<<endl;
}
