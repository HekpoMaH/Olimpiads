#include <cstdio>
#include <cassert>
#include <cstdlib>

int main( int argc, char *argv[] ) {
  if (argc != 3) {
    fprintf(stderr,
      "parameters: <h> <w>\n");
    return -1;
  }
  int h = atoi(argv[1]);
  int w = atoi(argv[2]);
  printf("%d %d\n", h, w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (i == 0 || i == h - 1) {
        putc('0' + (j & 1), stdout);
      } else if (j == 0 || j == w - 1) {
        putc('0' + (i & 1), stdout);
      } else {
        putc('1', stdout);
      }
    }
    putc('\n', stdout);
  }
  return 0;
}
