#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int maxn = 100010;

struct segment
{
  int l, r, t;
};

int n, k, rn, pn, p[maxn], res[maxn];
segment s[maxn];
int next[maxn], cnt[maxn];

bool sless( int i, int j )
{
  return s[i].r < s[j].r;
}

int Get( int p )
{
  return (next[p] != -1) ? (next[p] = Get(next[p])) : p;
}

int main()
{
  freopen("planes.in", "r", stdin);
  freopen("planes.out", "w", stdout);

  scanf("%d%*d%d", &n, &k);
  forn(i, n)
    scanf("%d%d%d", &s[i].l, &s[i].r, &s[i].t);
  memset(next, -1, sizeof(next));
  forn(t, 2)
  {
    pn = 0;
    forn(i, n)
      if (s[i].t != t)
        p[pn++] = i;
    sort(p, p + pn, sless);

    int x;
    forn(i, pn)
      if ((x = Get(s[p[i]].l)) <= s[p[i]].r)
      { 
        rn++, res[p[i]] = x;
        if (++cnt[x] == k)
          next[x] = x + 1;
      }

    if (t == 0 && pn != rn)
    {
      puts("0");
      return 0;
    }
  }

  printf("%d\n", rn);
  forn(i, n)
    printf("%d ", res[i]);
  return 0;
}
