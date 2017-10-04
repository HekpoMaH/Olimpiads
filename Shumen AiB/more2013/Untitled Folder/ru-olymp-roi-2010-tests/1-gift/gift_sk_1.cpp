#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
  ll res = 0;
  int n, ra = -1, rb = -1, rc = -1;

  freopen("gift.in", "r", stdin);
  freopen("gift.out", "w", stdout);

  cin >> n;
  
  n /= 2;
  for (int a = 1; a <= n; a++)
    for (int b = 1; a * b <= n && b <= a; b++)
    {
      int c = (n - a * b) / (a + b);
      if (c < a)
        break;

      ll tmp = (ll)a * b * c;
      if (tmp > res)
        res = tmp, ra = a, rb = b, rc = c;
    }

  cout << res << endl;
  cout << ra << " " << rb << " " << rc << endl;
  return 0;
}
