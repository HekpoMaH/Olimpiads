#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int x[16], y[16];
int p[16];
int greater (int a, int b) { return a > b ? a : b; }

int nextpperm ()
{
  sort (p + n, p + 2*n, greater);
  return next_permutation (p, p + 2*n);
}

inline int dist (int a, int b)
{
  if ((x[a] + y[a]) % 2 != (x[b] + y[b]) % 2) return 100000;
  return max (abs (x[a] - x[b]), abs (y[a] - y[b]));
}

int main ()
{
  scanf ("%d", &n);
  for (int i = 0; i < 2*n; ++i)
  {
    p[i] = i;
    scanf ("%d%d", x+i, y+i);
  }

  int res = 1000000;
  do
  {
    int tr = dist (2*n, p[0]);
    for (int i = 1; i < n; ++i) tr += dist(p[i - 1], p[i]);
    if (tr < res) res = tr;
  }
  while (nextpperm ());

  printf ("%d\n", res);
  return 0;
}
