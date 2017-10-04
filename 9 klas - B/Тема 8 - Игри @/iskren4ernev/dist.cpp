#include <cstdio>
#include <algorithm>

const int MAXN = 22;

struct pnt {
	int x, y;
	int dst (const pnt &p) const {
		return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
	}
};

int N;
pnt pnts[MAXN];
int dp[1 << MAXN];

int main () {
	scanf ("%d", &N);
	
	int i, j;
	for (i = 0; i < N; ++i)
		scanf ("%d %d", &pnts[i].x, &pnts[i].y);
	
	for (int p = (1 << N) - 1; p; --p) {
		for (i = 0; (p >> i & 1) == 0; ++i);
		for (j = i + 1; j < N; ++j)
			if (p >> j & 1) {
				int x = p & ~(1 << i) & ~(1 << j);
				dp[x] = std::max (dp[x], dp[p] + pnts[i].dst (pnts[j]));
			}
	}
	
	printf ("%d.000\n", dp[0]);

	return 0;
}

