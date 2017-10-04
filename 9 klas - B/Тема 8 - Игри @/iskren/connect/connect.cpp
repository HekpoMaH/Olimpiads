#include <cstdio>
#include <cassert>

const int MAXrN = 1 << 5;
const int MAXrM = 1 << 7;

const int MAXN = 1 << 4;
const int MAXM = 1 << 6;
const int MAXMSK = 1 << 13;

const int INF = 10000;

int rN, rM;
char map[MAXrN][MAXrM];

int N, M, MSK;
short dp[MAXN][MAXM][MAXMSK];
char prev[MAXN][MAXM][MAXMSK];

const int cc = 7;//case count
int addp[] = 		{0		, 2		, 2		, 1		, 2		, 2		, 3		, 0		, 0		, 1		, 1};
bool bit_0[][2] = 	{{0, 0}	, {0, 1}, {1, 0}, {1, 1}, {0, 1}, {1, 0}, {0, 0}};
bool bit_1x[][2] =	{{0, 0} , {1, 0}, {0, 1}, {0, 0}, {0, 1}, {1, 0}, {1, 1}};
unsigned bit_1[] =	{0		, 1		,  2	, 0		, 2		, 1		, 3		, 0		, 0		, 1		, 2};

inline unsigned appl (const unsigned &k, const int &i, const int &c) {
//	printf ("appl %x %d %d -- %x\n", k, i, c, k & ~((1 << i) | (1 << (i+1))) | (bit_1[c] << i));
	return k & ~((1 << i) | (1 << (i+1))) | (bit_1[c] << i);
}

int main () {
	scanf ("%d %d\n", &rN, &rM);

	int i, j, k;
	for (i = 0; i < rN; ++i) {
		fgets (map[i], rM + 1, stdin);
		getchar ();
	}
	
	N = rN / 2;
	M = rM / 2;
	MSK = 1 << (N + 1);
	for (i = 1; i < MSK; ++i) dp[0][M][i] = INF;
	dp[0][M][0] = 0;

	bool bit1, bit2;
	int c, Xcnt = 0;
	for (j = N - 1; j >= 0; --j) {
		i = N;
		for (k = 0; k < MSK; ++k) {
			if (k & (1 << N)) dp[i][j][k] = INF;
			else dp[i][j][k] = dp[0][j+1][k << 1];
		}

		for (i = N - 1; i >= 0; --i) {
			if (map[i * 2 + 1][j * 2 + 1] == 'X') ++Xcnt;
			for (k = 0; k < MSK; ++k) {
				//check if the mask is correct
				if (k & (1 << i	   ) && map[i * 2    ][j * 2 + 1] != ' ') {dp[i][j][k] = INF; continue;}
				if (k & (1 << i + 1) && map[i * 2 + 1][j * 2    ] != ' ') {dp[i][j][k] = INF; continue;}

				dp[i][j][k] = INF;
				prev[i][j][k] = 20;
				bit1 = !!(k & (1 << i    ));
				bit2 = !!(k & (1 << i + 1));
				if (map[i * 2 + 1][j * 2 + 1] == 'X') {
					if (bit1 && !bit2) {
						dp[i][j][k] = dp[i+1][j][appl (k, i, cc)] + addp[cc];
						prev[i][j][k] = cc;
					} else if (!bit1 && bit2) {
						dp[i][j][k] = dp[i+1][j][appl (k, i, cc + 1)] + addp[cc+1];
						prev[i][j][k] = cc + 1;
					} else if (!bit1 && !bit2) {
						if (dp[i][j][k] > dp[i+1][j][appl (k, i, cc + 2)] + addp[cc+2]) {
							dp[i][j][k] = dp[i+1][j][appl (k, i, cc + 2)] + addp[cc+2];
							prev[i][j][k] = cc + 2;
						}
						if (dp[i][j][k] > dp[i+1][j][appl (k, i, cc + 3)] + addp[cc+3]) {
							dp[i][j][k] = dp[i+1][j][appl (k, i, cc + 3)] + addp[cc+3];
							prev[i][j][k] = cc + 3;
						}
					} else if (bit1 && bit2) {
						dp[i][j][k] = INF;
					}
				} else {
					for (c = 0; c < cc; ++c) {
						if (bit_0[c][0] == bit1 && bit_0[c][1] == bit2) {
							if (dp[i][j][k] > dp[i+1][j][appl (k, i, c)] + addp[c]) {
								dp[i][j][k] = dp[i+1][j][appl (k, i, c)] + addp[c];
								prev[i][j][k] = c;
							}
						}
					}
				}
			}
		}
	}

	printf ("%hd\n", dp[0][0][0] + Xcnt / 2);

	k = 0;
	for (j = 0; j < M; ++j) {
		for (i = 0; i < N; ++i) {
//			map[i * 2 + 1][j * 2 + 1] = prev[i][j][k] + 'a';
			if (prev[i][j][k] && map[i * 2 + 1][j * 2 + 1] != 'X') map[i * 2 + 1][j * 2 + 1] = '.';
			k = appl (k, i, prev[i][j][k]);
			bit1 = k & (1 << i);
			bit2 = k & (1 << i + 1);
			if (bit1) map[i * 2 + 1][j * 2 + 2] = '.';
			if (bit2) map[i * 2 + 2][j * 2 + 1] = '.';
		}
		assert ((k & (1 << N)) == 0);
		k <<= 1;
	}

	for (i = 0; i < rN; ++i) {
		for (j = 0; j < rM; ++j)
			putchar (map[i][j]);
		putchar ('\n');
	}
	
	return 0;
}
