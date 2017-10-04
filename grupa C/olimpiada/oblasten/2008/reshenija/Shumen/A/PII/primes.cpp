#include <cstdio>
using namespace std;

const int MAX_PRIMES = 6000;
const int MAX_N      = 50100+5;

int n;
int primes=0;
int A[MAX_PRIMES];
int dp[MAX_N + 100];
int ans;

void find_primes ()
{
	int i, j;

	ans = 0;
	for (i=2; i<MAX_N; i++) {
		for (j=2; j*j<=i; j++)
			if (i%j == 0)
				goto L1;
		
		if (i==n) ans=-1;
		A[primes++] = i;
L1: ;
	}
}

void solve ()
{
	int i, j, p;

	for (i=0; A[i]<=n; i++) ;
	p = A[i];

	dp[0] = 1;
	for (i=0; i<primes; i++)
		for (j=0; j<=n-A[i]; j++) {
			dp[j+A[i]] += dp[j];
			if (dp[j+A[i]]>=p)
				dp[j+A[i]]-=p;
		}

	ans += dp[n];
}

int main ()
{
	scanf ("%d", &n);
	find_primes ();
	solve ();

	printf ("%d\n", ans);

	return 0;
}