/*
FROM: BalticOI 1997 day 2
PROB: boc (a bank)
KEYW: dynamical programming
*/

#include <cstdio>

const int MAXN = 1 << 14;

unsigned N;
int dp[MAXN];
int nxt[MAXN];

int main () {
	scanf ("%u", &N);

	dp[1] = 0;

	for (unsigned i = 2; i <= N; ++i)
		dp[i] = dp[(i >> 1) | (i & 1)] + 1;

	static bool used[MAXN] = {0};

	for (unsigned i = 1; i <= N; ++i)
		scanf ("%d", nxt + i);

	int cntr;
	int c;
	int ans = 0;
	for (unsigned i = 1; i <= N; ++i) {
		if (!used[i]) {
			cntr = 0;
			c = i;
			do {++cntr; used[c] = 1; c = nxt[c];} while (!used[c]);
//			printf ("%d(%d)\n", cntr, dp[cntr]);
			ans >?= dp[cntr];
		}
	}

	printf ("%d\n", ans);

	return 0;
}
