#include "random.h"

#include <cstdio>
#include <cassert>
#include <cstdlib>

const int maxW = 2000;

char a[maxW][maxW];
int w, h, p;

int main( int argc, char *argv[] ) {
  if (argc != 5) {
    fprintf(stderr,
      "parameters: <seed> <h> <w> <%%>\n");
    return -1;
  }
  if (atoi(argv[1]) == 0) {
    initrand(Time());
  } else {
    initrand(atoi(argv[1]));
  }
  h = atoi(argv[2]);
  w = atoi(argv[3]);
  p = atoi(argv[4]);
  int cnt = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cnt += (a[i][j] = ((R(1, 1000) < p)) + '0') == '0';
    }
  }
  if (cnt == 0) {
    a[R(0, h - 1)][R(0, w - 1)] = '0';
  }
  printf("%d %d\n", h, w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      putc(a[i][j], stdout);
    }
    putc('\n', stdout);
  }
  return 0;
}
