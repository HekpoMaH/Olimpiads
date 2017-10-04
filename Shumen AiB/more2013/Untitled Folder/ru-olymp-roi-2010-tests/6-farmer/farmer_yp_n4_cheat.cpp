#include <cstdio>
#include <ctime>
#include <cassert>
#include <algorithm>

using namespace std;

const int maxN = 2000;

int w, h;
char a[maxN][maxN + 1];
short ne[maxN][maxN], x[maxN], y[maxN], z[maxN];
int ai1, ai2, aj1, aj2, asum;

void relax( int i1, int i2, int j1, int j2 ) {
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

int main() {
  int stTime = clock();
  freopen("farmer.in", "r", stdin);
  freopen("farmer.out", "w", stdout);

  scanf("%d%d", &h, &w);
  for (int i = 0; i < h; i++) {
    scanf("%s", a[i]);
  }
  for (int i = h - 1; i >= 0; i--) {
    for (int j = 0; j < w; j++) {
      if (i == h - 1) {
        ne[i][j] = h;
      } else if (a[i][j] != a[i + 1][j]) {
        ne[i][j] = i + 1;
      } else {
        ne[i][j] = ne[i + 1][j];
      }
    }
  }
  ai1 = aj1 = ai2 = aj2 = -1;
  asum = 0;
  for (int st = 0; st < h; st++) {
    if (clock() - stTime > 1.8 * CLOCKS_PER_SEC) {
      break;
    }
    for (int i = 0; i < w; i++) {
      x[i] = (a[st][i] == '0') ? st : ne[st][i];
      y[i] = (x[i] == h) ? h : ne[x[i]][i];
      z[i] = (y[i] == h) ? h : ne[y[i]][i];
    }
    for (int en = st; en < h; en++) {
      if (clock() - stTime > 1.8 * CLOCKS_PER_SEC) {
        break;
      }
      for (int l = 0; l < w; l++) {
        if (l > 0 && x[l - 1] > en) {
          continue;
        }
        if ((w - l) * (en - st + 1) <= asum) {
          break;
        }
        int state = 0;
        for (int r = l; r < w; r++) {
          if (state == 0) {
            if (x[r] <= en) {
              if (z[r] <= en) {
                break;
              } else {
                state = 1;
              }
            }
          } else if (state == 1) {
            if (x[r] > en) {
              state = 2;
            } else if (x[r] != x[r - 1] || !((y[r - 1] > en && y[r] > en) || (y[r - 1] == y[r] && z[r] > en))) {
              break;
            }
          } else if (state == 2) {
            if (x[r] <= en) {
              break;
            }
          }
          relax(st, en, l, r);
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
