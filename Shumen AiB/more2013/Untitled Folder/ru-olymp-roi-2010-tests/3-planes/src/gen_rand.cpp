#include "random.h"

#include <cassert>
#include <cstdlib>
#include <cstdio>

const int mamN = 100000;
const int mamX = 100000;

struct plane {
  int l, r, c;
};

int n, m, k;
plane a[mamN];

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
  for (int i = 0; i < n; i++) {
    a[i].l = R(1, m);
    a[i].r = R(a[i].l, m);
    if (i < q) {
      a[i].c = 1;
    } else {
      a[i].c = 0;
    }
  }
  printf("%d %d %d\n", n, m, k);
  randomShuffle(a, a + n);
  for (int i = 0; i < n; i++) {
    printf("%d %d %d\n", a[i].l, a[i].r, a[i].c);
  }
  return 0;
}
