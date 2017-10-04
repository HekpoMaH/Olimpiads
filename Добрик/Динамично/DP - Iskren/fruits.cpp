/*
FROM: BalticOI 1998 day 1
PROB: fruits
KEYW: dynamical programming
*/

#include <cstdio>

const int MAXN = 1 << 6;
const int TARG = 1 << 10;

int N;
int prev[TARG];
bool pos[TARG];

int main () {
	scanf ("%d", &N);

	int i, j;
	int crnt;
	pos[0] = 1;
	for (i = 0; i < N; ++i) {
		scanf ("%d", &crnt);
		for (j = 1000; j >= crnt; --j)
			if (!pos[j] && pos[j - crnt]) {
				pos[j] = 1;
				prev[j] = crnt;
			}
	}

	if (!pos[1000]) {printf ("NO\n"); return 0;}
	for (i = 1000; i; i -= prev[i])
		printf ("%d\n", prev[i]);

	return 0;
}
