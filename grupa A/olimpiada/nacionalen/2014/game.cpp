#include<bits/stdc++.h>
using namespace std;
int dp[709][709];
int a[709];
int n;
void read()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],dp[i][i+1]=0,dp[i][i]=0;
}
void solve()
{
    for(int k=3;k<=n;k++)//length of intervals
    {
        for(int i=1;i<=n-k+1;i++)
        {
            int j=i+k-1;
            for(int kk=i+1;kk<=j-1;kk++)dp[i][j]=max(dp[i][kk]+dp[kk][j]+a[kk]*(a[i]+a[j]),dp[i][j]);
        }
    }
    cout<<dp[1][n]<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    read();
    solve();
}
