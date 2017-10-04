#include "random.h"

#include <cstdio>
#include <cassert>
#include <cstdlib>

const int maxW = 2000;

char a[maxW][maxW];
int w, h, p;

void fill( int i1, int i2, int j1, int j2, int c, int l ) {
  if (i2 - i1 > 1 && j2 - j1 > 1 && (l < 2 || R(1, 100) <= p)) {
    int i3 = (i1 + i2) / 2;
    int j3 = (j1 + j2) / 2;
    fill(i1, i3, j1, j3, c, l + 1);
    fill(i3, i2, j1, j3, 1 - c, l + 1);
    fill(i1, i3, j3, j2, 1 - c, l + 1);
    fill(i3, i2, j3, j2, c, l + 1);
  } else {
    for (int i = i1; i < i2; i++) {
      for (int j = j1; j < j2; j++) {
        a[i][j] = '0' + c;
      }
    }
  }
}

int main( int argc, char *argv[] ) {
  if (argc != 5) {
    fprintf(stderr,
      "parameters: <seed> <h> <w> <perc>\n");
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
  fill(0, h, 0, w, 0, 0);
  printf("%d %d\n", h, w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      putc(a[i][j], stdout);
    }
    putc('\n', stdout);
  }
  return 0;
}
