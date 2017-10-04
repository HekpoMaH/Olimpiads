/*
FROM: BalticOI 1998 day 2
PROB: star
KEYW: dynamical programming, hardcoding, greedy
*/

#include <cstdio>
#include <climits>
#include <utility>

const int MAXN = 1 << 6;
const int MAXIL = 1 << 4;
const int MAXL = 1 << 4;
const int L = 12;
const int MASK = 1 << L;
const int N = 48;

int inl[MAXL][MAXIL] = {
	{4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14},
	{15, 16, 17, 18, 19, 20, 21, 22, 23},
	{24, 25, 26, 27, 28, 29, 30, 31, 32},
	{33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43},

	{0, 1, 2, 7, 9, 16, 17, 24, 25, 33, 34},
	{3, 9, 10, 18, 19, 26, 27, 35, 36},
	{11, 12, 10, 12, 28, 29, 37, 38, 44},
	{13, 14, 22, 23, 30, 31, 39, 40, 45, 46, 47},

	{4, 5, 15, 16, 25, 26, 36, 37, 44, 45, 47},
	{6, 7, 17, 18, 27, 28, 38, 39, 46},
	{1, 8, 9, 19, 20, 29, 30, 40, 41},
	{0, 2, 3, 10, 11, 21, 22, 31, 32, 42, 43}
};

int inls[MAXL] = {11, 9, 9, 11, 11, 9, 9, 11, 11, 9, 9, 11};

int mpl[MAXL];
std::pair <int, int> mmax[MAXN];
int dp[MAXN][MASK];

int main () {
	int i, j;
	for (i = 0; i < L; ++i) scanf ("%d", mpl + i);
	for (i = 0; i < N; ++i) mmax[i].first = INT_MAX;
	for (i = 0; i < L; ++i)
		for (j = 0; j < inls[i]; ++j)
			if (mmax[inl[i][j]].first > mpl[i])
				mmax[inl[i][j]] = std::make_pair (mpl[i], 1 << i);
			else if (mmax[inl[i][j]].first == mpl[i])
				mmax[inl[i][j]].second |= 1 << i;


	for (j = 0; j < MASK; ++j) dp[N][j] = INT_MAX / 2;
	dp[N][0] = 0;//when nothing is covered

	for (i = N-1; i >= 0; --i) {
		for (j = 0; j < MASK; ++j)
			dp[i][j] = dp[i+1][j];
		for (j = 0; j < MASK; ++j)
			dp[i][j | mmax[i].second] <?= dp[i+1][j] + mmax[i].first;
	}

	int maxsum = 0;
	for (i = 0; i < N; ++i) maxsum += mmax[i].first;

	printf ("%d %d\n", dp[0][MASK-1], maxsum);

	return 0;
}
