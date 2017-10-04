#include<bits/stdc++.h>
using namespace std;
const int mod=1800000007;
unsigned long long used[12];
unsigned long long c[209][209];
unsigned long long dp[209][209],sz;
string A;
unsigned long long calc(int need,int pos)
{
    if(need!=0&&pos==10)return 0;
    if(dp[need][pos]!=-1)return dp[need][pos];
    if(need==0)return 1;
    dp[need][pos]=0;
    int out=0;
    //cout<<pos<<" "<<used[pos]<<endl;
    for(int i=1;i<=need&&i<=used[pos];i++)
    {
        if(pos==0&&i<need)
        {
            out=-1;
        }
        else if(pos!=0)out=0;
        dp[need][pos]=(dp[need][pos]+c[(need-out)][i]*calc(need-i,pos+1)%mod)%mod;

    }
    dp[need][pos]=(dp[need][pos]+calc(need,pos+1));
    return dp[need][pos];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>A;sz=A.size();
    for(int i=0;i<sz;i++)used[A[i]-'0']++;
    c[0][0]=1;
    for(int i=1;i<=120;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    }
    unsigned long long ans=0;
    if(used[0])ans++;
    //cout<<sz<<endl;
    for(int i=1;i<=sz;i++)ans=(ans+calc(i,0))%mod;
    ans%=mod;
    cout<<ans<<"\n";
}
