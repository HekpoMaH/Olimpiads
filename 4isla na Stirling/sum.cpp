#include<bits/stdc++.h>
using namespace std;
long long dp[33][109];
int n,s;
int main()
{
    cin>>n>>s;
    if(s<0){cout<<0<<endl;return 0;}
    for(int i=0;i*i<s;i++)dp[1][i*i]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            if(dp[i-1][j]!=0)
            {
                int k=0;
                while(j+k*k<s)
                {
                    dp[i][j+k*k]+=dp[i-1][j];
                    k++;
                }
            }
        }
        for(int j=0;j<=s;j++)cout<<dp[i][j]<<" ";cout<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=s;j++)cout<<dp[i][j]<<" ";cout<<endl;
    }
    long long ans=0;
    for(int i=0;i<s;i++)ans+=dp[n][i];
    cout<<ans<<endl;
}
