/*
 * Почти правильное решение, не учитывает что мыши могут прибежать к сыру одновременно
 */
#include <cstdlib>
#include <cstdio>

int n, m, X0[100000], X1[100000];

int dist(int i, int j) { 
	return j < m ? abs(X0[i] - X1[j]) : -1u/2;
}

int main() {
	freopen("mice.dat", "r", stdin);
	freopen("mice.sol", "w", stdout);
	scanf("%d%d%*d%*d", &n, &m);
	for (int i = 0; i < n; ++i) 
		scanf("%d", X0 + i);
	for (int i = 0; i < m; ++i)
		scanf("%d", X1 + i);
	int res = n, last = -1, last_dist = -1;
	for (int i = 0, j = 0; i < n && j < m; ++i) {
		for (; j + 1 < m && X1[j + 1] <= X0[i]; ++j);
		int d1 = dist(i, j), d2 = dist(i, j + 1);
		if (d2 < d1) {
			d1 = d2;
			d2 = -1u/2;
			++j;
		}
		if (j != last || d1 == d2 && ++j) {
			--res;
			last_dist = d1;
			last = j;
		} else if (d1 < last_dist)
			last_dist = d1;
	}
	printf("%d\n", res);
	return 0;
}
