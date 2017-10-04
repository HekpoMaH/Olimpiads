#include <stdio.h>

#define MAXN 1000

int map[MAXN];
int dp[MAXN][MAXN];
int n;

void readInput() {
	int i;

    scanf("%d", &n);
	getchar();
    for (i = 0; i < n; i++) {
		scanf("%d", &map[i]);
	}
}

void solve() {
	int i, j;

	dp[0][0] = 0;
	if (map[0] == 2)
		dp[0][1] = 1;
	else
		dp[0][1] = -1;

	for (j = 2; j <= n; j++)
		dp[0][j] = -1;

	for (i = 1; i < n; i++) {
		if (map[i] == 2)
			dp[i][0] = dp[i-1][0];
		else {
			if (dp[i-1][1] != -1)
				dp[i][0] = dp[i-1][1];
			else
				dp[i][0] = -1;
		}

		for (j = 1; j <= n; j++) {
			if (map[i] == 2) {
				if (dp[i-1][j-1] != -1)
					dp[i][j] = dp[i-1][j-1] + j;
				else
					dp[i][j] = -1;
				if ((dp[i-1][j] != -1) && (dp[i-1][j] < dp[i][j])) {
					dp[i][j] = dp[i-1][j];
				}
			} else {
				if ((j+1 <= n) && (dp[i-1][j+1] != -1))
					dp[i][j] = dp[i-1][j+1] + j;
				else
					dp[i][j] = -1;
			}
		}
	}
}

void writeOutput() {
	printf("%d\n", dp[n-1][0]);
}

int main () {

	readInput();
	solve();
	writeOutput();

    return 0;
}
