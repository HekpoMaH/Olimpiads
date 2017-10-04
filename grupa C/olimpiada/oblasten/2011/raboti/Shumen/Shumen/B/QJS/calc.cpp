#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int dp[30001][2],n,s,ans;
int main()
{
  cin>>s>>n;
  for(int i=1;i<=s;i++)
  {
    dp[i][0]=1000001;
    dp[i][1]=1000001;
  }
  for(int i=1;i<=n;i++)
  {
    dp[i][0]=1;
    dp[i][1]=1;
  }
  for(int i=n+1;i<=s;i++)
  {
    for(int j=1;j<=i/2;j++)
    {
      dp[i][1]=min(dp[i][1],min(dp[i-j][0]+dp[j][1],dp[i-j][1]+dp[j][1]));
    }
    for(int j=2;j<=sqrt(i);j++)
    {
      if(i%j==0)
      {
        dp[i][0]=min(dp[i][0],min(dp[i/j][0]+dp[j][0],dp[i/j][1]+dp[j][0]));
      }
    }
  }
  ans=min(dp[s][0],dp[s][1]);
  cout<<ans<<endl;
return 0;
}
