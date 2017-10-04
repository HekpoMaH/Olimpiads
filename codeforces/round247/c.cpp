#include<bits/stdc++.h>
using namespace std;
int n,k,d;
int br;
int dp[109][2];
const int mod=1e9+7;
void go()
{
    dp[0][0]=1;
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=k&&i-j>=0;j++)
        {
            if(j<d)dp[i][0]+=dp[i-j][0],dp[i][0]%=mod;
            if(j>=d)
            {
                dp[i][1]+=dp[i-j][0],dp[i][1]%=mod;
            }
            dp[i][1]+=dp[i-j][1],dp[i][1]%=mod;
        }
    }
    cout<<dp[n][1]<<"\n";
}
int main()
{
    cin>>n>>k>>d;go();
   // cout<<br<<"\n";
}
