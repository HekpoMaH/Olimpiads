//„астичное решение за O(n log n) с различными отсечени€ми. 

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
  long long ub = round(sqrt(n / 3));
  for (long long a = 1; a <= ub; ++a)
  {
    long long ab = a * a;
    for (long long b = a; b <= ub; ++b)
    {
      long long c = (n - ab) / (a + b);
      if (c < b) break;
      if (ans < ab * c)
      {
        ra = a;
        rb = b;
        rc = c;
        ans = ab * c;
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


