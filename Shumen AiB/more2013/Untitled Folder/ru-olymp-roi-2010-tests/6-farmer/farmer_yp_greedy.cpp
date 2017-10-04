#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxN = 2000;

int w, h;
char a[maxN][maxN + 1], b[maxN][maxN + 1];
int x[maxN], s[maxN], sp;
int ai1, ai2, aj1, aj2, asum;

void relax( int i1, int i2, int j1, int j2 ) {
//  fprintf(stderr, "relax %d %d %d %d (asum=%d)\n", i1, i2, j1, j2, asum);
  if (i1 > i2 || j1 > j2 || asum >= (i2 - i1 + 1) * (j2 - j1 + 1)) {
    return;
  }
  asum = (i2 - i1 + 1) * (j2 - j1 + 1);
  ai1 = i1; ai2 = i2; aj1 = j1; aj2 = j2;
}

void solve( char c ) {
  ai1 = ai2 = aj1 = aj2 = asum = -1;
  for (int i = 0; i < w; i++) {
    x[i] = 0;
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] == c) {
        x[j]++;
      } else {
        x[j] = 0;
      }
    }
//    for (int j = 0; j < w; j++) {
//      fprintf(stderr, "%d%c", x[j], " \n"[j + 1 == w]);
//    }
    sp = 0;
    for (int j = 0; j < w; j++) {
//      fprintf(stderr, "j=%d\n", j);
      while (sp > 0 && x[s[sp - 1]] > x[j]) {
        relax(i - x[s[sp - 1]] + 1, i, s[sp - 1], j - 1);
        sp--;
      }
      while (sp > 1 && x[s[sp - 2]] == x[j]) {
        relax(i - x[j] + 1, i, s[sp - 2], j);
        sp--;
      }
      s[sp++] = j;
//      fprintf(stderr, "put %d\n", j);
    }
    while (sp > 0) {
      relax(i - x[s[sp - 1]] + 1, i, s[sp - 1], w - 1);
      sp--;
    }
  }
}

void patch( int i1, int i2, int j1, int j2 ) {
  int bi1 = i2 + 1, bi2 = i1 - 1, bj1 = j2 + 1, bj2 = j1 - 1;
  for (int i = i1; i <= i2; i++) {
    for (int j = j1; j <= j2; j++) {
      if (b[i][j] == '0') {
        bi1 = min(bi1, i);
        bi2 = max(bi2, i);
        bj1 = min(bj1, j);
        bj2 = max(bj2, j);
      }
    }
  }
  if (bi1 > bi2) {
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (b[i][j] == '0') {
          printf("%d %d %d %d\n", i + 1, j + 1, i + 1, j + 1);
          return;
        }
      }
    }
    assert(false);
  } else {
    printf("%d %d %d %d\n", bi1 + 1, bj1 + 1, bi2 + 1, bj2 + 1);
  }
}

int main() {
  freopen("farmer.in", "r", stdin);
  freopen("farmer.out", "w", stdout);

  scanf("%d%d", &h, &w);
  for (int i = 0; i < h; i++) {
    scanf("%s", a[i]);
    strcpy(b[i], a[i]);
  }
  solve('0');
  assert(asum > 0);
  for (int i = ai1; i <= ai2; i++) {
    for (int j = aj1; j <= aj2; j++) {
      a[i][j] = '1';
    }
  }
  solve('1');
  assert(asum > 0);
  patch(ai1, ai2, aj1, aj2);
  printf("%d %d %d %d\n", ai1 + 1, aj1 + 1, ai2 + 1, aj2 + 1);
  printf("%d\n", asum);

  return 0;
}
