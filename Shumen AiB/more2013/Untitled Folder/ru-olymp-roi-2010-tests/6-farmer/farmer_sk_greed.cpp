#include <cstdio>
#include <cstring>
#include <algorithm>
                  
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int maxn = 301;

void Finalize( int res, int rx1, int ry1, int rx2, int ry2, char (*s)[maxn] );

int h, w, LX, RX, LY, RY;
char s[maxn][maxn];

int Sum( int y, int x )
{
  int cnt = 0;
  int dx[] = {1, 0, -1, 0};
  int dy[] = {0, 1, 0, -1};
  int is[4];
  char ch = s[y][x];

  forn(i, 4)
  {
    int x1 = x + dx[i], y1 = y + dy[i];
    is[i] = !(LX <= x1 && x1 < RX && LY <= y1 && y1 < RY && s[y1][x1] == ch);
  }
  forn(i, 4)
    cnt += (is[i] && is[(i + 1) & 3]);
  return cnt;
}

int main()
{
  freopen("farmer.in", "r", stdin);
  freopen("farmer.out", "w", stdout);

  scanf("%d%d ", &h, &w);
  forn(i, h)
    gets(s[i]);
  LX = LY = 0, RX = w, RY = h;
        
  int res = 0, rx1 = 0, ry1 = 0, rx2 = 0, ry2 = 0;
  forn(x2, w + 1)
    forn(x1, x2)
      forn(y2, h + 1)
        forn(y1, y2)
        {
          int size = (y2 - y1) * (x2 - x1);
          if (size <= res)
            continue;

          LY = y1, RY = y2, LX = x1, RX = x2;

          int cnt1 = 0;
          for (int x = x1; x < x2; x++)
            for (int y = y1; y < y2; y++)
              if (s[y][x] == '0')
                if ((cnt1 += Sum(y, x)) > 4)
                  x = x2, y = y2;
          if (cnt1 <= 4)
            res = size, rx1 = x1, ry1 = y1, rx2 = x2, ry2 = y2;
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
