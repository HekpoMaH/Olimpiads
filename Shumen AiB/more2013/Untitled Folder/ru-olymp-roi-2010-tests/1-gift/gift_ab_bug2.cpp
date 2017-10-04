//Неверное решение за O(sqrt(n)). Считаемм, что одна из сторон до ровно floor(n / 6) и перебираем b.

#include <cstdio>
#include <cassert>
#include <cmath>
#include <algorithm>

using std::max;

long long ra, rb, rc;

long long getAns(long long n) 
{
	long long ans = 0;
	n /= 2;
	long long a = floor(sqrt(n / 3));
	for (long long b = a; b >= 1; --b)
	{
		long c = (n - a * b) / (a + b);
		if (ans < a * b * c)
		{
			ra = a;
			rb = b;
			rc = c;
			ans = a * b * c;
		}
	}
	return ans;
}

const long long MAXN = 1e13;

int main()
{
	freopen("gift.in", "rt", stdin);
	freopen("gift.out", "wt", stdout);
	long long n;
	assert(scanf("%lld", &n) == 1);
	assert(6 <= n && n <= MAXN);
	printf("%lld\n", getAns(n));
	printf("%lld %lld %lld\n", ra, rb, rc);
	return 0;
}


