#include<bits/stdc++.h>
using namespace std;
int n,a,b;
unsigned long long dp[22][16][16];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>a>>b;
    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<=b;j++)
        {
            dp[n+1][i][j]=1;
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int k=0;k<=a;k++)
        {
            for(int k1=0;k1<=b;k1++)
            {
                for(int j=0;j<=k;j++)
                {
                    for(int j1=0;j1<=k1;j1++)
                    {
                        dp[i][k][k1]+=dp[i+1][j][j1];
                    }
                }
            }
        }
    }
    cout<<dp[1][a][b]<<endl;
}
