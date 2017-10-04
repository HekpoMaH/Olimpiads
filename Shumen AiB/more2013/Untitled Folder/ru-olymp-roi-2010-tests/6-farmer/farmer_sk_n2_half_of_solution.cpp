#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef unsigned long long ll;

const int maxn = 1010;

void Finalize( int res, int rx1, int ry1, int rx2, int ry2, char (*s)[maxn] );

int h, w, res = 0, rx1, ry1, rx2, ry2;
char A[maxn][maxn];

int ones[maxn], lcp[maxn], good[maxn], num[maxn];

int main()
{
  freopen("farmer.in", "r", stdin);
  freopen("farmer.out", "w", stdout);

  scanf("%d%d ", &h, &w);
  forn(i, h)
    gets(A[i]);

  forn(i, h)
  {
    ones[i] = lcp[i] = good[i] = 0;
    num[i] = (A[i][0] == '0');
  }
  
  forn(lx, w)
  {
    forn(i, h)
    {
      ones[i] = max(lx, ones[i] - 1);
      while (ones[i] < w && A[i][ones[i]] == '1')
        ones[i]++;

      lcp[i] = max(lx, lcp[i] - 1);
      while (lcp[i] < w && A[i][lcp[i]] == A[i + 1][lcp[i]])
        lcp[i]++;

      if (lx > 0 && A[i][lx] == '1' && A[i][lx - 1] == '0')
        num[i]--;
      while (good[i] < w && num[i] < 2)
        num[i] += (A[i][good[i]] == '1' && A[i][good[i] + 1] == '0'), good[i]++;
    }

    for (int rx = lx; rx < w; rx++)
      forn(ly, h)
        if (rx < good[ly])
        {
          int ry = ly, dif = 1, non_one = (rx >= ones[ly]);
          while (ry < h && non_one <= 1 && dif <= 3 && rx < good[ry])
          {
            if (rx >= lcp[ry])
              dif++, non_one += (rx >= ones[ry + 1]);
            ry++;
          }

          int tmp;
          if ((tmp = (rx - lx + 1) * (ry - ly)) > res)
            res = tmp, rx1 = lx, rx2 = rx + 1, ry1 = ly, ry2 = ry;
        }
  }

  Finalize(res, rx1, ry1, rx2, ry2, A);
  return 0;
}

void Finalize( int res, int rx1, int ry1, int rx2, int ry2, char (*s)[maxn] )
{
  int xmi = rx2, xma = rx1, ymi = ry2, yma = ry1;
  for (int x = rx1; x < rx2; x++)
    for (int y = ry1; y < ry2; y++)
      if (s[y][x] == '0')
      {
        xmi = min(xmi, x), xma = max(xma, x);
        ymi = min(ymi, y), yma = max(yma, y);
      }
  if (xmi > xma)
    forn(x, w)
      forn(y, h)
        if (s[y][x] == '0')
          xmi = xma = x, ymi = yma = y;

  printf("%d %d %d %d\n", ymi + 1, xmi + 1, yma + 1, xma + 1);
  printf("%d %d %d %d\n", ry1 + 1, rx1 + 1, ry2, rx2);
  printf("%d\n", res);
}
