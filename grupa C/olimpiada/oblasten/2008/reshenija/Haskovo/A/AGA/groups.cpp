
#include <iostream>
using namespace std;

const double INF = 1e100;

int n, p;
double num[505];
double pre[505][505];
double dp[505][505];

void read()
{
	cin >> n >> p;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
}
void solve()
{
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= p; ++j)
			dp[i][j] = INF;
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
		{
			double x = 0.0;
			for (int k = i; k <= j; ++k)
				x += num[k - 1];
			x /= (j - i + 1.0);
			pre[i][j] = 0.0;
			for (int k = i; k <= j; ++k)
				pre[i][j] += (x - num[k - 1]) * (x - num[k - 1]);
		}
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i && j <= p; ++j)
			for (int k = 1; k <= i - j + 1; ++k)
				dp[i][j] <?= dp[i - k][j - 1] + pre[i - k + 1][i];
	printf("%.16lf\n", dp[n][p]);
}
int main()
{
	read();
	solve();
	return 0;
}
