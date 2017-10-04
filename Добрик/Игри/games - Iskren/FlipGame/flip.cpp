/*
FROM: Balkan Olympiad in Informatics (BOI) 1999 day 1
PROB: the flip game
KEYW: bit force, brute force, binary
*/

#include <cstdio>

const int MAXM = 1 << 10;
const int N = 9;

int M;
unsigned short vec[MAXM];

int main () {
	scanf ("%d", &M);

	int i, j;
	unsigned short a;
	for (i = 0; i < M; ++i) {
		for (j = 0; j < N; ++j) {
			scanf ("%hu", &a);
			vec[i] <<= 1;
			vec[i] |= a;
		}
	}

	unsigned short k;
	int p;
	int best = M * 9, cres;
	for (k = 0; k < (1 << N); ++k) {
		cres = 0;
		for (i = 0; i < M; ++i) {
			cres += ((p = __builtin_popcount (k ^ vec[i])), p <? (9 - p));
		}
		best <?= cres;
	}

	printf ("%d\n", best);

	return 0;
}
