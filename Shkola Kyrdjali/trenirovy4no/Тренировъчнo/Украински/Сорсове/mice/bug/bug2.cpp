/*
 * Решение предпологает, что левее каждой мыши есть сыр
 */

#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int L = 100001;

int n, m, a[L], b[L], d[L];
bool u[100000];
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
				res = min(res, f(i + 1, j));
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
	b[m] = -1u/4;
	for (int i = 0, j = 0; i < n; ++i) {
		for (; j + 1 < m && b[j + 1] < a[i]; ++j);
		if (j < m) {
			int d1 = a[i] - b[j], d2 = b[j + 1] - a[i];
			if (d1 <= d2) u[j] = true;
			if (d1 >= d2) u[j + 1] = true;
			d[i] = min(d1, d2);
		} 
	}
	int k = 0;
	for (int j = 0; j < m; ++j) 
		if (u[j]) b[k++] = b[j];
	m = k;
	memset(F, -1, sizeof F);
	printf("%d\n", f(0, 0));
	return 0;
}
