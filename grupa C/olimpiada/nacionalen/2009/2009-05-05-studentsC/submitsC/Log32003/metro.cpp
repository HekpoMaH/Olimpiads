/*
TASK: metro
LANG: C++
*/
#include<cstdio>
using namespace std;
int dp[1024][128],n,a[1024];
int best(int p,int h)
{
    int m=dp[p-1][h];
    if(h>1) if(m>dp[p-1][h-1]) m=dp[p-1][h-1];
    if(h<99) if(m>dp[p-1][h+1]) m=dp[p-1][h+1];
    if(h<98) if(m>dp[p-1][h+2]) m=dp[p-1][h+2];
    return m;
}

/*int best1(int p,int h)
{
    int m=dp[p-1][h];
    printf("%d\n",m);
    if(h>1) if(m>dp[p-1][h-1]) m=dp[p-1][h-1];
    printf("%d\n",m);
    if(h<99) if(m>dp[p-1][h+1]) m=dp[p-1][h+1];
    printf("%d\n",m);
    if(h<98) if(m>dp[p-1][h+2]) m=dp[p-1][h+2];
    printf("%d\n",m);
    return m;
}*/
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=1;i<100;i++)
    {
        if(i<a[0]) dp[0][i]=(a[0]-i)*(a[0]-i);
        else
        if(i==a[0]) dp[0][i]=1;
        else dp[0][i]=(i-a[0])*7;
    }
    for(i=1;i<n;i++)
    for(j=1;j<100;j++)
    {
        int b=best(i,j);
        if(j<a[i]) dp[i][j]=(a[i]-j)*(a[i]-j)+b;
        else
        if(j==a[i]) dp[i][j]=1+b;
        else dp[i][j]=(j-a[i])*7+b;
    }
    /*best1(3,8);
    for(j=14;j>=7;j--)
    {
        for(i=0;i<n;i++) printf("%d ",dp[i][j]);
        printf("\n");
    }*/
    int m=dp[n-1][1];
    for(i=2;i<100;i++) if(dp[n-1][i]<m) m=dp[n-1][i];
    printf("%d\n",m);
    return 0;
}
