#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

const int maxN = 2000;

int w, h;
char a[maxN][maxN + 1];
int ai1, ai2, aj1, aj2, asum;

inline void relax( int i1, int i2, int j1, int j2 ) {
  if (i1 > i2 || j1 > j2 || asum >= (i2 - i1 + 1) * (j2 - j1 + 1)) {
    return;
  }
  asum = (i2 - i1 + 1) * (j2 - j1 + 1);
  ai1 = i1; ai2 = i2; aj1 = j1; aj2 = j2;
}

void patch( int i1, int i2, int j1, int j2 ) {
  int bi1 = i2 + 1, bi2 = i1 - 1, bj1 = j2 + 1, bj2 = j1 - 1;
  for (int i = i1; i <= i2; i++) {
    for (int j = j1; j <= j2; j++) {
      if (a[i][j] == '0') {
        bi1 = min(bi1, i);
        bi2 = max(bi2, i);
        bj1 = min(bj1, j);
        bj2 = max(bj2, j);
      }
    }
  }
  if (bi1 > i2) {
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (a[i][j] == '0') {
          printf("%d %d %d %d\n", i + 1, j + 1, i + 1, j + 1);
          return;
        }
      }
    }
  } else {
    printf("%d %d %d %d\n", bi1 + 1, bj1 + 1, bi2 + 1, bj2 + 1);
  }
}

void doXor( int i1, int i2, int j1, int j2 ) {
  for (int i = i1; i <= i2; i++) {
    for (int j = j1; j <= j2; j++) {
      if (a[i][j] == '0') {
        a[i][j] = '1';
      } else {
        a[i][j] = '0';
      }
    }
  }
}

void check() {
  for (int i1 = 0; i1 < h; i1++) {
    for (int i2 = i1; i2 < h; i2++) {
      for (int j1 = 0; j1 < h; j1++) {
        for (int j2 = j1; j2 < h; j2++) {
          bool ok = true;
          for (int i = i1; i <= i2; i++) {
            for (int j = j1; j <= j2; j++) {
              if (a[i][j] == '0') {
                ok = false;
              }
            }
          }
          if (ok) {
            relax(i1, i2, j1, j2);
          }
        }
      }
    }
  }
}

int main() {
  freopen("farmer.in", "r", stdin);
  freopen("farmer.out", "w", stdout);

  scanf("%d%d", &h, &w);
  for (int i = 0; i < h; i++) {
    scanf("%s", a[i]);
  }
  int cnt = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cnt += a[i][j] == '0';
    }
  }
  assert(cnt > 0 && cnt < w * h);
  ai1 = ai2 = aj1 = aj2 = asum = -1;
  for (int i1 = 0; i1 < h; i1++) {
    for (int i2 = i1; i2 < h; i2++) {
      for (int j1 = 0; j1 < h; j1++) {
        for (int j2 = j1; j2 < h; j2++) {
          doXor(i1, i2, j1, j2);
          check();
          doXor(i1, i2, j1, j2);
        }
      }
    }
  }
  assert(asum > 0);
  patch(ai1, ai2, aj1, aj2);
  printf("%d %d %d %d\n", ai1 + 1, aj1 + 1, ai2 + 1, aj2 + 1);
  printf("%d\n", asum);

  return 0;
}
