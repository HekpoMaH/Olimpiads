/*
TASK: metro
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int n,a[1050],i,k,res1,res2,res3,res4,ans,dp[1050][110],tmp;

int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
     scanf("%d",&a[i]);
    ans=10000000;
    for(k=0;k<=100;k++)
    {
        if(k>a[0])dp[0][k]=7*(k-a[0]);
        else if(k<a[0])dp[0][k]=(a[0]-k)*(a[0]-k);
        else dp[0][k]=1;
    }
    for(i=1;i<n;i++)
    {
        for(k=0;k<=100;k++)
        {
            res1=res2=res3=res4=10000000;
            if(k>a[i])tmp=7*(k-a[i]);
            else if(k<a[i])tmp=(a[i]-k)*(a[i]-k);
            else tmp=1;
            res1=dp[i-1][k]+tmp;
            if(k-1>=0)res2=dp[i-1][k-1]+tmp;
            if(k+1<=100)res3=dp[i-1][k+1]+tmp;
            if(k+2<=100)res4=dp[i-1][k+2]+tmp;
            dp[i][k]=min(res1,min(res2,min(res3,res4)));
        }
    }
    for(k=0;k<=100;k++)
     ans=min(ans,dp[n-1][k]);
    printf("%d\n",ans);
}
