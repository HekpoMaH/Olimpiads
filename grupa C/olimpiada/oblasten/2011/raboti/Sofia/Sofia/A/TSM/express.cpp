#include <cstdio>
#include <cstring>

typedef long long int lli;
char expr[32];
lli dp[32][32];
const lli inf = 1ll<<62;

int main ()
{
  gets (expr);

  int n = strlen (expr);
  for (int d = 0; d < n; d += 2)
  {
    for (int l = 0; l + d < n; l += 2)
    {
      int r = l + d;
      dp[l][r] = inf;
      if (l == r) dp[l][r] = expr[l] - '0';
      else for (int m = l + 1; m < r; m += 2)
      {
        if      (expr[m] == '+' && dp[l][r] > dp[l][m - 1] + dp[m + 1][r]) dp[l][r] = dp[l][m - 1] + dp[m + 1][r];
        else if (expr[m] == '-' && dp[l][r] > dp[l][m - 1] - dp[m + 1][r]) dp[l][r] = dp[l][m - 1] - dp[m + 1][r];
        else if (expr[m] == '*' && dp[l][r] > dp[l][m - 1] * dp[m + 1][r]) dp[l][r] = dp[l][m - 1] * dp[m + 1][r];
      }
    }
  }
/*
  for (int l = 0; l < n; l += 2, printf ("\n"))
    for (int j = 0; j < n; j += 2) printf ("%lld ", dp[l][j]);
*/
  printf ("%lld\n", dp[0][n - 1]);
  return 0;
}
