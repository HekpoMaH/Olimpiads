#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int dp[4009];
int main()
{

    memset(dp,-1,sizeof(dp));
    //cout<<dp[0]<<endl;
    dp[0]=0;cin>>n>>a>>b>>c;
    for(int i=1;i<=n;i++)
    {
        if(dp[i-a]!=-1&&i-a>=0)dp[i]=max(dp[i],dp[i-a]+1);
        if(dp[i-b]!=-1&&i-b>=0)dp[i]=max(dp[i],dp[i-b]+1);
        if(dp[i-c]!=-1&&i-c>=0)dp[i]=max(dp[i],dp[i-c]+1);
    }
    cout<<dp[n]<<endl;
}
