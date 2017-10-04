#include<iostream>
using namespace std;
long long n,p[10000],dp[10000],mx,a,b;
int main()
{
  cin>>n;
  p[0]=0;dp[0]=0;
  for(int i=1;i<=n;i++)cin>>p[i];
  for(int i=1;i<=n;i++)
  {
    mx=0;
    for(int j=0;j<=i;j++)
    {
      a=dp[j];
      if(j==i)a=p[j];
      b=dp[i-j];
      if(i-j==i)b=p[i-j];
      if(a+b>mx)mx=a+b;
    }
    dp[i]=mx;
  }
  cout<<dp[n]<<endl;
  return 0;
}
