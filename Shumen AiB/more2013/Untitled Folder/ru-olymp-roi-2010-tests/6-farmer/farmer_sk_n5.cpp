#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int maxn = 1001;

void Finalize( int res, int rx1, int ry1, int rx2, int ry2, char (*s)[maxn] );

int h, w;
char s[maxn][maxn];

int main()
{
  freopen("farmer.in", "r", stdin);
  freopen("farmer.out", "w", stdout);

  scanf("%d%d ", &h, &w);
  forn(i, h)
    gets(s[i]);

  int res = 0, rx1 = 0, ry1 = 0, rx2 = 0, ry2 = 0;
  forn(y1, h)
    forn(x2, w + 1)
      forn(x1, x2)
      {
        int is = 0, bad = 0;

        for (int y2 = y1; y2 < h; y2++)
        {
          int one = 1, zero = (s[y2][x1] == '0');
          for (int x = x1; x < x2; x++)
          {
            if (s[y2][x] != '1')
              one = 0;
            zero += (x > x1 && s[y2][x] == '0' && s[y2][x - 1] == '1');
          }
          if (zero > 1)
            bad = 1;
          if (!one)
            if (!is)
              is = 1;
            else
              for (int x = x1; x < x2; x++)
                if (s[y2][x] != s[y2 - 1][x])
                  bad = 1;
          if (bad)
            break;
            
          int size = (y2 - y1 + 1) * (x2 - x1);
          if (size > res)
            res = size, rx1 = x1, ry1 = y1, rx2 = x2, ry2 = y2 + 1;
        }
      }

  Finalize(res, rx1, ry1, rx2, ry2, s);
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
