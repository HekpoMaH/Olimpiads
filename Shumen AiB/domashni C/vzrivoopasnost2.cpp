#include<iostream>
using namespace std;
int n,dp[22];
int main()
{
  cin>>n;
  dp[1]=3;dp[2]=8;
  for(int i=3;i<=n;i++)
  {
    dp[i]=2*dp[i-1]+2*dp[i-2];
    
  }
  cout<<dp[n]<<endl;
  return 0;
}
