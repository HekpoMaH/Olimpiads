#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long s,n,i,j,dp[1000001];
int main()
{
  scanf("%d%d",&s,&n);
  for(i=1;i<=n;i++)
  {
     dp[i]=1;
  }
  for(i=n+1;i<=s;i++)
  {
    dp[i]=dp[i-1]+1;
    for(j=2;j<=n;j++)
    {
      if (i%j==0) {dp[i]=min(dp[i],dp[i/j]+1);}
      dp[i]=min(dp[i],dp[i-j]+1);
    }
  }
  printf("%d\n",dp[s]);
  return 0;
}
