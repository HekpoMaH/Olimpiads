#include "random.h"

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxW = 2000;

char a[maxW][maxW];
int w, h;

int sqr( int a ) {
  return a * a;
}

int main( int argc, char *argv[] ) {
  if (argc != 4) {
    fprintf(stderr,
      "parameters: <seed> <h> <w>\n");
    return -1;
  }
  if (atoi(argv[1]) == 0) {
    initrand(Time());
  } else {
    initrand(atoi(argv[1]));
  }
  h = atoi(argv[2]);
  w = atoi(argv[3]);
  int r = min(w, h) / 2;
  printf("%d %d\n", h, w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int t;
      if (i < h / 2 && j < w / 2) {
        if (sqr(i - h / 2) + sqr(j - w / 2) < sqr(r)) {
          t = 1;
        } else {
          t = (R(1, 100) <= 50);
        }
      } else if (i >= h / 2 && j >= w / 2) {
        if (sqr(i - h / 2) + sqr(j - w / 2) < sqr(r)) {
          t = 0;
        } else {
          t = (R(1, 100) <= 50);
        }
      } else {
        t = 1;
      }
      putc('0' + t, stdout);
    }
    putc('\n', stdout);
  }
  return 0;
}
