//Частичное решение, в котором перебирается a, но не перебирается b.


#include <cstdio>
#include <cassert>
#include <cmath>
#include <algorithm>

using std::max;

long long ra, rb, rc;

long long getAns(long long n) {
    double ac = sqrt(n / 6);
    double a0 = floor(ac);
    long long a = round(a0);
    long long ans = 0;
    int cnt = 0;
    while (true) {
      double bc = sqrt(a * a + n / 2.0) - a;
      if (a * bc * bc < ans)
        break;
      double b0 = floor(bc);
      long long b = round(b0);
      long long c = (n - 2 * a * b) / (2 * a + 2 * b);
      if (ans < a * b * c) {
        ra = a;
        rb = b;
        rc = c;
	ans = a * b * c;
      }
      --a;
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


