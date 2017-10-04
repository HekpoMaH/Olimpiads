/*
FROM: SPRING 2003 A
PROB: trade
KEYW: coding, decoding, bfs, game
*/

#include <cstdio>
#include <cassert>

const int MAXN = 1 << 5;
const int MAXP = 1 << 18;
const int MAXCODE = 1 << 20;

struct tr {
	int fr, frt;
	int to, tot;
	tr () {}
	tr (int _fr, int _frt, int _to, int _tot) : fr (_fr), frt (_frt), to (_to), tot (_tot) {}
};

int N, P, C;
int V[MAXN];
int U[MAXN];
int T[MAXN];
tr trs[MAXP];

inline int code (int *m) {
	static int i, res;
	for (i = N-1, res = 0; i >= 0; --i)
		res += m[i] * T[i];

	return res;
}

inline void decode (int c, int *m) {
	static int i;
	for (i = 0; i < N; ++i) {
		m[i] = c / T[i];
		c %= T[i];
	}
}

int opt[MAXCODE];//0 ->undeterminded, 1-> wining, 2->losing

int prev[MAXCODE];//which is the state we are comming from
int trm[MAXCODE];//which trade we have made to reach to prev[]

int in[MAXCODE];

void prnt (int *v) {
	for (int i = 0; i < N; ++i) printf ("%d ", v[i]); printf ("\n");
}


void bfs (int targ) {
	int queue[MAXCODE];
	int p3 = 0;
/*
	for (int j = 0; j < P; ++j)
		printf ("v[%d] >= %d && v[%d] + %d <= V[%d](%d)\n",\
		trs[j].frt, trs[j].fr, trs[j].tot, trs[j].to, trs[j].tot, V[trs[j].tot]);
*/
	int i, j;
	int v[MAXN];
	for (i = 0; i < C; ++i) {
		decode (i, v);
		for (j = 0; j < P; ++j)
			if (v[trs[j].tot] >= trs[j].to && v[trs[j].frt] + trs[j].fr <= V[trs[j].frt])//we kan make a move
				++in[i];

		if (in[i] == 0) {queue[p3++] = i; opt[i] = 2; prev[i] = -1;}
	}

	int go;
	for (i = 0; i < p3; ++i) {
		if (queue[i] == targ) break;
		decode (queue[i], v);
//		printf ("%d--%d---\n", i, opt[queue[i]]);
//		prnt (v);
//		printf ("---\n");

		if (opt[queue[i]] == 1) {//winning
			for (j = 0; j < P; ++j) {
				if (v[trs[j].frt] >= trs[j].fr && v[trs[j].tot] + trs[j].to <= V[trs[j].tot]) {
					v[trs[j].frt] -= trs[j].fr;
					v[trs[j].tot] += trs[j].to;
					go = code (v);
//					prnt (v);
					assert (opt[go] != 2);
					if (!opt[go] && !(--in[go])) {opt[go] = 2; queue[p3++] = go; prev[go] = queue[i]; trm[go] = j;}
					v[trs[j].frt] += trs[j].fr;
					v[trs[j].tot] -= trs[j].to;
				}
			}
		} else {//losing
			for (j = 0; j < P; ++j) {
				if (v[trs[j].frt] >= trs[j].fr && v[trs[j].tot] + trs[j].to <= V[trs[j].tot]) {
					v[trs[j].frt] -= trs[j].fr;
					v[trs[j].tot] += trs[j].to;
					go = code (v);
//					prnt (v);
					assert (opt[go] != 2);
					if (!opt[go]) {opt[go] = 1; queue[p3++] = go; prev[go] = queue[i]; trm[go] = j;}
					v[trs[j].frt] += trs[j].fr;
					v[trs[j].tot] -= trs[j].to;
				}
			}
		}
	}
}

void bfs0 (int start) {
	int queue[MAXCODE];
	int p3 = 0;
	int go;
	int i, j;
	int v[MAXN];
	queue[p3++] = start; opt[start] = -1;
	for (i = 0; i < p3; ++i) {
		decode (queue[i], v);
		for (j = 0; j < P; ++j) {
			if (v[trs[j].tot] >= trs[j].to && v[trs[j].frt] + trs[j].fr <= V[trs[j].frt]) {
				v[trs[j].frt] += trs[j].fr;
				v[trs[j].tot] -= trs[j].to;
				go = code (v);
				if (!opt[go]) {opt[go] = -1; queue[p3++] = go; prev[queue[i]] = go; trm[queue[i]] = j; break;}
				if (opt[go] == -1) {prev[queue[i]] = go; trm[queue[i]] = j; break;}
				v[trs[j].frt] -= trs[j].fr;
				v[trs[j].tot] += trs[j].to;
			}
		}
	}
}

void doit (int *v, int mc) {
	v[trs[mc].frt] += trs[mc].fr;
	v[trs[mc].tot] -= trs[mc].to;
}

int main () {
	scanf ("%d", &N);

	int k[MAXN];
	int i;
	for (i = 0; i < N; ++i) {
		scanf ("%d %d", V + i, k + i);
		U[i] = V[i] + 1;
	}
	scanf ("%d", &P);
	int a, b, c, d;
	for (i = 0; i < P; ++i) {
		scanf ("%d %d %d %d", &a, &b, &c, &d);
		trs[i] = tr (d, c - 1, b, a - 1);//invert from/to because we are going to traverse the reversed graph
	}

	T[N-1] = 1;
	for (i = N-2; i >= 0; --i) T[i] = U[i+1] * T[i+1];
	C = T[0] * U[0];//the number of states

	int start = code (k);
	bfs (start);

	if (opt[start] == 0) bfs0 (start);

	int v[MAXN];
	int crntpos = start;
	if (opt[start] == 1) {//wining
		printf ("1\n");
		fflush (stdout);
		printf ("%d\n", trm[start] + 1);
		crntpos = prev[start];
		doit (v, trm[start]);
		fflush (stdout);
	} else
		printf ("2\n");//computer first

	int move;
	decode (crntpos, v);
	while (scanf ("%d", &move) && move) {
		--move;
		doit (v, move);
		crntpos = code (v);
		printf ("%d\n", trm[crntpos] + 1);
		fflush (stdout);
		doit (v, trm[crntpos]);
		crntpos = prev[crntpos];
		assert (opt[crntpos] != 1);//do NOT let him win
	}

	return 0;
}
