#include<bits/stdc++.h>
using namespace std;
int n;
int k;
vector<long long> dp[10000*100+19];
int a[109],b[109],br;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)cin>>b[i];
    //memset(dp,-1,sizeof(dp));
    dp[0].push_back(0);
    for(int i=1;i<=n;i++)
    {
        for(int j=10000*100;j>=0;j--)
        {
            if(dp[j].size()!=0)
            {
                for(int k=0;k<dp[j].size();k++)
                dp[j+a[i]].push_back(dp[j][k]+b[i]);
            }
        }
    }
    for(int i=10000*100;i>=1;i--)
    {
        if(dp[i].size()!=0)
        {
            for(int j=0;j<dp[i].size();j++)
            {
                if(i/dp[i][j]==k&&i%dp[i][j]==0)
                {
                    cout<<i<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<-1<<endl;
}

