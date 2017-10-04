#include<bits/stdc++.h>
using namespace std;
int a[1000];
int dp[1009][10009];
int br;
int mod=1000000007;
int main()
{
    int n,c,dpo;
    cin>>n>>c;
    dp[1][0]=1;
    for(int i=2;i<=n;i++)
    {
        dpo=0;
        for(int inv=0;inv<=c;inv++)
        {
            dpo+=dp[i-1][inv];dpo%=mod;
            if(inv>=i)dpo=(dpo-dp[i-1][inv-i]+mod)%mod;
            dp[i][inv]=dpo;
        }
    }
    cout<<dp[n][c]<<endl;
}
