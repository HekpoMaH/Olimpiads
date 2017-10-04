#include <cstdio>
#include <cstring>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef unsigned long long ll;

const int maxn = 1010;

int h, w, res = 0, resCnt = 0, rx1, ry1, rx2, ry2;
int eq[maxn], one[maxn], fail[maxn];
char A[maxn][maxn];

int main()
{
  freopen("rectangle.in", "r", stdin);
  freopen("rectangle.out", "w", stdout);

  scanf("%d%d ", &h, &w);
  forn(i, h)
    gets(A[i]);

  forn(ly, h)
  {
    forn(i, w)
      eq[i] = one[i] = 1, fail[i] = (A[ly][i] == '0');

    for (int ry = ly; ry < h; ry++)
    {
      char *row = A[ry], *last = A[ry - 1];
      forn(i, w)
      {
        eq[i] &= (row[i] == row[i + 1]);
        one[i] &= (row[i] == '1');
        if (ry > ly && row[i] == '0' && last[i] == '1')
          fail[i]++;
      }

      int rx = 0, cnt = 1, bad = !one[0], tmp;
      forn(lx, w)
      {
        if (fail[lx] > 1)
        {
          rx = lx + 1;
          cnt = 1, bad = !one[rx];
          continue;
        }
        while (rx < w && fail[rx] <= 1 && cnt <= 3 && bad <= 1)
        {
          if (!eq[rx])
            cnt++, bad += !one[rx + 1];
          rx++;
        }
        if ((tmp = (ry - ly + 1) * (rx - lx)) > res)
          resCnt = 1, res = tmp, rx1 = lx, rx2 = rx, ry1 = ly, ry2 = ry + 1;
        else if (tmp == res)
          resCnt++;
        if (!eq[lx])
          cnt--, bad -= !one[lx];
      }
    }
  }

  printf("%d\n%d %d %d %d\n", res, rx1 + 1, ry1 + 1, rx2, ry2);
  fprintf(stderr, "resCnt = %d\n", resCnt);
  return 0;
}
