#include <stdio.h>

#define MAXN 1001
#define INF -2000000000

int N, K;
long a[MAXN][MAXN], dp[MAXN][MAXN];
long answ = INF, csum;

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

void go(int x, int y, int k) {
	if ((x == N-1) && (y == N-1)) {
		answ = max(answ, csum);
	}
	if (x+1 < N) {
		csum += a[x+1][y];
		go(x+1, y, k);
		csum -= a[x+1][y];
	}
	if (y+1 < N) {
		csum += a[x][y+1];
		go(x, y+1, k);
		csum -= a[x][y+1];
	}

	if (k < K) {
		if (x > 0) {
			csum += a[x-1][y];
			go(x-1, y, k+1);
			csum -= a[x-1][y];
		}
		if (y > 0) {
			csum += a[x][y-1];
			go(x, y-1, k+1);
			csum -= a[x][y-1];
		}
	}
}

void solve() {
	int i, j, tmp;

	if (N <= 10) {
		csum = a[0][0];
		go(0, 0, 0);
	} else {

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

		answ = dp[N-1][N-1];
	}

	printf("%ld\n", answ);
}

int main () {
	readInput();
	solve();

	return 0;
}
