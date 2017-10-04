/*
 * Неверная инициализация динамики
 */

#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int L = 100001;

int n, m, a[L], b[L], d[L];
bool u[L];
int f[L];

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
	for (int i = 0; i < m; ++i) {
		if (d[0] == abs(a[0] - b[i]))
			f[i] = 0;
		else 
			f[i] = i ?  f[i - 1] : 1;
	}
	for (int i = 1; i < n; ++i) {
		k = f[0]++;
		if (d[i] == abs(a[i] - b[0])) 
			f[0] = i - (d[i] == d[i - 1]);
		for (int j = 1, t; j < m; ++j) {
			t = f[j];
			f[j] = min(f[j] + 1, f[j - 1]);
			if (d[i] == abs(a[i] - b[j])) {
				f[j] = min(f[j], k);
				if (d[i - 1] == d[i])
					f[j] = t;
			}
			k = t;
		}
	}
	printf("%d\n", f[m - 1]);
	return 0;
}
