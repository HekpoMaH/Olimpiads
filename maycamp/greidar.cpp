#include<iostream>
using namespace std;
int a[100005],b[100005],dp[100005],n;
int main()
{
    cin>>n;
    for(int i=n;i>2;i--)
    {
        cin>>a[i]>>b[i];
    }
    cin>>dp[2];cin>>dp[1];
    dp[0]=0;dp[2]+=dp[1];
    for(int i=3;i<=n;i++)
    {
        dp[i]=min(dp[i-3]+b[i],dp[i-1]+a[i]);
    }
    cout<<dp[n]<<endl;
    return 0;
}