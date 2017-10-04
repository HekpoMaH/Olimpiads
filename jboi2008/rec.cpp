#include<bits/stdc++.h>
using namespace std;
const int nmax=1009;
int a[nmax],b[nmax];
int dp[nmax][3];
int main()
{
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    dp[1][1]=a[1];dp[1][2]=b[1];
    for(int i=2;i<=n;i++)
    {
        dp[i][1]=a[i]+max(dp[i-1][1]+abs(b[i]-b[i-1]),dp[i-1][2]+abs(b[i]-a[i-1]));
        dp[i][2]=b[i]+max(dp[i-1][1]+abs(a[i]-b[i-1]),dp[i-1][2]+abs(a[i]-a[i-1]));
    }
    cout<<max(dp[n][1],dp[n][2])<<"\n";
}
