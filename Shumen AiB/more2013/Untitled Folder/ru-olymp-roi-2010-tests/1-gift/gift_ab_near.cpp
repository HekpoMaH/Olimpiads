#include <cstdio>
#include <cassert>
#include <cmath>
#include <algorithm>

using std::max;

const long long MD = 10000;

long long ra, rb, rc;

long long getAns(long long n) 
{
	long long ans = 0;
	long long a0 = floor(sqrt(n / 6));
	n /= 2;
	for (long long a = a0; a > a0 - MD && a > 0; --a)
	{
		long long ab = a * a;
		for (long long b = a; b < a0 + MD; ++b)
		{
			long long c = (n - ab) / (a + b);
			if (c < b) break;
			if (ans < ab * c) 
			{
				ans = ab * c;
				ra = a;
				rb = b;
				rc = c;
			}
			ab += a;
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


