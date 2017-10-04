/*
FROM: SPRING 2004 A
PROB: crazy
KEYW: game, coding, decoding, fastest win
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>

const int MAXCODE = 1 << 19;
const int MAXN = 1 << 10;

int _code (int *a) {
	return (a[0] << 10) + a[1];
}

inline int code (int a, int b) {
	static int x[2];
	if (a > b) {
		x[0] = b; x[1] = a;
		return _code (x);
	} else {
		x[0] = a; x[1] = b;
		return _code (x);
	}
}

void decode (int c, int *a) {
	a[0] = (c >> 10);
	a[1] = c & ((1 << 10) - 1);
}

std::vector <int> vec[MAXCODE];
std::queue <int> q;

int opt[MAXCODE];
int in[MAXCODE];
int prev[MAXCODE];
int tm[MAXCODE];

std::vector <int> precomp[MAXN];
int out[MAXN];

int __pcs;
void precompute () {
	int i, j, k, ij;
	for (i = 2; i <= 1000; ++i) {
		out[i] = 0;
		for (j = 2; j * j < i; ++j) {
			if (i % j) continue;
			ij = i / j;
			for (k = j; k < i; k += j) {precomp[k].push_back (i); ++out[i];}
			for (k = ij; k < i; k += ij) {precomp[k].push_back (i); ++out[i];}
		}

		if (j * j == i) {precomp[j].push_back (i); ++out[i];}
	}
	for (i = 0; i < 1000; ++i) {
		std::sort (precomp[i].begin (), precomp[i].end ());
		precomp[i].resize (std::unique (precomp[i].begin (), precomp[i].end ()) - precomp[i].begin ());
//		__pcs += precomp[i].size ();
//		printf ("%d ->", i); for (j = 0; j < precomp[i].size (); ++j) printf (" %d", precomp[i][j]); printf ("\n");
	}
//	printf ("pcs %d\n", __pcs);
}

int _real;
int _comp;
void bfs () {
	int i, l;
	int go, crnt;
	int v[2];
	for (i = 0; i < MAXCODE; ++i) {
		decode (i, v);
		if (v[0] > v[1]) {opt[i] = -1; continue;}
		if (v[0] < 2) {opt[i] = -2; continue;}
		if (v[0] + v[1] > 1000) {opt[i] = -3; continue;}
		++_real;
		if (!out[v[0]] && !out[v[1]]) {opt[i] = 2; tm[i] = 0; prev[i] = -1; q.push (i); continue;}
		in[i] = out[v[0]] * (v[0] != v[1] ? out[v[1]] : 1);
//		printf ("%d -- %d\n", i, in[i]);
	}
	while (!q.empty ()) {
		crnt = q.front (); q.pop ();
		--_real;
		++_comp;
		decode (crnt, v);
		printf ("popped %d %d(%d)\n", v[0], v[1], tm[crnt]);
		if (opt[crnt] == 2) {
			for (l = 0; l < 2; ++l)
				for (i = 0; i < (int)precomp[v[l]].size (); ++i) {
					if (precomp[v[l]][i] + v[1-l] - 1 > 1000 || ((precomp[v[l]][i]) <? (v[1-l] - 1)) > 500 || v[1-l] < 3) continue;
					go = code (precomp[v[l]][i], v[1-l] - 1);
					assert (opt[go] >= 0);
					--in[go];
					assert (opt[go] != 2);
					if (!opt[go]) {opt[go] = 1; tm[go] = tm[crnt] + 1; prev[go] = crnt; q.push (go);}
				}
		} else {
			for (l = 0; l < 2; ++l)
				for (i = 0; i < (int)precomp[v[l]].size (); ++i) {
					if (precomp[v[l]][i] + v[1-l] - 1 > 1000 || ((precomp[v[l]][i]) <? (v[1-l] - 1)) > 500 || v[1-l] < 3) continue;
					go = code (precomp[v[l]][i], v[1-l] - 1);
					assert (opt[go] >= 0);
					--in[go];
					assert (opt[go] != 2);
					if (!in[go] && !opt[go]) {opt[go] = 2; tm[go] = tm[crnt] + 1; prev[go] = crnt; q.push (go);}
				}
		}
	}
	printf ("_real %d\n", _real);
	printf ("_comp %d\n", _comp);
}


int main () {
	precompute ();
	bfs ();

/*	int tmp[2];
	scanf ("%d %d", tmp, tmp + 1);
	int coded = code (tmp);
	decode (coded, tmp);
	printf ("%d %d\n", tmp[0], tmp[1]);
*/
	return 0;
}
