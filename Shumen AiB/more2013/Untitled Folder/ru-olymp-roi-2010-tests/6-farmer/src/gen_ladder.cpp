#include "random.h"

#include <cstdio>
#include <cassert>
#include <cstdlib>

const int maxW = 2000;

char a[maxW][maxW];
int w, h, cw, ch;

int main( int argc, char *argv[] ) {
  if (argc != 6) {
    fprintf(stderr,
      "parameters: <seed> <h> <w> <ch> <cw>\n");
    return -1;
  }
  if (atoi(argv[1]) == 0) {
    initrand(Time());
  } else {
    initrand(atoi(argv[1]));
  }
  h = atoi(argv[2]);
  w = atoi(argv[3]);
  ch = atoi(argv[4]);
  cw = atoi(argv[5]);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      a[i][j] = '0';
    }
  }
  int cx = 0, cy = 0;
  while (cx < w && cy < h) {
    for (int y = cy; y < h && y < cy + ch; y++) {
      for (int x = cx; x < w && x < cx + cw; x++) {
        a[y][x] = '1';
      }
    }
    cx += R(1, cw / 2);
    cy += R(1, ch / 2);
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
