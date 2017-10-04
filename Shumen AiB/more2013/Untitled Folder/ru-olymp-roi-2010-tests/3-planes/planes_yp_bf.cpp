#include <cstdio>
#include <cassert>

const int maxN = 100000;
const int maxX = 100000;

struct plane {
  int l, r, c;
};

int n, m, k;
plane a[maxN];
int ans, res[maxN];
int cur, pos[maxN];
int left[maxX];

void search( int i ) {
  if (i == n) {
    if (cur > ans) {
      ans = cur;
      for (int i = 0; i < n; i++) {
        res[i] = pos[i];
      }
    }
    return;
  }
  if (a[i].c == 0) {
    pos[i] = -1;
    search(i + 1);
  }
  for (pos[i] = a[i].l; pos[i] <= a[i].r; pos[i]++) {
    if (left[pos[i]] == 0) {
      continue;
    }
    left[pos[i]]--;
    cur++;
    search(i + 1);
    cur--;
    left[pos[i]]++;
  }
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
  ans = -1;
  for (int i = 0; i <= m; i++) {
    left[i] = k;
  }
  cur = 0;
  search(0);
  if (ans == -1) printf("0\n");
  else printf("%d\n", ans);
  if (ans != -1) {
    for (int i = 0; i < n; i++) {
      printf("%d%c", res[i] + 1, " \n"[i + 1 == n]);
    }
  }

  return 0;
}
