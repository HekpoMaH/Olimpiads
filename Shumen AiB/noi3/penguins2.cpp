
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = (int) 1001;
const int INF = (int) 1e9;
int n, k, tcnt, sum[N], ans[N][N], p[N][N];
char s[N], res[N];

int main() {
	freopen("penguins.in", "r", stdin);
	freopen("penguins.out", "w", stdout);
	scanf("%d", &tcnt);
	for (int it = 0; it < tcnt; ++it) {
		scanf("%d%d%s", &n, &k, s);
		ans[0][0] = 0, res[n] = 0;
		for (int i = 0; i < n; ++i) {
			sum[i + 1] = sum[i] + (s[i] - '0');
			ans[0][i + 1] = INF;
		}
		for (int blocks = 0; blocks < k; ++blocks) {
			ans[blocks + 1][0] = 0;
			for (int i = 1; i <= n; ++i) {
				ans[blocks + 1][i] = INF;
				for (int j = 0; j < i; ++j)
					if (ans[blocks + 1][i] > ans[blocks][j] + min(sum[i] - sum[j], i - j - (sum[i] - sum[j]))) {
						ans[blocks + 1][i] = ans[blocks][j] + min(sum[i] - sum[j], i - j - (sum[i] - sum[j]));
						p[blocks + 1][i] = j;
					}
			}
		}
		int blocks = k, i = n;
		fill(res, res + n, '0');
		while (i > 0) {
			int j = p[blocks][i];
			if (sum[i] - sum[j] > (i - j) - (sum[i] - sum[j]))
				fill(res + j, res + i, '1');
			i = j, --blocks;
		}
		printf("%s\n", res);
	}
	return 0;
}
