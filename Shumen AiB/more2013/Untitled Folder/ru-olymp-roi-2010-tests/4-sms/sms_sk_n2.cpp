#include <cstdio>
#include <cstring>
#include <cassert>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int maxn = 100010;
const int inf = (int)1e6;

int n[6];
int d[5][maxn], p[5][maxn];
char s[5][maxn][11];
vector <string> res;

void read( int i )
{
  scanf("%s", s[i][n[i]++]);
}

inline int lcp( char *s, char *t )
{
  int k = 0;
  while (*s && *s == *t)
    s++, t++, k++;
  return k;
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

  int tmp;
  memset(d, 0x10, sizeof(d));
  d[0][0] = 0;
  forn(i, 5)
    forn(j, n[i])
      forn(k, n[i + 1])
        if (d[i + 1][k] > (tmp = d[i][j] + 10 - lcp(s[i][j], s[i + 1][k])))
          d[i + 1][k] = tmp, p[i + 1][k] = j;

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
