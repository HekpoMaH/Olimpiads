#include<iostream>
#include<cstring>
using namespace std;
char c[1001][1001];
int n,m,k,x,y,a[1001][3],dp[1001][3];
int main()
{
    cin>>n>>m>>x>>y;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
    cin>>c[i][j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(c[i][j]=='.')a[j][2]++;
            else a[j][1]++;
        }
    }
    memset(dp,31,sizeof(dp));
    for(int j=1;j<=m;j++)a[j][1]+=a[j-1][1],a[j][2]+=a[j-1][2];
    
    dp[0][1]=0;dp[0][2]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=x;j<=y;j++)
        {
            if(i>=j)dp[i][1]=min(dp[i][1],dp[i-j][2]+a[i][1]-a[i-j][1]);
            if(i>=j)dp[i][2]=min(dp[i][2],dp[i-j][1]+a[i][2]-a[i-j][2]);
        }
    }
    cout<<min(dp[m][1],dp[m][2])<<endl;
    return 0;
}