#include<bits/stdc++.h>
using namespace std;
long long xses[2000009];
long long yses[2000009];
long long n,ans,mod=1e9+7;
void calc(long long a[])
{
    sort(a+1,a+n+1);
    long long tek=0;
    for(int i=1;i<=n;i++)
    {
        tek+=(long long)a[i]%mod;
        ans+=((long long)(a[i]*i)-(long long)tek)%mod;ans%=mod;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>xses[i]>>yses[i];
    }
    calc(xses);calc(yses);
    cout<<ans<<endl;
}
