#include <cstdio>
#include <cstring>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int maxn = 21;

int h, w, res;
int rx1, ry1, rx2, ry2;
int tx1, ty1, tx2, ty2;
char A[maxn][maxn];
char A0[maxn][maxn];

int main()
{
  freopen("farmer.in", "r", stdin);
  freopen("farmer.out", "w", stdout);

  scanf("%d%d", &h, &w);
  forn(i, h)
    scanf("%s", A0[i]);

  forn(y2, h + 1)
    forn(y1, y2 + 1)
      forn(x2, w + 1)
        forn(x1, x2 + 1)
        {
          memcpy(A, A0, sizeof(A));
          for (int y = y1; y < y2; y++)
            for (int x = x1; x < x2; x++)
              A[y][x] ^= 1;
          forn(ry, h + 1)
            forn(rx, w + 1)
              forn(lx, rx)
                forn(ly, ry)
                {
                  int size = (rx - lx) * (ry - ly);
                  if (size <= res)
                    continue;

                  int bad = 0;
                  for (int y = ly; y < ry; y++)
                    for (int x = lx; x < rx; x++)
                      if (A[y][x] != '1')
                        bad = 1, x = rx, y = ry;
                  if (!bad)
                  {
                    res = size;
                    rx1 = lx, ry1 = ly, rx2 = rx, ry2 = ry;
                    tx1 = x1, ty1 = y1, tx2 = x2, ty2 = y2;
                  }
                }
        }

  printf("%d %d %d %d\n", ty1 + 1, tx1 + 1, ty2, tx2);
  printf("%d %d %d %d\n", ry1 + 1, rx1 + 1, ry2, rx2);
  printf("%d\n", res);
  return 0;
}
