#include <cstdio>
#include <cstring>
#include <cassert>

const int maxN = 100000;
const int maxX = 100000;
const int maxV = 1000000;

struct plane {
  int l, r, c;
};

int n, m, k;
plane a[maxN];
int ans, res[maxN];
int ma[maxV];
bool u[maxN];

bool dfs( int v ) {
  u[v] = true;
  for (int i = a[v].l; i <= a[v].r; i++) {
    for (int j = 0; j < k; j++) {
      int w = i * k + j;
      if (ma[w] == -1 || (!u[ma[w]] && dfs(ma[w]))) {
        ma[w] = v;
        res[v] = i;
        return true;
      }
    }
  }
  return false;
}

int main() {
  freopen("planes.in", "r", stdin);
  freopen("planes.out", "w", stdout);

  assert(scanf("%d%d%d", &n, &m, &k) == 3);
  assert(1 <= n && n <= maxN);
  assert(1 <= m && m <= maxX);
  assert(1 <= k && k <= maxN);
  for (int i = 0; i < n; i++) {
    assert(scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].c) == 3);
    assert(0 <= a[i].l && a[i].l <= a[i].r && a[i].r <= m);
    a[i].l--; a[i].r--;
    assert(a[i].c == 0 || a[i].c == 1);
  }
  assert((long long)m * k <= maxV);
  ans = 0;
  for (int i = 0; i < m * k; i++) {
    ma[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    if (a[i].c == 1) {
      memset(u, false, sizeof(u));
      if (!dfs(i)) {
        printf("0\n");
        return 0;
      }
      ans++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i].c == 0) {
      memset(u, false, sizeof(u));
      if (dfs(i)) {
        ans++;
      } else {
        res[i] = -1;
      }
    }
  }
  if (ans == -1) printf("0\n");
  else printf("%d\n", ans);
  if (ans != -1) {
    for (int i = 0; i < n; i++) {
      printf("%d%c", res[i] + 1, " \n"[i + 1 == n]);
    }
  }

  return 0;
}
