#include <cstdio>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

const int maxn = 100010;
const int maxt = 1 << 17;

struct segment
{
  int l, r, t;
};

int n, m, k, rn, pn, p[maxn], res[maxn];
segment s[maxn];
ll rest[maxt * 2];
int next[maxn], cnt[maxn];

bool slessR( int i, int j ) { return s[i].r < s[j].r; }
bool slessL( int i, int j ) { return s[i].l < s[j].l; }

void Inc( int x )
{
  for (int i = maxt + x; i > 0; i >>= 1)
    rest[i]--;
}

int Get1( int v, int vl, int vr, int L, int R )
{
  if (vl > R || L > vr || rest[v] == 0)
    return -1;
  if (L <= vl && vr <= R)
  {
    while (v < maxt)
      if (!rest[v *= 2])
        v++;
    return v - maxt;
  }

  int vm = (vl + vr) / 2, res;
  if ((res = Get1(2 * v, vl, vm, L, R)) == -1)
    res = Get1(2 * v + 1, vm + 1, vr, L, R);
  return res;
}

int Get2( int v, int vl, int vr, int L, int R )
{
  if (vl > R || L > vr || rest[v] == 0)
    return -1;
  if (L <= vl && vr <= R)
  {
    while (v < maxt)
      if (!rest[v = v * 2 + 1])
        v--;
    return v - maxt;
  }

  int vm = (vl + vr) / 2, res;
  if ((res = Get2(2 * v + 1, vm + 1, vr, L, R)) == -1)
    res = Get2(2 * v, vl, vm, L, R);
  return res;
}

int main()
{
  freopen("planes.in", "r", stdin);
  freopen("planes.out", "w", stdout);

  scanf("%d%d%d", &n, &m, &k);
  forn(i, n)
    scanf("%d%d%d", &s[i].l, &s[i].r, &s[i].t);
  for (int i = 1; i <= m; i++)
    rest[maxt + i] = k;
  for (int i = maxt - 1; i > 0; i--)
    rest[i] = rest[i * 2] + rest[i * 2 + 1];

  forn(t, 2)
  {
    pn = 0;
    forn(i, n)
      if (s[i].t != t)
        p[pn++] = i;
    if (!t)
      sort(p, p + pn, slessR);
    else
    {
      sort(p, p + pn, slessL);
      reverse(p, p + pn);
    }

    int x;
    forn(i, pn)
    {
      if (!t)
        x = Get1(1, 0, maxt - 1, s[p[i]].l, s[p[i]].r);
      else
        x = Get2(1, 0, maxt - 1, s[p[i]].l, s[p[i]].r);
      if (x != -1)
        rn++, res[p[i]] = x, Inc(x);
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
