#include<iostream>
#include<cstring>
using namespace std;
int n;
long long dp[1000005];
int main()
{
    cin>>n;
    memset(dp,31,sizeof(dp));
    dp[1]=0;
    for(int i=1;i<n;i++)
    {
        dp[i+1]=min(dp[i+1],dp[i]+1);
        if(i*2<=n)dp[i*2]=min(dp[i*2],dp[i]+1);
        if(i*3<=n)dp[i*3]=min(dp[i*3],dp[i]+1);
    }
    cout<<dp[n]<<endl;
    return 0;
}