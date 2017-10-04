#include "random.h"

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxW = 2000;

char a[maxW][maxW];
int w, h, cw, ch, n;

int main( int argc, char *argv[] ) {
  if (argc != 7) {
    fprintf(stderr,
      "parameters: <seed> <h> <w> <ch> <cw> <n>\n");
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
  n = atoi(argv[6]);
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
  for (int i = 0; i < n; i++) {
    int y1 = R(0, h - 1);
    int y2 = R(y1, min(h - 1, y1 + h / 10));
    int x1 = R(0, w - 1);
    int x2 = R(x1, min(w - 1, x1 + w / 10));
    for (int y = y1; y <= y2; y++) {
      for (int x = x1; x <= x2; x++) {
        if (a[y][x] == '0') {
          a[y][x] = '1';
        } else {
          a[y][x] = '0';
        }
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
