#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000],b[1000],dp[1000],re[1000];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<n;i++)cin>>b[i];
    //memset(dp,31,sizeof(dp));
    dp[1]=a[1];
    re[1]=1;
    dp[0]=0;
    for(int i=2;i<=n;i++)
    {
        dp[i]=max(dp[i-1]+a[i],dp[i-2]+b[i-1]);
        if(dp[i-1]+a[i]>=dp[i-2]+b[i-1])re[i]=1;
        else re[i]=2,re[i-1]=2;
        //cout<<dp[i-1]+a[i]<<" "<<dp[i-2]+b[i-1]<<" "<<re[i]<<endl;
    }
    cout<<dp[n]<<endl;
    //if(re[2]==1)cout<<1<<endl;
    for(int i=1;i<=n;i++)
    {
        if(re[i]==1)cout<<i<<endl;
        else cout<<i<<" "<<i+1<<endl,i++;
    }
}
/*
7
5 4 3 2 1 4 4
11 3 4 8 2 4
aaaaa
*/
