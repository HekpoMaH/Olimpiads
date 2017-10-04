
#include<bits/stdc++.h>
using namespace std;

const int    MAX_N = 512;
const double INF   = 1e100;

int n, p;
double A[MAX_N];
double D[MAX_N][MAX_N];
double dp[MAX_N][MAX_N];

void input ()
{
	int i;

	scanf ("%d%d", &n, &p);

	for (i=1; i<=n; i++)
		scanf ("%lf", &A[i]);
}

void precomp ()
{
	int i, j;
	double S1, S2;

	for (i=1; i<=n; i++) {
		S1 = S2 = 0.0;

		for (j=i; j<=n; j++) {
			S1 += A[j];
			S2 += A[j]*A[j];
			D[i][j] = S2 - S1*S1/(j-i+1);
                        assert(D[i][j]>=0);
		}
	}
}

void solve ()
{
	int i, j, k;

	for (i=0; i<=n; i++)
		for (j=0; j<=p; j++)
			dp[i][j] = INF;

	dp[0][0] = 0.0;

 	for (i=1; i<=n; i++)
		for (j=1; j<=i; j++)
			for (k=0; k<i; k++)
				dp[i][j] = min( dp[i][j], dp[k][j-1] + D[k+1][i] );
}

int main ()
{
	input ();
	precomp ();
	solve ();

	printf ("%.4lf\n", dp[n][p]);

	return 0;
}
