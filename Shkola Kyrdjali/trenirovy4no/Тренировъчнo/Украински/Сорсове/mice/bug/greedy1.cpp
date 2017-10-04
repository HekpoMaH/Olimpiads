#include <algorithm>
#include <cstdio>

using namespace std;

pair <int, int> e[200000], s[200000];

int n, m, k, a[100000], b[100000];

inline int dist(int x, int y) { return abs(a[x] - b[y]); }

void addedge(int x, int y) {
	e[k++] = make_pair(x, y);
}

bool intersects(const pair <int, int> &p, const pair <int, int> &q) {
	return p.first == q.first || p.second == q.second && dist(p.first, p.second) != dist(q.first, q.second);
}

int main() {
	freopen("mice.dat", "r", stdin);
	freopen("mice.sol", "w", stdout);
	scanf("%d%d%*d%*d", &n, &m);
	for (int i = 0; i < n; ++i) 
		scanf("%d", a + i);
	for (int i = 0; i < m; ++i)
		scanf("%d", b + i);
	for (int i = 0, j = 0; i < n; ++i) {
		for (; j + 1 < m && b[j + 1] < a[i]; ++j);
		if (j + 1 < m) {
			int d1 = dist(i, j), d2 = dist(i, j + 1);
			if (d1 <= d2) addedge(i, j);
			if (d1 >= d2) addedge(i, j + 1);
		} else if (j < m) addedge(i, j);
	}
	for (int i = 0; i < k; ++i) {
		int i0 = i, i1 = i;
		for (; i0 > 0 && intersects(e[i], e[i0 - 1]); --i0);
		for (; i1 + 1 < k && intersects(e[i], e[i1 + 1]); ++i1);
		s[i] = make_pair(i0, i1);
	}
	sort(s, s + k);
	int right = -1u/2;
	for (int i = k; i --> 0; )
		if (s[i].second < right) {
			--n;
			right = s[i].first;
		}
	printf("%d\n", n);
	return 0;
}
