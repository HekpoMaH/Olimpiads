#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef unsigned long long ll;

const int maxn = 1010;

void Finalize( int res, int rx1, int ry1, int rx2, int ry2, char (*s)[maxn] );

int h, w, res = 0, rx1, ry1, rx2, ry2, fail[maxn];
ll hash[maxn];
char A[maxn][maxn];

int main()
{
  freopen("farmer.in", "r", stdin);
  freopen("farmer.out", "w", stdout);

  scanf("%d%d ", &h, &w);
  forn(i, h)
    gets(A[i]);

  forn(ly, h)
  {
    memset(hash, 0, sizeof(hash));
    forn(i, w)
      hash[i] = 0, fail[i] = (A[ly][i] == '0');

    for (int ry = ly; ry < h; ry++)
    {
      forn(i, w)
        hash[i] = hash[i] * 239 + !(A[ry][i] - '0');
      forn(i, w)
        if (ry > ly && A[ry][i] == '0' && A[ry - 1][i] == '1')
          fail[i]++;

      int rx = 0, cnt = 1, bad = (hash[0] != 0), tmp;
      forn(lx, w)
      {
        if (fail[lx] > 1)
        {
          rx = lx + 1;
          cnt = 1, bad = (hash[rx] != 0);
          continue;
        }
        while (rx < w && fail[rx] <= 1 && cnt <= 3 && bad <= 1)
        {
          if (hash[rx] != hash[rx + 1])
            cnt++, bad += (hash[rx + 1] != 0);
          rx++;
        }
        if ((tmp = (ry - ly + 1) * (rx - lx)) > res)
          res = tmp, rx1 = lx, rx2 = rx, ry1 = ly, ry2 = ry + 1;
        if (hash[lx] != hash[lx + 1])
          cnt--, bad -= (hash[lx] != 0);
      }
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
