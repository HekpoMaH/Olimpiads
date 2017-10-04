#include<bits/stdc++.h>
using namespace std;
int n,m;
double dp[1009];
double a[1009][3];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2];
    for(int i=1;i<=m;i++)dp[i]=-1;
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=0;j--)
        {
            if(j-a[i][1]>=0.0)dp[j]=max(dp[(int)(j-a[i][1])]+a[i][2],dp[j]);

        }
    }
    double mx=0;
    for(int i=1;i<=m;i++)mx=max(dp[i],mx);//,cout<<dp[i]<<" ";
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<mx<<endl;
}
