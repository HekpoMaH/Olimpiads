#include <cstdio>
#include <cstring>
#include <cassert>

#ifdef WIN32
# define LL "%I64d"
#else
# define LL "%lld"
#endif

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

#define m 100100
#define mm 26

int n, k, is[mm][mm], nu[mm];
char s[m];

int main()
{
  freopen("gems.in", "r", stdin);
  freopen("gems.out", "w", stdout);
  assert(scanf("%d%d", &n, &k) == 2);
  assert(1 <= n && n <= 100000);
  assert(1 <= k && k <= 676);
  assert(scanf("%s", s) == 1);
  assert(strlen(s) == n);
  memset(is, 0, sizeof(is));
  forn (i, k)
  {
    char a, b;
    assert(scanf(" %c %c", &a, &b) == 2);
    assert('a' <= a && a <= 'z');
    assert('a' <= b && b <= 'z');
    is[a - 'a'][b - 'a'] = 1;
  }
  memset(nu, 0, sizeof(nu));
  long long ans = 0;
  forn (i, n)
  {
    assert('a' <= s[i] && s[i] <= 'z');
    forn (j, 26)
      ans += is[j][s[i] - 'a'] * nu[j];
    nu[s[i] - 'a']++;
  }
  printf(LL "\n", ans);
  return 0;
}
