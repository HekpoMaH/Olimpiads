#include<iostream>
#include<cstring>
using namespace std;
int n;
int a[1505][1505];
int dp[1505][1505],t;
int inf=1555*1555;
int main()
{
    cin>>n;ios::sync_with_stdio(0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cin>>a[i][j],dp[i][j]=inf;
    }for(int i=0;i<=n;i++)dp[i][0]=dp[0][i]=inf;
    dp[1][1]=1;//cout<<dp[2][2]<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dp[i-1][j]==inf)continue;
            if((dp[i-1][j]%2==0)!=a[i][j])dp[i][j]=dp[i-1][j]+1;
            //if(dp[i-1][j]%2==1&&a[i][j]==0&&dp[i-1][j]!=inf)dp[i][j]=dp[i-1][j]+1;
            else dp[i][j]=dp[i-1][j]+2;//cout<<i<<" "<<j<<" "<<a[i][j]<<" "<<dp[i-1][j]<<" "<<dp[i][j]<<endl;
        }
        for(int j=2;j<=n;j++)
        {
            if(dp[i][j-1]==inf)continue;
            if((dp[i][j-1]%2==0)!=a[i][j])t=dp[i][j-1]+1;
            else t=dp[i][j-1]+2;
            dp[i][j]=min(dp[i][j],t);
        }
    }
    for(int i=1;i<=n;i++)
    {
        //for(int j=1;j<=n;j++)cout<<dp[i][j]<<" ";
        //cout<<endl;
    }
    cout<<dp[n][n]<<endl;
}
