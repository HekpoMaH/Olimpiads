#include<bits/stdc++.h>
using namespace std;
int n;
int ps[1009][1009];
int dp[1009][1009];
int a[1009];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int s;
    for(int i=1;i<=n;i++)
    {
        s=0;
        for(int j=i;j<=n;j++)
        {
            s+=a[j];
            ps[i-1][j]=s;
        }
    }
    for(int i=0;i<=n-2;i++)
    {
        dp[i][i+2]=ps[i][i+2];
    }
    int mn;
    for(int r=3;r<=n;r++)
    {
        for(int i=0;i<=n-r;i++)
        {
            mn=1e6;
            for(int i1=i+1;i1<=i+r-1;i1++)
            {
                mn=min(mn,dp[i][i1]+dp[i1][i+r]);
            }
            //cout<<"mn="<<mn<<" ps="<<ps[i][i+r]<<endl;
            dp[i][i+r]=mn+ps[i][i+r];
        }
    }
    cout<<dp[0][n]<<endl;
}
