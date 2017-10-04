#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
int n,mn=100090;
string s[100009],ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i],m[s[i]]++;
    for(int i=1;i<=n;i++)
    {
        if(m[s[i]]<mn)
        {
            mn=m[s[i]];
            ans=s[i];
        }
    }
    cout<<ans<<"\n";
}
