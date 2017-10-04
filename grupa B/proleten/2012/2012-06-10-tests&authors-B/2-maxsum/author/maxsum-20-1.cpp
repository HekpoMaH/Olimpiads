#include <stdio.h>

#define MAXN 1001
#define INF -2000000000

long a[MAXN][MAXN];
int N, K;
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

void go(x, y, k) {
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
	csum = a[0][0];
	go(0, 0, 0);
	
	printf("%ld\n", answ);
}

int main () {

	readInput();
	solve();

	return 0;
}
