#include <stdio.h>

#define MAXN 1001
#define INF -2000000000
#define max(x, y) ((x) > (y) ? (x) : (y))

long a[MAXN][MAXN], dp_old[MAXN][MAXN], dp_new[MAXN][MAXN];
int N, K;

void readInput() {
	int i, j;
	
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%ld", &a[i][j]);
}

void solve() {
	int i, j, k;
	long answ, tmp;
	
	dp_new[0][0] = a[0][0];
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			if ((i != 0) || (j != 0)) {
				if (i - 1 >= 0) tmp = dp_new[i-1][j]; else tmp = INF;
				if (j - 1 >= 0) tmp = max(tmp, dp_new[i][j-1]);
				
				dp_new[i][j] = a[i][j] + tmp;
			}
		}
	
	answ = dp_new[N-1][N-1];
	for (k = 1; k <= K; k++) {
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				dp_old[i][j] = dp_new[i][j];	
				
				
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++) {
				if (i - 1 >= 0) tmp = dp_new[i-1][j]; else tmp = INF;
				if (j - 1 >= 0) tmp = max(tmp, dp_new[i][j-1]);
				if (i+1 < N) tmp = max(tmp, dp_old[i+1][j]);
				if (j+1 < N) tmp = max(tmp, dp_old[i][j+1]);

				dp_new[i][j] = a[i][j] + tmp;
			}
		
		answ = max(answ, dp_new[N-1][N-1]);
	}
	
	printf("%ld\n", answ);
}

int main () {

	readInput();
	solve();

	return 0;
}
