#include <cstdio>
int n;
int m;
int k;
int table[1 << 10][1 << 10];
int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0;i <= n; ++i) 
		for (int j = 0;j <= m; ++j)
			table[i][j] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1;j <= m; ++j) {
			scanf("%d", &table[i][j]);
			table[i][j] += table[i - 1][j];
			table[i][j] += table[i][j - 1];
			table[i][j] -= table[i - 1][j - 1];
		}
	}
	int max = 0;
	int current;
	for (int i = k; i <= n; ++i) {
		for (int j = k;j <= m; ++j) {
			current = table[i][j] - table[i - k][j] - table[i][j - k] + table[i - k][j - k];
			if (current > max) max = current;
		}
	}
	printf("%d\n", table[n][m] - max);
	return 0;
}
