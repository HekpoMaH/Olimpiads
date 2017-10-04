#include<iostream>
using namespace std;
long long tb[100][100],dp[100][100],n;
int main()
{
  ios::sync_with_stdio(false);
  cin>>n;
  dp[0][0]=1;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>tb[i][j];
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(dp[i][j]>0&&tb[i][j]!=0)
      {
      if(i+tb[i][j]<n)dp[i+tb[i][j]][j]+=dp[i][j];
      //if(i+tb[i][j]==n-1&&j==n-1&&dp[i][j]!=0){dp[n-1][n-1]++;cout<<i<<" "<<j<<endl;}
      if(j+tb[i][j]<n)dp[i][j+tb[i][j]]+=dp[i][j];
      }
      //if(i==n-1&&j+tb[i][j]==n-1&&dp[i][j]!=0){dp[n-1][n-1]++;cout<<i<<" "<<j<<endl;}
    }
  }
  cout<<dp[n-1][n-1]<<endl;
  return 0;
}
