#include<iostream>
#include<cstring>
using namespace std;
struct rsd
{
    int a,b,c;
};
rsd cl[5005];
int n;
int dp[5005];
int main()
{
    cin>>n;
    memset(dp,31,sizeof(dp));
    for(int i=1;i<=n;i++)cin>>cl[i].a>>cl[i].b>>cl[i].c;
    dp[n]=cl[n].a;
    dp[n+1]=dp[n+2]=0;
    for(int i=n-1;i>=1;i--)
    {
        dp[i]=min(dp[i],dp[i+1]+cl[i].a);
        dp[i]=min(dp[i],dp[i+2]+cl[i].b);
        dp[i]=min(dp[i],dp[i+3]+cl[i].c);
    }
    //for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
    //cout<<endl;
    cout<<dp[1]<<endl;
    return 0;
}