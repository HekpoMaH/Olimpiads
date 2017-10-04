#include "../testlib.h"

const int maxN = 100000;
const int maxM = 100000;
const int maxK = 100000;

int n, m, k;

int main() {
  registerValidation();
  n = inf.readInt(1, maxN);
  inf.readSpace();
  m = inf.readInt(1, maxM);
  inf.readSpace();
  k = inf.readInt(1, maxK);
  inf.readEoln();
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int l, r, c;
    l = inf.readInt(1, m);
    inf.readSpace();
    r = inf.readInt(l, m);
    inf.readSpace();
    c = inf.readInt(0, 1);
    inf.readEoln();
    if (c == 1) {
      cnt++;
    }
  }
  ensure(cnt >= 1);
  return 0;
}
