#include<bits/stdc++.h>
using namespace std;
int n;
int dp[100],f[100];
int main()
{
    cin>>n;
    //memset(mem,-1,sizeof(mem));
    dp[1]=1;dp[2]=2;f[1]=1;f[2]=1;
    //cout<<1<<" ";
    for(int i=3;i<=n;i++)
    {
        f[i]=f[i-1]+f[i-2];
        //cout<<dp[i-1]<<" "<<dp[i-2]<<" "<<f[i-2]<<endl;
        dp[i]=dp[i-1]+dp[i-2];
        if(i>=2)dp[i]+=f[i-2];
    }
    cout<<dp[n]<<endl;
}
