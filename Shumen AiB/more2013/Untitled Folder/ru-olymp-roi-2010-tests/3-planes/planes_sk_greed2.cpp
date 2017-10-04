#include <cstdio>
#include <cstring>
#include <ctime>

#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int maxn = 100010;

struct segment
{
  int l, r, t;
};

int n, k, rn, pn, p[maxn], res[maxn], u[maxn];
segment s[maxn];
map <int, int> next, cnt;
map <int, set<int> > pairs;

bool sless( int i, int j )
{
  return s[i].r < s[j].r;
}

int Get( int p )
{
  return next.count(p) ? (next[p] = Get(next[p])) : p;
}

int cntv = 0, start, finish = 0;

int dfs( int v )
{
  if (++cntv % 1000 == 0)
    if (clock() - start > 1.5 * CLOCKS_PER_SEC)
      finish = 1;
  if (finish)
    return 0;

  u[v] = 1;
  for (int i = s[v].l; i <= s[v].r; i++)
  {
    int good = (cnt[i] < k), old = -1;
    set <int> &s = pairs[i];
    for (set <int>::iterator it = s.begin(); it != s.end() && !good && !u[*it]; it++)
      good |= dfs(*it), old = *it;
    if (good)
    {
      if (old != -1)
        pairs[i].erase(old);
      else
        cnt[i]++;
      pairs[i].insert(v);
      res[v] = i;
      return 1;
    }
  }
  return 0;
}

int main()
{    
  start = clock();

  freopen("planes.in", "r", stdin);
  freopen("planes.out", "w", stdout);

  scanf("%d%*d%d", &n, &k);
  forn(i, n)
    scanf("%d%d%d", &s[i].l, &s[i].r, &s[i].t);
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
        rn++, res[p[i]] = x, pairs[x].insert(p[i]);
        if (++cnt[x] == k)
          next[x] = x + 1;
      }

    if (t == 0 && pn != rn)
    {
      puts("0");
      return 0;
    }
  }

  int good = 1;
  while (good && clock() - start < 1.5 * CLOCKS_PER_SEC)
  {
    good = 0;
    memset(u, 0, sizeof(u));
    forn(i, n)
      if (!res[i] && dfs(i))
        rn++, i = n, good = 1;
  }

  printf("%d\n", rn);
  forn(i, n)
    printf("%d ", res[i]);
  return 0;
}
