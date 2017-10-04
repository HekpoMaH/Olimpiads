#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

const int maxN = 2000;

int w, h;
char a[maxN][maxN + 1], b[maxN][maxN + 1];

int main( int argc, char *argv[] ) {
  if (argc < 3) {
    fprintf(stderr, "parameters: <in> <ans> [mp]\n");
    return -1;
  }
  if (argc > 3) {
    freopen(argv[3], "w", stdout);
  }
  freopen(argv[1], "r", stdin);
  assert(scanf("%d%d", &h, &w) == 2);
  for (int i = 0; i < h; i++) {
    assert(scanf("%s", a[i]) == 1);
    assert(strlen(a[i]) <= maxN);
  }
  freopen(argv[2], "r", stdin);
  int i1, i2, j1, j2;
  assert(scanf("%d%d%d%d", &i1, &j1, &i2, &j2) == 4);
  i1--; i2--; j1--; j2--;
  for (int i = i1; i <= i2; i++) {
    for (int j = j1; j <= j2; j++) {
      if (a[i][j] == '0') {
        a[i][j] = '4';
      } else {
        a[i][j] = '5';
      }
    }
  }
  assert(scanf("%d%d%d%d", &i1, &j1, &i2, &j2) == 4);
  i1--; i2--; j1--; j2--;
  for (int i = i1; i <= i2; i++) {
    for (int j = j1; j <= j2; j++) {
      if (a[i][j] == '0' || a[i][j] == '4') {
        a[i][j] = '2';
      } else {
        a[i][j] = '3';
      }
    }
  }
  if (w * h > 10000) {
    int t = 1;
    while ((w / t) * (h / t) > 10000) {
      t++;
    }
    for (int i = 0; i < h; i++) {
      strcpy(b[i], a[i]);
    }
    for (int i = 0; i < h / t; i++) {
      for (int j = 0; j < w / t; j++) {
        bool is[6] = {false, false, false, false, false, false};
        int sum = 0;
        for (int ii = 0; ii < t; ii++) {
          for (int jj = 0; jj < t; jj++) {
            is[b[i * t + ii][j * t + jj] - '0'] = true;
          }
        }
        if (is[2]) {
          a[i][j] = '2';
        } else if (is[3]) {
          a[i][j] = '3';
        } else if (is[0] && is[1]) {
          a[i][j] = '4';
        } else if (is[0]) {
          a[i][j] = '0';
        } else if (is[1]) {
          a[i][j] = '1';
        } else {
          assert(false);
        }
      }
    }
    h /= t, w /= t;
  }
  double ww = 170;
  printf("beginfig(1);\n");
  printf("m := %.5lfmm;\n", min(ww / w, ww / h));
  printf("def p(expr A, col) =\n");
  printf(" draw (m*A)--(m*A) withpen pencircle scaled m withcolor col;\n");
  printf("enddef;\n");
  printf("def a(expr A) = p(A, (1, 1, 1)); enddef;\n");
  printf("def b(expr A) = p(A, (0, 0, 0)); enddef;\n");
  printf("def c(expr A) = p(A, (0, 1, 0)); enddef;\n");
  printf("def d(expr A) = p(A, (1, 0, 1)); enddef;\n");
  printf("def e(expr A) = p(A, (0.7, 0.7, 0.7)); enddef;\n");
  printf("def f(expr A) = p(A, (0.3, 0.3, 0.3)); enddef;\n");
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      printf("%c((%d,%d));\n", 'a' + a[i][j] - '0', i, j);
    }
  }
  printf("endfig;\n");
  printf("end\n");
  return 0;
}
