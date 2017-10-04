/*
FROM: BalticOI 1997 day 1
PROB: seq (a subsequence)
KEYW: dynamical programming
*/

#include <cstdio>
#include <climits>
#include <algorithm>
/*
int dp[3] = {INT_MIN, INT_MIN, INT_MIN};
int mlen;

void f (int a) {
	static int buf[6], i;
	for (i = 0; i < 3; ++i) ++dp[i];
	for (i = 0; i < 3; ++i) buf[i] = dp[i];
	for (i = 0; i < 3; ++i) buf[i+3] = dp[i];
	for (i = 3-a; i < 6-a; ++i) dp[i-(3-a)] = buf[i];
	dp[a] >?= 1;
	mlen >?= dp[0];
}
*/
int main () {
	int N;
	scanf ("%d", &N);
	static int cntr[3] = {0}, sum = 0;

	for (int i = 0; i < N; ++i) {
		int c, t;
		scanf ("%d", &c);
		++cntr[sum += (t = (c % 3)), t];
//		printf ("%d ", t);
//		printf ("%d %d %d\n", dp[0], dp[1], dp[2]);
	}

//	printf ("\n%d %d %d\n", cntr[0], cntr[1], cntr[2]);
	if (cntr[1] && cntr[2])
		printf ("%d 1\n", N - !!(sum % 3));
	else
		printf ("%d 2\n", N - (cntr[1] ? cntr[1] % 3 : cntr[2] % 3));

//	printf ("%d\n", mlen);

	return 0;
}
