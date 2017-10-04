#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

typedef long long ll;

using namespace std;

const ll INF = 8e18;

// 0 + 1 + ... + (k - 1) = 
ll sum(int k) {
	return 1LL * k * (k - 1) / 2;
}

int main() {

	int n, m, k, x0, y0;
	cin >> n >> m >> k;
	vector<int> x(m + 1), y(m + 1);
	for (int i = 0; i <= m; i++) cin >> y[i] >> x[i];

	ll ans = INF;
	vector<int> vct;
	map<int, vector<int> > mp;
	for (int i = 0; i <= m; i++) {
		vct.push_back(y[i]);
		if (y[i] > 1) vct.push_back(y[i] - 1);
		if (y[i] < n) vct.push_back(y[i] + 1);
		mp[y[i]].push_back(x[i]);
	}
	sort(vct.begin(), vct.end());
	vct.resize(unique(vct.begin(), vct.end()) - vct.begin());

	for (int it = 0; it < (int)vct.size(); it++) {
		vector<int> v = mp[vct[it]];
		v.push_back(0);
		v.push_back(n + 1);
		sort(v.begin(), v.end());
		for (int i = 1; i < (int)v.size(); i++) {
			if (v[i] - v[i - 1] - 1 >= k) {
				int l = v[i - 1] + 1;
				int r = v[i] - 1;
				ll res = 0;

				if (l <= x[m] && x[m] <= r) {
					int a1 = x[m] - l;
					int a2 = r - x[m];
					if (a1 > a2) swap(a1, a2);
					int opt = (k - 1) / 2;
					if (a1 > opt) {
						a1 = opt;
					}
					a2 = (k - 1) - a1;
					res = sum(a1 + 1) + sum(a2 + 1) + 1LL * abs(y[m] - vct[it]) * k;
				}
				else {
					res = sum(k) + 1LL * (abs(y[m] - vct[it]) + max(x[m] - r, l - x[m])) * k;
				}

				ans = min(ans, res);
			}
		}
	}

	if (ans == INF) ans = -1;
	cout << ans << endl;

	return 0;
}
