/*
FROM: Balkan Olympiad in Informatics (BOI) 1999 day 2
PROB: knowing people
KEYW: bit force, brute force, binary
*/

#include <cstdio>

const int MAXN = 1 << 6;//64

typedef unsigned long long t_60b;

int N, M;
t_60b vec[MAXN];
bool in_q[MAXN];
int q[MAXN];

int main () {
	scanf ("%d %d", &N, &M);

	int i, j, k;
	int a, b;
	for (i = 0; i < N; ++i) vec[i] |= 1ull << i;
	for (i = 0; i < M; ++i) {
		scanf ("%d %d", &a, &b);
		--a; --b;
		vec[a] |= 1ull << b;
		vec[b] |= 1ull << a;
	}

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			if (in_q[j]) continue;

			for (k = 0; k < N; ++k)
				if ((vec[j] & (1ull << k)) && (vec[k] | vec[j]) != vec[k]) break;

//			printf ("%d %d -- %d\n", i, j, k);
			if (k == N) {
				in_q[j] = 1;
				q[i] = j;
				for (k = 0; k < N; ++k) vec[k] &= ~(1ull << j);
				break;
			}
		}
		if (j == N) {printf ("NO\n"); break;}
	}

	if (i == N) {
		printf ("YES\n%d", q[0]);
		for (i = 1; i < N; ++i) printf (" %d", q[i]); puts ("");
	}

	return 0;
}
