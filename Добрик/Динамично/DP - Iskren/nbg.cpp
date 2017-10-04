/*
FROM: BalticOI 1996 day 2
PROB: nbg (a number game)
KEYW: acyclic game, dynamical programming with mask
*/

#include <cstdio>
#include <cassert>

const int MAXM = 20;
const int MAXS = 1 << MAXM;

int N, M, S;
bool dp[MAXS];
bool done[MAXS];

bool dpf (int a) {
	if (done[a]) return dp[a];
	int n = N;
	int i;
	for (i = 0; i < M; ++i)
		if (a & (1 << i))
			n -= i + 1;
	for (i = 0; i < (M <? n); ++i) {
		if (a & (1 << i)) continue;
		if (!dpf (a | (1 << i)))
			dp[a] = 1;
	}

	done[a] = 1;
	return dp[a];
}

int main () {
	scanf ("%d %d", &N, &M);
	if (M > N) M = N;
	S = 1 << M;

	dpf (0);

	int i, j;
	printf ("%c wins\n", 'B' - dp[0]);
	for (i = 0; i < M; ++i) {
		printf ("%d ", i + 1);
		if (!dp[1 << i])
			printf ("winning\n");
		else {
			for (j = 0; j < (M <? (N - i - 1)); ++j) {
				if (i == j) continue;
//				printf ("try %d(%d)\n", j, dp[(1 << i) | (1 << j)]);
				if (!dp[(1 << i) | (1 << j)]) {
					printf ("%d\n", j + 1);
					break;
				}
			}
			assert (j != (M <? (N - i)));
		}
	}

	return 0;
}
