#include <cstdio>
#include <cstring>
#include <algorithm>
                  
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int maxn = 501;

void Finalize( int res, int rx1, int ry1, int rx2, int ry2, char (*s)[maxn] );

int h, w, LX, RX, LY, RY;
char s[maxn][maxn];
int sum[maxn], sumL[maxn], sumR[maxn], sumLR[maxn];
int is[maxn], isL[maxn], isR[maxn], isLR[maxn];

inline int Sum( int y, int x )
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
  forn(y1, h)
  {
    memset(sum, 0, sizeof(sum));
    memset(sumL, 0, sizeof(sumL));
    memset(sumR, 0, sizeof(sumR));

    for (int y = y1; y < h; y++)
    {
      int y2 = y + 1, size = y2 - y1;
      LY = y1, RY = y2;

      if (y > y1)
        forn(x, w)
          if (s[y - 1][x] == '0')
          {
            LX = 0, RX = w;
            sum[x] += Sum(y - 1, x);
            LX = x, RX = w;
            sumL[x] += Sum(y - 1, x);
            LX = 0, RX = x + 1;
            sumR[x] += Sum(y - 1, x);
            LX = x, RX = x + 1;
            sumLR[x] += Sum(y - 1, x);
          }
      forn(x, w)
        if (s[y][x] == '0')
        {
          LX = 0, RX = w;
          is[x] = Sum(y, x);
          LX = x, RX = w;
          isL[x] = Sum(y, x);
          LX = 0, RX = x + 1;
          isR[x] = Sum(y, x);
          LX = x, RX = x + 1;
          isLR[x] = Sum(y, x);
        }
        else
          is[x] = isL[x] = isR[x] = isLR[x] = 0;
      forn(x, w)
        sum[x] += is[x], sumL[x] += isL[x], sumR[x] += isR[x], sumLR[x] += isLR[x];

      forn(x, w)
      {
        int cnt = sumLR[x];
        if (cnt <= 4 && size > res)
          res = size, rx1 = x, rx2 = x + 1, ry1 = y1, ry2 = y2;
      }

      int x1 = 0, x2 = 2, cnt = sumL[0] + sumR[1];
      while (1)
      {
        int tmp = -1;
//        printf("x2=%d cnt=%d\n", x2, cnt);
        while (x2 < w && (tmp = cnt + (sum[x2 - 1] + sumR[x2] - sumR[x2 - 1])) <= 4)
        {
          x2++, cnt = tmp;
//          printf("x2=%d cnt=%d\n", x2, cnt);
        }
//        printf("tmp=%d\n", tmp);
//        printf("y1=%d, y2=%d, x1=%d ==> x2=%d, cnt=%d\n", y1, y2, x1, x2, cnt);

        size = (y2 - y1) * (x2 - x1);
        if (cnt <= 4 && size > res)
          res = size, rx1 = x1, rx2 = x2, ry1 = y1, ry2 = y2;
        if (++x1 >= w - 1)
          break;

        cnt += sumL[x1] - sumL[x1 - 1];
        if (x2 == x1 + 1)
          cnt += sumR[x2] - sumR[x2 - 1], x2++;
        else
          cnt -= sum[x1];
      }

      forn(x, w)
        sum[x] -= is[x], sumL[x] -= isL[x], sumR[x] -= isR[x], sumLR[x] -= isLR[x];
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
