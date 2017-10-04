/*
FROM: Balkan Olympiad in Informatics (BOI) 1998 day 2
PROB: formula 9 (f9)
KEYW: dynamical programming, bitmask
*/

#include <cstdio>

const int MAXM = 1 << 20;
const int MAXT = 4;

int D, R, T;
int wp[MAXT];
int tot[MAXT];
int dp[2][MAXM];

int main () {
	scanf ("%d %d %d", &D, &R, &T);

	int i, j, k;
	for (i = 0; i < T; ++i) scanf ("%d", wp + i);
	for (i = 0; i < D; ++i) scanf ("%d", tot + i);

	int o = 0, n = 1;
	int maxm = 1 << (T * R);
	dp[o][maxm - 1] = 1;

	int bs;
	for (i = 0; i < D; ++i) {
		for (m = 0; m < maxm; ++m)
			for (j = 0, bs = 1; j < R; ++j, bs <<= T)
				for (k = 0; k < T; ++k) {
				}
	}

	return 0;
}
