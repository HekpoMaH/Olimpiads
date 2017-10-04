#include "random.h"

#include <cstdio>
#include <cassert>
#include <cstdlib>

const int maxW = 2000;

char a[maxW][maxW];
int w, h, n;

int main( int argc, char *argv[] ) {
  if (argc != 5) {
    fprintf(stderr,
      "parameters: <seed> <h> <w> <num>\n");
    return -1;
  }
  if (atoi(argv[1]) == 0) {
    initrand(Time());
  } else {
    initrand(atoi(argv[1]));
  }
  h = atoi(argv[2]);
  w = atoi(argv[3]);
  n = atoi(argv[4]);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      a[i][j] = '0';
    }
  }
  for (int t = 0; t < n; t++) {
    int i1 = R(0, h - 1);
    int i2 = R(i1, h - 1);
    int j1 = R(0, w - 1);
    int j2 = R(j1, w - 1);
    char c = R('0', '1');
    for (int i = i1; i <= i2; i++) {
      for (int j = j1; j <= j2; j++) {
        a[i][j] = c;
      }
    }
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
