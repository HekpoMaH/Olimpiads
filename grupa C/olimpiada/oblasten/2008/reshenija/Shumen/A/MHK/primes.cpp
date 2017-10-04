#include <iostream>
using namespace std;
int dp[60009];
int pr[60009];
int prime[10000],brp=0;
int n;
int main()
{ 
	int i;
	cin>>n;
	if(n==0){cout<<0<<endl;return 0;}
	pr[0]=pr[1]=1;
	for(i=2;i<=50023;i++)
	{
		if(pr[i]==0)
		{
			prime[brp++]=i;
			int k=2;
			while(k*i<=50023){pr[k*i]=1;k++;}
		}
	}	
	int MOD=(*upper_bound(prime,prime+brp,n));

	int sz=upper_bound(prime,prime+brp,n)-prime;

	dp[0]=1;
	//iz[0]=1;
	int j;
	for(i=0;i<=sz;i++)
	for(j=0;j+prime[i]<=n;j++)
	{
		
			dp[j+prime[i]]+=dp[j];
			if(dp[j+prime[i]]>MOD)dp[j+prime[i]]-=MOD;
		//dp[i]%=MOD;
	}

	int res=dp[n]%MOD-!pr[n];
    if(res==-1)
	    cout<<MOD-1<<endl;
	else
	    cout<<res%MOD<<endl;

	return 0;	
}
