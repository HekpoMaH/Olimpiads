#include<iostream>
#include<cstring>
using namespace std;
long long a[1000],n,dp[1002][1002],teglo[1002][1002];
int main()
{
  cin>>n;
  memset(dp,32,sizeof(dp));
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++)
  {
      for(int j=i;j<=n;j++)
      {
          teglo[i][j]=teglo[i][j-1]+a[j];
      }
  }
  for(int i=1;i<=n;i++)dp[i][i]=0;
  //cout<<teglo[2][3]<<endl;
  //long long mn;
  for(int k=1;k<=n;k++)
  {
      for(int i=1;i<=n-k;i++)
      {
          for(int j=i;j<=i+k-1;j++)
          {
              dp[i][i+k]=min(dp[i][j]+dp[j+1][i+k],dp[i][i+k]);
          }
          dp[i][i+k]+=teglo[i][i+k];
      }
  }
  cout<<dp[1][n]<<endl;
  return 0;
}
