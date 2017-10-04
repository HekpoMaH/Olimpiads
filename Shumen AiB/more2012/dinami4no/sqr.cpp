#include<iostream>
using namespace std;
long long n,dp[102][102],a[102][102],mx=-1270005;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i][j];
        }
    }
    for(int s1=1;s1<=n;s1++)
    for(int s2=1;s2<=n;s2++)
    {
        for(int i=s1;i<=n;i++)
        {
            for(int j=s2;j<=n;j++)
            {
                mx=max(mx,dp[i][j]-dp[i-s1][j]-dp[i][j-s2]+dp[i-s1][j-s2]);
            }
        }
    }
    cout<<mx<<endl;
    return 0;
}