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
      putc('0' + ((i == 0 || i == h - 1) && (j == 0 || j == h - 1)), stdout);
    }
    putc('\n', stdout);
  }
  return 0;
}
