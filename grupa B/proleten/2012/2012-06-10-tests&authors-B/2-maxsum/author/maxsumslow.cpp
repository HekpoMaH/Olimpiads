#include <stdio.h>

#define MAXN 1001
#define INF -2000000000

long a[MAXN][MAXN], dp_old[MAXN][MAXN], dp_new[MAXN][MAXN];
int N, K;

void readInput() {
	int i, j;
	
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%ld", &a[i][j]);
}

long getOld(int i, int j) {
	if ((i < 0) || (i >= N) || (j < 0) || (j >= N))
		return INF;
		
	return dp_old[i][j];
}

long getNew(int i, int j) {
	if ((i < 0) || (i >= N) || (j < 0) || (j >= N))
		return INF;
		
	return dp_new[i][j];
}

long max(long a, long b) {
	return (a > b ? a : b);
}

long max4(long a, long b, long c, long d) {
	return max(max(a, b), max(c, d));
}

void solve() {
	int i, j, k;
	long answ;
	
	dp_new[0][0] = a[0][0];
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			if ((i != 0) || (j != 0)) {
				dp_new[i][j] = a[i][j] + max( getNew(i-1, j), getNew(i, j-1) );
			}
		}
	
	answ = dp_new[N-1][N-1];
	for (k = 1; k <= K; k++) {
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				dp_old[i][j] = dp_new[i][j];	
				
				
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				dp_new[i][j] = a[i][j] + 
					max4( getNew(i-1, j), getNew(i, j-1), getOld(i+1, j), getOld(i, j+1) );
		
		answ = max(answ, dp_new[N-1][N-1]);
	}
	
	printf("%ld\n", answ);
}

int main () {

	readInput();
	solve();

	return 0;
}
