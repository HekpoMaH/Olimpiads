#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

#define MAXN (1 << 6)
#define EPS (1e-15)
using namespace std;

double mass[MAXN];
double loc[MAXN];

double getSum(int from, int to, double pos)
{
	double ans = 0.;
	for (int i=from; i < to; ++i)
		ans += mass[i]/((pos-loc[i])*(pos-loc[i]));

	return ans;
}

vector<double> getPoints (vector<int> x, vector<int> m)
{
	int n = x.size();
	for (int i=0; i < n; ++i)
		mass[i] = (double)m[i],
		loc[i] = (double)x[i];

	vector<double> sol;
	sol.clear();

	for (int i=0; i+1 < n; ++i)
	{
		double l=loc[i], r=loc[i+1], mid;
		for (int iter=0; iter < 100; ++iter)
		{
			mid = (l+r)/2.;
			double f = getSum(0, i+1, mid)-getSum(i+1, n, mid);
			if (f < 0) r = mid;
			else l = mid;
		}
		sol.push_back(mid);
	}

	return sol;
}

vector<int> a, b;
inline void read()
{
	int n;
	scanf("%d", &n);
	for (int i=0; i < n; ++i)
	{
		int cur;
		scanf("%d", &cur);
		a.push_back(cur);
	}

	for (int i=0; i < n; ++i)
	{
		int cur;
		scanf("%d", &cur);
		b.push_back(cur);
	}
}

int main()
{
	int brt, testNo = 0;
	scanf("%d", &brt);

	while (brt--)
	{
		a.clear(); b.clear();
		read();
		vector<double> ans = getPoints(a, b);
		printf("Case #%d:", ++testNo);
		for (int i=0; i < ans.size(); ++i)
			printf(" %.5lf", ans[i]);
		printf("\n");
	}
	return 0;
}
