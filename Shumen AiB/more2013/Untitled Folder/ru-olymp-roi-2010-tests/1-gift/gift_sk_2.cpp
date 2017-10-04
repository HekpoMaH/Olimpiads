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
  
  ll a = (ll)(sqrt(n / 3) + 1e-6), b = a;
  ll res = a * a * a;
  ll ra = a, rb = a, rc = a;
  while (a > 0) 
  {
    // 2ab + b^2 == n
    // ab^2 --> max (let b^2 == n)
    while (2 * a * b + b * b < n)
      b++;
    if (a * b * b <= res)
      break;

    for (ll b = a; a * b <= n; b++)
    {
      ll c = (n - a * b) / (a + b);
      if (c < b) // a <= b <= c
        break;

      ll tmp = (ll)a * b * c;
      if (tmp > res)
        res = tmp, ra = a, rb = b, rc = c;
    }
    a--;
  }

  cout << res << endl;
  cout << ra << " " << rb << " " << rc << endl;
  return 0;
}
