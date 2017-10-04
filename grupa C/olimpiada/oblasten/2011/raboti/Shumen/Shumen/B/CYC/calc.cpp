#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<stack>
using namespace std;
int main ()
{
	int k,dp[100001],s,n,i,j,ans;
	cin>>s>>n;
	dp[0]=0;
	for(k=1;k<=n;k++)
	dp[k]=1;
	for(i=n+1;i<=s;i++)
	for(j=1;j<=n;j++)
	{
		ans=910000;
		if(dp[i-j]+1<ans) ans=dp[i-j]+1;
		if(i%j==0&&j>1)
		if(dp[i/j]+1<ans) ans=dp[i/j]+1;
		dp[i]=ans;
	}
	cout<<dp[s]<<endl;
return 0;
}