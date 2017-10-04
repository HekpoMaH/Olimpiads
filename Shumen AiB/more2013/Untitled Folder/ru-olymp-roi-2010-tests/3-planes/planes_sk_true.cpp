#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int maxn = 100010;

typedef pair <int, int> pii;

struct segment
{
  int l, r, t;
};
                       
int n, k, pn, p[maxn], rn[2], pa[maxn], u[maxn];
segment s[maxn];
int next[maxn], cnt[maxn];
pii res[2][maxn];
map <pii, int> link;

bool sless( int i, int j )
{
  return s[i].r < s[j].r;
}

int Get( int p )
{
  return (next[p] != -1) ? (next[p] = Get(next[p])) : p;
}

int dfs( int v )
{
  int x;

  u[v] = 1;
  if (res[1][v].first && (!link.count(res[1][v]) || (!u[x = link[res[1][v]]] && dfs(x))))
  {
    link[res[0][v] = res[1][v]] = v;
    return 1;
  }
  return 0;
}

void Solve()
{
  forn(i, n)
    scanf("%d%d%d", &s[i].l, &s[i].r, &s[i].t);
  memset(res, 0, sizeof(res));
  forn(t, 2) // t=0 : all ones, t=1 : matching of maximal size
  {
    pn = 0;
    forn(i, n)
      if (s[i].t || t)
        p[pn++] = i;
    sort(p, p + pn, sless);

    int x;
    rn[t] = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(next, -1, sizeof(next));
    forn(i, pn)
      if ((x = Get(s[p[i]].l)) <= s[p[i]].r)
      { 
        rn[t]++, res[t][p[i]] = make_pair(x, cnt[x]);
        if (++cnt[x] == k)
          next[x] = x + 1;
      }

    if (t == 0 && pn != rn[t])
    {
      puts("0");
      return;
    }
  }

  memset(u, 0, sizeof(u));
  link.clear();
  forn(i, n)
    if (res[0][i].first)
      link[res[0][i]] = i;
  forn(i, n)
    if (res[1][i].first && !res[0][i].first)
      dfs(i);

  printf("%d\n", rn[1]);
  forn(i, n)
    printf("%d%c", res[0][i].first, " \n"[i == n - 1]);
}

int main()
{
  freopen("planes.in", "r", stdin);
  freopen("planes.out", "w", stdout);

  while (scanf("%d%*d%d", &n, &k) == 2)
    Solve();
  return 0;
}
