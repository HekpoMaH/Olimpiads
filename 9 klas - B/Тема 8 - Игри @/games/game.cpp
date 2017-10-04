/*
FROM: Balkan Olympiad in Informatics (BOI) 2001 day 2
PROB: game (the game)
KEYW: game theory, memory compression, interactive
*/

#include <cstdio>
#include <cassert>

//#include "mod_game.h"

const int MAXN = 1 << 11;

int N;
int lose_cnt[MAXN];
int win_move[MAXN];

int main () {
	scanf ("%d", &N);

	lose_cnt[0] = MAXN;

	int i, j;
	for (i = 1; i <= N; ++i) {
		for (j = i - 1; i - j > lose_cnt[j]; --j);
		win_move[i] = i - j;
		lose_cnt[i] = (i - j - 1) / 2;
		printf ("%d %d (%d)\n", i, lose_cnt[i], win_move[i]);
	}

	int ym = (N-1)/2;
	while (N) {
		assert (win_move[N] <= ym * 2);
		printf ("%d\n", win_move[N]);
		if (N == win_move[N]) {printf ("I WIN!\n"); return 0;}
		scanf ("%d", &ym);
		assert (ym <= win_move[N] * 2);
		N -= win_move[N];
		N -= ym;
	}

	printf ("YOU WIN!\n");

	return 0;
}
