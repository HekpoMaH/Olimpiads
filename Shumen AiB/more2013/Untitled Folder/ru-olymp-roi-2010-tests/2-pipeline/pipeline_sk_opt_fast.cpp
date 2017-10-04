#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back

typedef long long ll;

const int maxn = 1000;

int n, m, k, deg[maxn];
vector <int> c[maxn];

int cc = 1, u[maxn];

void add( int v, int x )
{
  forn(i, c[v].size())
    deg[c[v][i]] += x;
}

void go( int dep )
{
  int mi = -1, cnt = 0;
  forn(i, n)
    cnt += !!u[i];
  assert(cnt == dep);
  forn(i, n)
    if (!u[i] && (mi == -1 || deg[mi] < deg[i]))
      mi = i;
  if (mi == -1 || deg[mi] == 0)
  {
    puts("Yes");
    forn(i, n)
      if (!u[i] && dep < k)
        u[i] = -1, dep++;
    forn(i, n)
      if (u[i])
        printf("%d ", i + 1);
    exit(0);
  }

  int e = 0;
  forn(i, n)
    if (!u[i])
      e += deg[i];
  if (2 * deg[mi] * (k - dep) < e)
    return;

  forn(i, n)
    if (!u[i] && deg[i] == 1)
    {
      forn(j, c[i].size())
        if (!u[c[i][j]]) 
          mi = c[i][j];
      u[mi] = 1, add(mi, -1);
      go(dep + 1);
      u[mi] = 0, add(mi, 1);
      return;
    }

  u[mi] = 1, add(mi, -1);
  go(dep + 1);
  u[mi] = 0, add(mi, 1);

  if (dep + deg[mi] <= k)
  {
    int x;
    cc++;
    forn(i, c[mi].size())
      if (u[x = c[mi][i]] == 0)
        u[x] = cc, add(x, -1), dep++;
    go(dep);
    forn(i, c[mi].size())
      if (u[x = c[mi][i]] == cc)
        u[x] = 0, add(x, 1);
    cc--;
  }
}

int main()
{
  freopen("pipeline.in", "r", stdin);
  freopen("pipeline.out", "w", stdout);

  scanf("%d%d%d", &n, &m, &k);
  assert(n <= maxn);
  while (m--)
  {
    int a, b;
    scanf("%d%d", &a, &b), a--, b--;
    c[a].pb(b), c[b].pb(a);
  }
  forn(i, n)
    deg[i] = c[i].size();

  go(0);

  puts("No");
  return 0;
}
