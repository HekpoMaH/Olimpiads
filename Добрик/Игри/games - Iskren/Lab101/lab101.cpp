/*
FROM: NOI 2006 round 3 day 2
PROB: lab101
KEYW: cyclic game, bfs, without building graph
*/

#include <cstdio>
#include <cstring>

#define MAXN (16)
#define MAXM (16)
#define MAXK (32)
#define MAXT (10)
#define MAXSTATE (1 << 26)
//const int MAXN = 16;
//const int MAXM = 16;
//const int MAXK = 32;
//const int MAXT = 10;
//const int MAXSTATE = MAXN * MAXN * MAXM * MAXM * (1 << MAXT);

int N, M;
bool brd[MAXN][MAXM];

int K, T;//Keys, Traps
int trap_id[MAXN][MAXM];
int key_id[MAXN][MAXM];
//int keys[MAXK][2];
int gtbkc[MAXN][MAXM];
int gtcbkc[MAXN][MAXM][2];

int Tx, Ty;//target x, y

inline int encode (int p1x, int p1y, int p2x, int p2y, int keys) {
//	printf ("_________ret encode -- %d (%d %d %d %d %x)\n", ((((p1x * M + p1y) * N + p2x) * M + p2y) << T) + keys,\
	p1x, p1y, p2x, p2y, keys);
	return (p1x << 22) + (p1y << 18) + (p2x << 14) + (p2y << 10) + keys;
}

inline void decode (int state, int &p1x, int &p1y, int &p2x, int &p2y, int &keys) {
	keys = state & 1023; state >>= 10;
	p2y = state & 15; state >>= 4;
	p2x = state & 15; state >>= 4;
	p1y = state & 15; state >>= 4;
	p1x = state;
}

int SC;
char type[MAXSTATE];
char out[MAXSTATE];
//int prev[MAXSTATE];
const int MOVES = 5;
const int dx[] = {-1, 0, 1, 0, 0};
const int dy[] = {0, 1, 0, -1, 0};

inline bool in_valid_cell (int x, int y, int keys) {
	return x >= 0 && x < N && y >= 0 && y < M && !brd[x][y] && !(trap_id[x][y] != -1 && ((keys >> trap_id[x][y]) & 1));
}

inline bool save_to_switch (int x, int y, int ox, int oy) {
	return	!(gtcbkc[x][y][0] == ox && gtcbkc[x][y][1] == oy)
			&&
			!(gtcbkc[x][y][0] ==  x && gtcbkc[x][y][1] ==  y);
}
/*
inline int get_trap_by_key_coor (int x, int y) {
	return trap_id[ keys[key_id[x][y]][0] ][ keys[key_id[x][y]][1] ];
}
*/
void bfs () {
	static int q[MAXSTATE], p3, c;
	int i, j;
	int nx, ny;
	int go;
	SC = MAXSTATE;
	int p1x, p1y, p2x, p2y, keys;
	int cntr;
	for (i = 0; i < SC; ++i) {
		decode (i, p1x, p1y, p2x, p2y, keys);

		if (!(in_valid_cell (p1x, p1y, keys)
			&& in_valid_cell (p2x, p2y, keys))) {
			type[i] = 3;
			continue;
		}
		if (p1x == Tx && p1y == Ty) {
			type[i] = 3;
			continue;
		}
		if (brd[p1x][p1y] || brd[p2x][p2y]
		 || trap_id[p1x][p1y] != -1 && ((keys >> trap_id[p1x][p1y]) & 1)
		 || trap_id[p2x][p2y] != -1 && ((keys >> trap_id[p2x][p2y]) & 1)) {
			type[i] = 3;
			continue;
		}

		if (p2x == Tx && p2y == Ty) {
			type[i] = 2;//losing for the current one, terminal
			q[p3++] = i;
			continue;
		}

		cntr = 0;
		for (j = 0; j < MOVES; ++j) {
			nx = p1x + dx[j];
			ny = p1y + dy[j];
			if (in_valid_cell (nx, ny, keys))
				++out[i];
		}
		if (key_id[p1x][p1y] != -1
		 && save_to_switch (p1x, p1y, p2x, p2y))
			++out[i];//we can switch it
	}

	for (i = 0; i < p3; ++i) {
		c = q[i];
		decode (c, p1x, p1y, p2x, p2y, keys);
		for (j = 0; j < MOVES; ++j) {
			nx = p2x + dx[j];
			ny = p2y + dy[j];
			if (in_valid_cell (nx, ny, keys)) {
				go = encode (nx, ny, p1x, p1y, keys);
				if (!type[go] && (!(--out[go]) || (type[c] == 2))) {
					type[go] = 3 - type[c];
					q[p3++] = go;
//					prev[go] = c;
				}
			}
		}
		if (key_id[p2x][p2y] != -1
		 && save_to_switch (p2x, p2y, p1x, p1y)) {
		 	int nk = keys ^ (1 << gtbkc[p2x][p2y]);
			go = encode (p2x, p2y, p1x, p1y, nk);
			if (!type[go] && (!(--out[go]) || (type[c] == 2))) {
				type[go] = 3 - type[c];
				q[p3++] = go;
//				prev[go] = c;
			}
		}
	}
}

int main () {
	scanf ("%d %d\n", &N, &M);

	int i, j;
	int tmp;
	for (i = 0; i < N; ++i) {
		for (j = 0; j < M; ++j) {
			scanf ("%d", &tmp);
			brd[i][j] = tmp;
		}
		getchar ();//eat the newline
	}

	scanf ("%d\n", &K);

	memset (trap_id, -1, sizeof (trap_id));
	memset (key_id, -1, sizeof (key_id));
	int a, b, c, d;
	int init_keys = 0;
	for (i = 0; i < K; ++i) {
		scanf ("%d %d %d %d", &a, &b, &c, &d);
		--a; --b; --c; --d;
//		keys[i][0] = a; keys[i][0] = b;
		key_id[a][b] = i;
		gtcbkc[a][b][0] = c;
		gtcbkc[a][b][1] = d;
		if (trap_id[c][d] == -1) {
			if (brd[c][d]) {
				brd[c][d] = 0;//it is free now
				init_keys |= 1 << T;
			}
			trap_id[c][d] = T++;//the next trap #
		}
		gtbkc[a][b] = trap_id[c][d];
	}	

	int p1x, p1y, p2x, p2y;
	scanf ("%d %d", &p1x, &p1y); --p1x; --p1y;
	scanf ("%d %d", &p2x, &p2y); --p2x; --p2y;
	scanf ("%d %d", &Tx, &Ty); --Tx; --Ty;

	int beg_state = encode (p1x, p1y, p2x, p2y, init_keys);
//	printf ("_%x\n", beg_state);
	bfs ();
	printf ("%d\n", (int)type[beg_state]);
/*	int cstate = beg_state;
	while (cstate != -1) {
		int x, y, xx, yy, k;
		decode (cstate, x, y, xx, yy, k);
		printf ("%d %d %d %d %x __%d__\n", x, y, xx, yy, k, cstate);
		cstate = prev[cstate];
	}*/

	return 0;
}
