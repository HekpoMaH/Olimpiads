#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  freopen("gift.in", "r", stdin);
  freopen("gift.out", "w", stdout);

  long long n;
  cin >> n;

  long long ac = (long long)(sqrt(double(n / 6)));

  long long best_a, best_b, best_c;
  long long ans = -1;

  for (long long a = ac; a > 0; --a) {
    long long bc = (long long)(sqrt(double(a * a + n / 2.0)) - a + 0.5);
    if (ac * ac > a * bc * bc / ac) break;
    for (long long b = bc; b > 0; --b) {
      long long c = (n - 2 * a * b) / (2 * a + 2 * b);
      if (a * b + b * c + a * c <= n / 2 &&  a * b * c > ans) {
        ans = a * b * c;
        best_a = a;
        best_b = b;
        best_c = c;
      }
      long long c_max = (n - 2 * a * b - 1) / (2 * a + 2 * b) + 1;
      if (ac * ac > a * b * c_max / ac) break;
    }
  }

  cout << ans << endl;
  cout << best_a << " " << best_b << " " << best_c << endl;

  return 0;
}