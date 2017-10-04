/*
dp solution for values <= 10000
*/

#include <iostream>

using namespace std;

const int MAXN = 36;
const int MAXVALUE = 1000;

long long dp[MAXN * MAXVALUE + 1];

int main()
{
	int n;
	int t; // t can be int, because it is clearly stated that there is at least one possible combination >= t
	int points[MAXN + 1];
	int sum[MAXN + 1]; // stores the sum of the elements of points in the range [0 - i];

	cin >> n >> t;
	cin >> points[0];

	sum[0] = points[0];
	for (int i = 1; i < n; i++)
		{
			cin >> points[i];
			sum[i] = sum[i - 1] + points[i];
		}

	// dp[i] - in how many ways we can choose elements, whoose sum is exactly i
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = sum[i]; j >= points[i]; j--)
				dp[j] += dp[j - points[i]];

	long long res = 0;
	for (int i = t; i <= sum[n - 1]; i++)
		res += dp[i];

	cout << res << endl;


	return 0;
}
