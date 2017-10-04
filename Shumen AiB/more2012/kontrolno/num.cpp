#include<iostream>
#include<string>
using namespace std;
long long dp[103];
long long com[102][102];
long long used[12],br=1;
long long mod=1800000007;
string inp;
int main()
{
    cin>>inp;
    for(int i=0;i<inp.size();i++)
    {
        used[inp[i]-'0']++;
    }
    dp[0]=1;
    com[0][0]=1;
    for(int i=1;i<=100;i++)
    {
        com[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            com[i][j]=(com[i-1][j]+com[i-1][j-1])%mod;
        }
    }
    for(int cifra=1;cifra<=9;cifra++)
    {
        if(used[cifra]!=0)
        {
            for(int i=1;i<=used[i]&&i<dp[cifra-1]+1;i++)dp[i]=(dp[i]+com[used[i]][i])%mod;
            //for(int i=1;i<=used[i]-1&&i<dp[cifra-1]+1;i++)dp[i]=(dp[i]-com[used[i]][i])%mod;
        }
        else dp[cifra]=dp[cifra-1];
    }
    cout<<dp[2]<<endl;
    return 0;
}