#include <cstdio>

#define f(i, n) for(int i = 0; i < n; i ++)
#define fo(i, a, b) for(int i = a; i <= b; i ++)

#define SQR(a) ((a) * (a))

#define INF (1e50)

#define MAX_N (512)


int N, K;
double a[MAX_N];
double d[MAX_N][MAX_N];
double dp[MAX_N][MAX_N];


void Read()
{
	scanf("%d %d", &N, &K);
	
	f(i, N) scanf("%lf", &a[i]);
}

void Precompute_D()
{
register double sum;
	
	
	f(i, N) fo(j, i, N - 1)
	{
		sum = 0;
		
		fo(k, i, j) sum += a[k];
		
		sum /= double(j - i + 1);
		
		
		fo(k, i, j) d[i][j] += SQR(sum - a[k]);
	}
}

void Solve()
{
	Precompute_D();
	
	f(i, N) f(j, N) dp[i][j] = INF;
	
	f(i, N) dp[0][i] = d[0][i];
	
	fo(i, 1, N - 1) fo(j, i, N - 1)
	{
		f(k, j)
		{
			dp[i][j] <?= dp[i - 1][k] + d[k + 1][j];
		}
	}
}

void Write()
{
	printf("%.4lf\n", dp[K - 1][N - 1]);
}

int main()
{
	Read();
	
	Solve();
	
	Write();
	
	
	return 0;
}
