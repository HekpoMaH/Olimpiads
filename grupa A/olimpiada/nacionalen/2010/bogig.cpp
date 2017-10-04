#include<bits/stdc++.h>
using namespace std;
const int maxn=20;
int n,mas[maxn],dp[1<<maxn];
int read()
{

    cin>>n;
    for(int i=0;i<n;i++)cin>>mas[i];
    sort(mas,mas+n);
    int mask=0,prev=mas[0];
    for(int i=1;i<n;i++)
    {
        if(mas[i]!=prev)mask^=(1<<i);
        prev=mas[i];
    }
    return mask;
}
int go(int mask)
{
    if(dp[mask]!=-1)return dp[mask];
    dp[mask]=0;
    int cur;
    for(int i=1;i<n;i++)
    {
        if(i==n-1||(mask & (1<<(i+1))))
        {
            for(int j=i-1;j>=0;j--)
            {
                if( (mask&(1<<(j+1))) )
                {
                    cur=mask>>(i+1);
                    cur<<=(i-j-1);
                    cur|=(mask & ((1<<i)-1)) >> (j+1);
                    cur<<=1;
                    cur<<=(j+1);
                    cur|=(mask&((1<<(j+1))-1));
                    dp[mask]=max(dp[mask],go(cur)^1);
                    if(dp[mask]==1)return 1;
                }
            }
        }
    }
    return dp[mask];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cout<<go(read())<<"\n";
}
