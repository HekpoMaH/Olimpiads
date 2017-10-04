#include <stdio.h>

#define MAXN 1001
#define INF -2000000000

int N, K;
long a[MAXN][MAXN], dp[MAXN][MAXN];

void readInput() {
	int i, j;
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) 
			scanf("%ld", &a[i][j]);
}

long max(long a, long b) {
	return (a > b ? a : b);
}

void solve() {
	int i, j, tmp;
	dp[0][0] = a[0][0];

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			if ((i != 0) || (j != 0)) {
				tmp = INF;
				if (i > 0) 
					tmp = dp[i-1][j];
				if (j > 0)
					tmp = max(tmp, dp[i][j-1]);
				dp[i][j] = a[i][j] + tmp;
			}
		}

	printf("%ld\n", dp[N-1][N-1]);
}

int main () {
	readInput();
	solve();

	return 0;
}