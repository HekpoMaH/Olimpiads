#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

struct evt {
  static const int tAdd = 0;
  static const int tMerge = 1;
  static const int tBlack = 2;

  int type, i, j;
  evt() {}
  evt( int _type, int _i, int _j ): type(_type), i(_i), j(_j) {}
};

struct row {
  static const int sNone = 0;
  static const int sBlack = 1;
  static const int sWhite = 2;

  int pr, ne;
  int l, r;
  int state;
};

const int maxN = 2000;

int w, h;
char a[maxN][maxN + 1];
int ne[maxN][maxN], x[maxN], y[maxN], z[maxN];
int ai1, ai2, aj1, aj2, asum;
int k[maxN + 1];
evt e[maxN + 1][maxN * 3];
row r[maxN];
int c[maxN * 6], nu;
int g[maxN];

inline void relax( int i1, int i2, int j1, int j2 ) {
  if (i1 > i2 || j1 > j2 || asum >= (i2 - i1 + 1) * (j2 - j1 + 1)) {
    return;
  }
  asum = (i2 - i1 + 1) * (j2 - j1 + 1);
  ai1 = i1; ai2 = i2; aj1 = j1; aj2 = j2;
}

inline void relaxRow( int i1, int i2, int j ) {
  int j1, j2;
  if (r[j].pr != -1 && r[r[j].pr].state == row::sBlack) {
    j1 = r[r[j].pr].l;
  } else {
    j1 = r[j].l;
  }
  if (r[j].ne != -1 && r[r[j].ne].state == row::sBlack) {
    j2 = r[r[j].ne].r;
  } else {
    j2 = r[j].r;
  }
  relax(i1, i2, j1, j2);
}

inline void addEvt( evt t ) {
  e[t.i][k[t.i]++] = t;
}

inline void join( int i, int j ) {
  if (i == j) {
    return;
  }
  assert(r[i].ne == j);
  assert(r[j].pr == i);
  r[i].ne = r[j].ne;
  if (r[i].ne != -1) {
    r[r[i].ne].pr = i;
  }
  r[i].r = r[j].r;
  r[j].state = row::sNone;
  g[r[j].l] = g[r[j].r] = -1;
  g[r[i].l] = g[r[i].r] = i;
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
    for (int i = st; i <= h; i++) {
      k[i] = 0;
    }

    for (int i = 0; i < w; i++) {
      x[i] = (a[st][i] == '0') ? st : ne[st][i];
      y[i] = (x[i] == h) ? h : ne[x[i]][i];
      z[i] = (y[i] == h) ? h : ne[y[i]][i];
      r[i].l = r[i].r = i;
      r[i].state = row::sNone;
      r[i].pr = (i > 0) ? i - 1 : -1;
      r[i].ne = (i + 1 < w) ? i + 1 : -1;
      g[i] = i;
    }

    for (int i = 0; i < w; i++) {
      addEvt(evt(evt::tAdd, z[i], i));
      if (i + 1 < w) {
        if (x[i] == x[i + 1] && y[i] == y[i + 1]) {
          addEvt(evt(evt::tMerge, min(z[i], z[i + 1]), i));
        } else if (x[i] == x[i + 1]) {
          addEvt(evt(evt::tMerge, min(y[i], y[i + 1]), i));
        } else {
          addEvt(evt(evt::tMerge, min(x[i], x[i + 1]), i));
        }
      }
      addEvt(evt(evt::tBlack, x[i], i));
    }

    for (int i = h; i > st; i--) {
      nu = 0;
      for (int j = 0; j < k[i]; j++) {
        evt &t = e[i][j];
        int pos = g[t.j];
        row &tr = r[pos];
        if (pos == -1) {
          continue;
        }
        if (t.type == evt::tAdd) {
          tr.state = row::sWhite;
        } else if (t.type == evt::tMerge) {
          join(pos, tr.ne);
        } else if (t.type == evt::tBlack) {
          tr.state = row::sBlack;
        }
        row &tt = r[pos];
        if (tt.state == row::sBlack) {
          if (tt.pr != -1) {
            c[nu++] = tt.pr;
          }
          if (tt.ne != -1) {
            c[nu++] = tt.ne;
          }
          if (tt.pr == -1 && tt.ne == -1) {
            c[nu++] = pos;
          }
        } else if (tt.state == row::sWhite) {
          c[nu++] = pos;
        }
      }
      for (int j = 0; j < nu; j++) {
        int id = c[j];
        if (g[id] == -1) {
          continue;
        }
        id = g[id];
        if (r[id].state == row::sBlack) {
          relax(st, i - 1, r[id].l, r[id].r);
        } else if (r[id].state == row::sWhite) {
          relaxRow(st, i - 1, id);
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
