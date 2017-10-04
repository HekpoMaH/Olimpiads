#include <cstdio>
#include <cstring>
#include <cassert>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int maxn = 100010;
const int maxt = 1 << 17;
const int inf = (int)1e6;

int n[6], cur, ind[5][maxn];
int d[5][maxn], p[5][maxn];
char s[5][maxn][11];
int tr[2 * maxt], trInd[2 * maxt];
vector <string> res;

void read( int i )
{
  scanf("%s", s[i][n[i]++]);
}

bool sless( int i, int j )
{
  return strcmp(s[cur][i], s[cur][j]) < 0;
}

int GetMin( int v, int vL, int vR, int L, int R, int &j )
{
  if (vL > R || L > vR)
    return inf;
  if (L <= vL && vR <= R)
  {
    j = trInd[v];
    return tr[v];
  }

  int j1, j2, r1, r2, vM = (vL + vR) / 2;
  r1 = GetMin(2 * v, vL, vM, L, R, j1);
  r2 = GetMin(2 * v + 1, vM + 1, vR, L, R, j2);
  if (r2 < r1)
    r1 = r2, j1 = j2;
  j = j1;
  return r1;
}

int main()
{
  freopen("sms.in", "r", stdin);
  freopen("sms.out", "w", stdout);

  read(0), read(4);
  forn(i, 5)
  {
    int k;
    scanf("%d", &k);
    forn(j, k)
      read(i);
  }
  n[0] = n[4] = 1;
  forn(i, 5)
  {
    cur = i;
    forn(j, n[i])
      ind[i][j] = j;
    sort(ind[i], ind[i] + n[i], sless);
  }

  int tmp;
  memset(d, 0x10, sizeof(d));
  d[0][0] = 0;
  forn(i, 5)
  {
    memset(tr, 0, sizeof(tr));
    forn(j, n[i])
      tr[maxt + j] = d[i][ind[i][j]], trInd[maxt + j] = ind[i][j];
    for (int j = maxt - 1; j > 0; j--)
    {
      int t = j * 2 + (tr[j * 2] > tr[j * 2 + 1]);
      tr[j] = tr[t], trInd[j] = trInd[t];
    }

    forn(k, n[i + 1])
      forn(len, 11)
      {
        int l, r, m, sL, sR;

        l = 0, r = n[i];
        while (l < r)
          if (strncmp(s[i][ind[i][m = (l + r) / 2]], s[i + 1][k], len) < 0)
            l = m + 1;
          else
            r = m;
        sL = l;

        l = 0, r = n[i];
        while (l < r)
          if (strncmp(s[i][ind[i][m = (l + r) / 2]], s[i + 1][k], len) <= 0)
            l = m + 1;
          else
            r = m;
        sR = l;

        if (sL < sR)
        {
          int j;
          GetMin(1, 0, maxt - 1, sL, sR - 1, j);
          if (d[i + 1][k] > (tmp = d[i][j] + 10 - len))
            d[i + 1][k] = tmp, p[i + 1][k] = j;
        }
      }
  }

  int i = 4, j = 0;
  printf("%d ", d[i][j]);
  while (i)
  {
    res.push_back(s[i][j]);
    j = p[i][j], i--;
  }
  res.push_back(s[i][j]);

  int k = res.size();
  printf("%d\n", k);
  forn(i, k)
    printf("%s\n", res[k - i - 1].c_str());
  return 0;
}
