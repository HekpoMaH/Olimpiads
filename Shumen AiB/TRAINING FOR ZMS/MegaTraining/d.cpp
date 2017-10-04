#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string s;
int dp[222][4];
void solve()
{
    cin>>s;
    memset(dp,31,sizeof(dp));
    dp[0][1]=0;dp[0][2]=1;
    for(int i=1;i<=s.size();i++)
    {
        if(s[i-1]=='L')
        {
            dp[i][2]=dp[i-1][2];
            dp[i][1]=dp[i-1][1]+1;
            dp[i][1]=min(dp[i][1],dp[i][2]+1);
            dp[i][2]=min(dp[i][2],dp[i][1]+1);
        }
        if(s[i-1]=='R')
        {
            dp[i][2]=dp[i-1][2]+1;
            dp[i][1]=dp[i-1][1];
            dp[i][2]=min(dp[i][2],dp[i][1]+1);
            dp[i][1]=min(dp[i][1],dp[i][2]+1);
        }
        if(s[i-1]=='B')
        {
            dp[i][1]=dp[i-1][1]+1;
            dp[i][2]=dp[i-1][2]+1;
            dp[i][2]=min(dp[i][2],dp[i][1]+1);
            dp[i][1]=min(dp[i][1],dp[i][2]+1);
        }
    }

    cout<<dp[s.size()][2]<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)solve();
}
