#include <cstdio>
#include <cassert>
#include <cstdlib>

int main( int argc, char *argv[] ) {
  if (argc != 6) {
    fprintf(stderr,
      "parameters: <h> <w> <top-left corner> <cellh> <cellw>\n");
    return -1;
  }
  int h = atoi(argv[1]);
  int w = atoi(argv[2]);
  int c = atoi(argv[3]);
  int ch = atoi(argv[4]);
  int cw = atoi(argv[5]);
  printf("%d %d\n", h, w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      putc('0' + ((c + i / ch + j / cw) & 1), stdout);
    }
    putc('\n', stdout);
  }
  return 0;
}
