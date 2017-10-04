#include <cstdio>
#include <cassert>
#include <cstdlib>

int main( int argc, char *argv[] ) {
  if (argc != 6) {
    fprintf(stderr,
      "parameters: <h> <w> <top> <bot> <toothw>\n");
    return -1;
  }
  int h = atoi(argv[1]);
  int w = atoi(argv[2]);
  int top = atoi(argv[3]);
  int bot = atoi(argv[4]);
  int tw = atoi(argv[5]);
  printf("%d %d\n", h, w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (i < top) {
        putc('0', stdout);
      } else if (i >= h - bot) {
        putc('1', stdout);
      } else {
        putc('0' + ((j / tw) & 1), stdout);
      }
    }
    putc('\n', stdout);
  }
  return 0;
}
