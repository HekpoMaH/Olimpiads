#include<bits/stdc++.h>
using namespace std;
int n,k;
int dp[2009][2009];
const int mod=1e9+7;
int erato[2009];
int go(int last,int len)
{
    if(dp[last][len]!=-1)return dp[last][len];
    if(len==1)return dp[last][len]=1;
    int ans=0;
    for(int i=1;i*i<=last;i++)
    {
        if(last%i==0)
        {
            ans=(ans+go(last/i,len-1))%mod;
            if(last/i!=i)ans=(ans+go(last/(last/i),len-1))%mod;
        }
    }
    //ans=(ans+go(1,len-1))%mod;
    return dp[last][len]=ans;
}
int main()
{
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    int ans=0;
    for(int i=1;i<=n;i++)ans=(ans+go(i,k))%mod;
    cout<<ans<<endl;
}
