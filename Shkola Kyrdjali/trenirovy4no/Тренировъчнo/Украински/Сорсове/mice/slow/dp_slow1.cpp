/*
 * Решение динамическим программированимем, сложность - O(N * M)
 */
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int n, m, a[1000], b[1000], d[1000];
int F[1000][1000];

int f(int i, int j) {
	if (i == n) return 0;
	if (j == m) return n - i;
	int &res = F[i][j];
	if (res < 0) {
		res = min(f(i + 1, j) + 1, f(i, j + 1));
		if (d[i] == abs(a[i] - b[j])) {
			res = min(res, f(i + 1, j + 1));
			if (i + 1 < n && d[i] == d[i + 1])
				res = f(i + 1, j);
		}
	}
	return res;
}

int main() {
	freopen("mice.dat", "r", stdin);
	freopen("mice.sol", "w", stdout);
	scanf("%d%d%*d%*d", &n, &m);
	for (int i = 0; i < n; ++i) 
		scanf("%d", a + i);
	for (int i = 0; i < m; ++i)
		scanf("%d", b + i);
	for (int i = 0; i < n; ++i) {
		d[i] = -1u/2;
		for (int j = 0; j < m; ++j)
			d[i] = min(d[i], abs(a[i] - b[j]));
	}
	memset(F, -1, sizeof F);
	printf("%d\n", f(0, 0));
	return 0;
}
