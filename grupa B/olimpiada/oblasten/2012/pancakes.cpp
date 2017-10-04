#include<bits/stdc++.h>
using namespace std;
long long x;
int n;
long long t[22];
bool check(long long g)
{
    long long wtf=0;
    for(int i=1;i<=n;i++)
    {
        wtf+=g/t[i];
    }
    if(wtf>=x)return true;
    return false;
}
int main()
{
    cin>>x>>n;
    for(int i=1;i<=n;i++)cin>>t[i];
    long long l=0,r=1e16;
    long long m,ans=1e16;
    while(l<=r)
    {
        m=(l+r)/2;
        //cout<<m<<" "<<check(m)<<endl;
        if(check(m)==true)ans=min(ans,m),r=m-1;
        else l=m+1;
    }
    cout<<ans<<endl;
}
