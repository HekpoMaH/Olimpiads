#include<bits/stdc++.h>
using namespace std;
int n,p[1000],s[1000],t[1000],dp[1000];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<n;i++)cin>>s[i];
    for(int i=1;i<n;i++)cin>>t[i];
    dp[1]=p[1];
    for(int i=2;i<=n;i++)
    {
        dp[i]=max(dp[i-1]+p[i],max(dp[i-2]+t[i],dp[i-2]+s[i-1]));
    }
    cout<<dp[n]<<endl;
}
/*
7
5 4 -3 2 1 4 4
7 3 4 2 -2 4
6 -1 2 -3 5 5
*/
