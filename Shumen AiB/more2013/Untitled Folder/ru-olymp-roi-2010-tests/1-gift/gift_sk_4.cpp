#include <cmath>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MAX = (ll)1e10;

int main()
{
  freopen("gift.in", "r", stdin);
  freopen("gift.out", "w", stdout);

  ll n;
  cin >> n, n /= 2;
  
  ll a = (ll)(sqrt(n / 3) + 1e-6);
  ll res = a * a * a, ra = a, rb = a, rc = a;

  int cnt1 = 0, cnt2 = 0;

  while (a > 0)
  {
    cnt1++;

    // 2ab + b^2 == n
    // ab^2 --> max (let b^2 == n)
    ll L = a, R = (ll)(sqrt(n) + 1e-6) + 1, x;
    while (L < R)
    {
      x = (L + R) >> 1;
      if (2 * a * x + x * x - n > 0)
        R = x;
      else
        L = x + 1;
    }
    if (a * L * L - res <= 0)
      break;
    
    ll b = a, c = (n - a * b) / (a + b);
    ll tmp = a * b + b * c + a * c - n;

    while (1)
    {
      cnt2++;

      assert(abs(tmp) < MAX);
      while (b <= c && tmp > 0)
        tmp -= a + b, c--;
      if (b > c)
        break;
      ll x = (ll)a * b * c;
      if (x > res)
        res = x, ra = a, rb = b, rc = c;
    
      tmp += a + c, b++;
    }
    a--;
  }

  cout << res << endl;
  cout << ra << " " << rb << " " << rc << endl;

  fprintf(stderr, "cnt1 = %d\n", cnt1);
  fprintf(stderr, "cnt2 = %d\n", cnt2);
  return 0;
}
