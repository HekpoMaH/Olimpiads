#define NOFOOTER

#include "testlib.h"
#include <algorithm>
#include <map>

using namespace std;

const int MAXN = 100000;

int l[MAXN];
int r[MAXN];
int n, m, k;
int tp[MAXN];

int checkRes( InStream fin, TResult ret ) {
  map <int, int> cnt;
  int pans, ans = 0;
  pans = fin.readInt();
  if (pans == 0) {
    return -1;
  }
  for (int i = 0; i < n; i++) {
    int cur = fin.readInt();
    if (cur == 0) {
      if (tp[i] == 1) {
        quitf(ret, "Пассажир %d должен отправиться на РОИ", i + 1);
      }
    } else {
      if (cur < l[i]  || cur > r[i]) {
        quitf(ret, "Пассажир %d не может отправиться в день %d, только в интервале [%d..%d]", i + 1, cur, l[i], r[i]);
      }
      if (cnt[cur] >= k) {
        quitf(ret, "Самолет в день %d переполнен", cur);
      }
      cnt[cur]++;
      ans++;
    }
  }
  if (ans != pans) {
    quitf(ret, "Обещано %d оправленных пассажиров, а на самом деле %d", pans, ans);
  }
  return ans;
}

int main(int argc, char **argv) {
  registerTestlibCmd(argc, argv);
  n = inf.readInt();
  m = inf.readInt();
  k = inf.readInt();
  for (int i = 0; i < n; i++) {
    l[i] = inf.readInt();
    r[i] = inf.readInt();
    tp[i] = inf.readInt();
  }
  int jans = checkRes(ans, _fail);
  int pans = checkRes(ouf, _wa);
  if (jans == -1) {
    if (pans != -1) {
      quitf(_fail, "Участник нашел ответ, а жюри - нет");
    } else {
      quitf(_ok, "Нет решения");
    }
  } else {
    if (pans == -1) {
      quitf(_wa, "Участник не нашел решение, хотя оно существует");
    } else if (pans > jans) {
      quitf(_fail, "Жюри может отправить %d пассажиров, в то время как участник может %d", jans, pans);
    } else if (pans < jans) {
      quitf(_wa, "Можно отправить %d пассажиров, а участник смог только %d", jans, pans);
    } else {
      quitf(_ok, "%d пассажиров отправлено", pans);
    }
  }
  return -1;
}
