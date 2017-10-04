#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long n,i,j,a[10001],dp[10001],pos[10001],ans[10001];
char p[8000][8000];
long check (long x, long y)
{
  if ((x+1)!=y)
  {
     if (p[x+1][y-1]==2 && a[x]==a[y]) {p[x][y]=2;return 1;}
     else {p[x][y]=1;return 0;}
  }
  else
  {
    if (a[x]==a[y]) {p[x][y]=2;return 1;}
    else {p[x][y]=1;return 0;}
  }
}
int main()
{
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
     scanf("%d",a+i);
     p[i][i]=2;
     dp[i]=dp[i-1]+1;
     pos[i]=i-1;
     for(j=i-1;j>=1;j--)
     {
        if (check(j,i)==1)
        {
          if ((dp[j-1]+1)<dp[i])
          {
             dp[i]=dp[j-1]+1;
             pos[i]=j-1;
          }
        }
     }
  }
  printf("%d\n",dp[n]);
  j=n;
  for(i=1;i<dp[n];i++)
  {
     ans[i]=pos[j];
     j=pos[j];
  }
  for(i=dp[n]-1;i>=1;i--)
  {
    printf("%d",ans[i]);
    if (i==1) {printf("\n");}
    else {printf(" ");}
  }
  return 0;
}
/*
16
1 1 0 0 0 1 1 0 0 0 0 1 1 0 0 0
*/
