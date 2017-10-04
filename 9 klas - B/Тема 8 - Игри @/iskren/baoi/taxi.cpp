/*
FROM: BalticOI 1995 day 2
PROB: taxi (an express taxi)
KEYW: dynamical programming (dp)
*/

#include <cstdio>
#include <climits>

const int MAXN = 1 << 7;
const int MAXM = 1 << 4;
const int M = 10;

int N;
int pr[MAXM];
int dp[MAXN];
int prev[MAXN];

int main () {
	int i, j;
	for (i = 1; i <= M; ++i)
		scanf ("%d", pr + i);
	scanf ("%d", &N);

	dp[0] = 0;
	for (i = 1; i <= N; ++i) dp[i] = INT_MAX;
	for (i = 0; i < N; ++i)
		for (j = 1; j <= M; ++j)
			if (dp[i + j] > dp[i] + pr[j]) {
				dp[i + j] = dp[i] + pr[j];
				prev[i+j] = i;
			}

	int sum = 0;
	while (i != 0) {
		printf ("%d %d\n", i - prev[i], pr[i-prev[i]]);
		sum += pr[i-prev[i]];
		i = prev[i];
	}

	printf ("%d\n", sum);

	return 0;
}
