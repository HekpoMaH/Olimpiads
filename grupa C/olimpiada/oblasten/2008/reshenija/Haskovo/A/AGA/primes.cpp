
#include <iostream>
using namespace std;

int N = 65000, MOD;

int n, p = 0;
int prime[8192];
int dp[65536];
bool isprime[65536];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i <= N; ++i)
		isprime[i] = true;
	isprime[1] = false;
	for (int i = 1; i <= N; ++i)
		if (isprime[i])
		{
			prime[p++] = i;
			for (int j = i; j <= N / i; ++j)
				isprime[i * j] = false;
		}
	for (int j = n + 1; ; ++j)
		if (isprime[j]) 
		{
			MOD = j;
			break;
		}
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 0; i < p; ++i)
		for (int j = 0; j <= n - prime[i]; ++j)
		{
			dp[j + prime[i]] += dp[j];
			if (dp[j + prime[i]] >= MOD)
				dp[j + prime[i]] -= MOD;
		}
	if (!isprime[n])
		cout << dp[n] << endl;
	else
		cout << (dp[n] - 1 + MOD) % MOD << endl;
	return 0;
}
