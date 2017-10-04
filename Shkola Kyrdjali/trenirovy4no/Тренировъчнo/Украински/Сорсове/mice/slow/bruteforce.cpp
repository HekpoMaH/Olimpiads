#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

int n, m, d, X0[100000], X1[100000];

ll dist(int i, int j) { 
	i = X0[i] - X1[j];
	return (ll)i * i + (ll)d * d; 
}

int adj[100000][3], p[100000], best;
ll D[100000], F[100000];

void go(int i) {
	if (i == n) {
		for (int j = 0; j < m; ++j) {
			p[j] = 0;
			F[j] = -1ull/2;
		}
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			int j = adj[i][0];
			if (D[i] < F[j]) {
				cur -= p[j] - 1;
				p[j] = 1;
				F[j] = D[i];
			} else if (D[i] == F[j]) {
				++cur;
				++p[j];
			}
		}
		if (cur > best) best = cur;
		return;
	}
	go(i + 1);
	if (~adj[i][1]) {
		swap(adj[i][0], adj[i][1]);
		go(i + 1);
		swap(adj[i][0], adj[i][1]);
	}
}

int main() {
	freopen("mice.dat", "r", stdin);
	freopen("mice.sol", "w", stdout);
	int Y0, Y1;
	scanf("%d%d%d%d", &n, &m, &Y0, &Y1);
	d = Y1 - Y0;
	for (int i = 0; i < n; ++i) 
		scanf("%d", X0 + i);
	for (int i = 0; i < m; ++i) 
		scanf("%d", X1 + i);
	for (int i = 0; i < n; ++i) {
		adj[i][0] = adj[i][1] = adj[i][2] = -1;
		D[i] = -1ull/2;
		for (int j = 0; j < m; ++j) {
			ll d = dist(i, j);
			if (d < D[i]) {
				D[i] = d;
				adj[i][0] = j;
				adj[i][1] = -1;
			} else if (d == D[i]) 
				adj[i][1] = j;
		}
	}
	go(0);
	printf("%d\n", n - best);
	return 0;
}
