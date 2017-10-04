#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
  freopen("gift.in", "r", stdin);
  freopen("gift.out", "w", stdout);

  ll n;
  cin >> n, n /= 2;
  
  ll a0 = (ll)(sqrt(n / 3) + 1e-6);
  ll step = 700, L = max(1LL, a0 - step), R = a0 + step;
  ll res = 0, ra = -1, rb = -1, rc = -1;

  for (ll a = L; a <= R; a++)
    for (ll b = L; b <= a; b++)
      if (a * b < n)
      {
        ll c = (n - a * b) / (a + b);
        if (c < b) // a <= b <= c
          break;

        ll tmp = (ll)a * b * c;
        if (tmp > res)
          res = tmp, ra = a, rb = b, rc = c;
      }

  cout << res << endl;
  cout << ra << " " << rb << " " << rc << endl;
  return 0;
}
