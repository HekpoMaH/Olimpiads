#include <algorithm>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

const int INF = (int)(1e9);

int main() {

	int n, k;
	cin >> n >> k;
	vector<int> a(k);
	for (int i = 0; i < k; i++) cin >> a[i];
	vector<vector<int> > b(n + 1, vector<int>(n + 1));
	for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) cin >> b[i][j];

	vector<int> cnt(1 << n);
	for (int i = 1; i < 1 << n; i++) cnt[i] = cnt[i >> 1] + i % 2;
	int sum = 0;
	vector<int> who(n + 1, -1);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < a[i]; j++) who[sum + j] = i;
		sum += a[i];
	}

	vector<vector<int> > dp(1 << n, vector<int>(n, INF));
	for (int i = 0; i < n; i++) {
		dp[1 << i][i] = b[0][i + 1];
	}
	for (int mask = 1; mask < (1 << n) - 1; mask++) {
		for (int last = 0; last < n; last++) if (mask & (1 << last)) {
			if (dp[mask][last] == -1) continue;
			const bool finish = who[cnt[mask] - 1] != who[cnt[mask]];
			for (int nw = 0; nw < n; nw++) if (!(mask & (1 << nw))) {
				if (finish) {
					dp[mask | (1 << nw)][nw] = min(dp[mask | (1 << nw)][nw], dp[mask][last] + b[last + 1][0] + b[0][nw + 1]);
				}
				else {
					dp[mask | (1 << nw)][nw] = min(dp[mask | (1 << nw)][nw], dp[mask][last] + b[last + 1][nw + 1]);
				}
			}
		}
	}
	int ans = INF;
	for (int last = 0; last < n; last++) ans = min(ans, dp[(1 << n) - 1][last] + b[last + 1][0]);
	cout << ans << endl;

	return 0;
}
