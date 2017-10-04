#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
	freopen("mice.dat", "r", stdin);
	freopen("mice.sol", "w", stdout);
	int n, m;
	scanf("%d%d%*d%*d", &n, &m);
	vector <int> a(n), b(m);
	vector <int> d(m, -1u/2), c(m);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	vector <int> v;
	vector < pair <int, int> > u;
	for (int i = 0; i < n; ++i) {
		int j = lower_bound(b.begin(), b.end(), a[i]) - b.begin() - 1;
		vector <int> p;
		if (j >= 0 && j < m) p.push_back(j);
		if (++j < m) p.push_back(j);
		if (p.size() == 2) {
			int d0 = abs(a[i] - b[p[0]]);
			int d1 = abs(a[i] - b[p[1]]);
			if (d0 > d1) {
				swap(d0, d1);
				swap(p[0], p[1]);
			}
			if (d0 < d1) p.pop_back();
		}
		if (p.size() == 0) continue;
		j = p[0];
		int s = abs(a[i] - b[j]);
		if (s < d[j]) {
			d[j] = s;
			c[j] = 1;
		} else if (s == d[j]) 
			++c[j];			
		if (p.size() == 2) {
			v.push_back(i);
			u.push_back(make_pair(p[0], p[1]));
		}
	}
	for (int k = 0; k < v.size(); ++k) {
		int i = v[k];
		int j0 = u[k].first;
		int j1 = u[k].second;
		int s = abs(a[i] - b[j0]);
		if (s == d[j0]) 
			++c[j0];
		else if (s == d[j1]) 
			++c[j1];
		else if (d[j0] == -1u/2) {
			d[j0] = s;
			c[j0] = 1;
		} else if (d[j1] == -1u/2) {
			d[j1] = s;
			c[j1] = 1;
		}
	}
	printf("%d\n", n - accumulate(c.begin(), c.end(), 0));
	return 0;
}
