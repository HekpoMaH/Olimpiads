/*
 * Переоптимайз
 */

#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int L = 100001;

int n, m, a[L], b[L], d[L];
bool u[L];
int f[L];

int solve(int *a, int *b, int *d, int n, int m) {
	if (m == 0) return n;
	memset(f, 0, m * sizeof(int));
	for (int i = 1, j, k, t; i < n; ++i) {
		k = f[0]++;
		if (d[i] == abs(a[i] - b[0])) {
			f[0] = min(f[0], i);
			if (d[i - 1] == d[i])
				f[0] = k;
		}
		for (j = 1; j < m; ++j) {
			t = f[j];
			f[j] = min(t + 1, f[j - 1]);
			if (d[i] == abs(a[i] - b[j])) {
				f[j] = min(f[j], k);
				if (d[i - 1] == d[i])
					f[j] = t;
			}
			k = t;
		}
	}
	return f[m - 1];
}

int main() {
	freopen("mice.dat", "r", stdin);
	freopen("mice.sol", "w", stdout);
	scanf("%d%d%*d%*d", &n, &m);
	for (int i = 0; i < n; ++i) 
		scanf("%d", a + i);
	for (int i = 0; i < m; ++i)
		scanf("%d", b + i);
	if (m == 0) {
		printf("%d\n", n);
		return 0;
	}
	b[m] = -1u/4;
	for (int i = 0, j = 0; i < n; ++i) {
		for (; j + 1 < m && b[j + 1] < a[i]; ++j);
		if (j < m) {
			int d1 = abs(a[i] - b[j]), d2 = abs(b[j + 1] - a[i]);
			if (d1 <= d2) u[j] = true;
			if (d1 >= d2) u[j + 1] = true;
			d[i] = min(d1, d2);
		}
	}
	int k = 0;
	for (int j = 0; j < m; ++j) 
		if (u[j]) b[k++] = b[j];
	m = k;
	int res = 0;
	int i0 = 0, j0 = 0;
	for (int i1 = 0, j1 = 1; j1 < m; ++j1) {
		for (; i1 < n && a[i1] * 2 < b[j1 - 1] + b[j1]; ++i1);
		bool ok = false;
		if (i1 < n && a[i1] * 2 != b[j1 - 1] + b[j1]) ok = true;
		if (i1 < n && b[j1 - 1] < a[i1] && a[i1] < b[j1]) {
			if (i1 > 0 && a[i1 - 1] > b[j1 - 1]) ok = true;
			if (i1 + 1 < n && a[i1 + 1] < b[j1]) ok = true;
		}
		if (ok) {
			res += solve(a + i0, b + j0, d + i0, i1 - i0, j1 - j0);
			i0 = i1;
			j0 = j1;
		}
	}
	res += solve(a + i0, b + j0, d + i0, n - i0, m - j0);	
	printf("%d\n", res);
	return 0;
}
