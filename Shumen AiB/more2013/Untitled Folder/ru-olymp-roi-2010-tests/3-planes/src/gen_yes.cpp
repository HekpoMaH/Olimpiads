#include "random.h"

#include <cassert>
#include <cstdlib>
#include <cstdio>

const int maxN = 100000;
const int maxX = 100000;
const int maxNpl = maxX * 5;

struct plane {
  int l, r, c;
};

int n, m, k;
plane a[maxN];
int t[maxNpl];
int cnt[maxX];

int main( int argc, char *argv[] ) {
  if (argc != 6) {
    printf("args: <randseed> <n> <m> <k> <# of ROI participants>\n");
    return -1;
  }
  if (atoi(argv[1]) == 0) {
    initrand(Time());
  } else {
    initrand(atoi(argv[1]));
  }
  n = atoi(argv[2]);
  m = atoi(argv[3]);
  k = atoi(argv[4]);
  int q;
  q = atoi(argv[5]);
  long long npl = (long long)k * m;
  assert(npl >= q);
  if (npl <= maxNpl) {
    for (int i = 0; i < m * k; i++) {
      t[i] = i / k + 1;
    }
    randomShuffle(t, t + m);
    for (int i = 0; i < q; i++) {
      a[i].l = R(1, t[i]);
      a[i].r = R(t[i], m);
      a[i].c = 1;
    }
  } else {
    for (int i = 0; i < m; i++) {
      cnt[i] = 0;
    }
    for (int i = 0; i < q; i++) {
      int pos;
      do {
        pos = R(1, m);
      } while (cnt[pos - 1] >= k);
      cnt[pos - 1]++;
      a[i].l = R(1, pos);
      a[i].r = R(pos, m);
      a[i].c = 1;
    }
  }
  for (int i = q; i < n; i++) {
    a[i].l = R(1, m);
    a[i].r = R(a[i].l, m);
    a[i].c = 0;
  }
  printf("%d %d %d\n", n, m, k);
  randomShuffle(a, a + n);
  for (int i = 0; i < n; i++) {
    printf("%d %d %d\n", a[i].l, a[i].r, a[i].c);
  }
  return 0;
}
