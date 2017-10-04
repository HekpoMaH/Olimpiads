#include "../testlib.h"

#include <string>

using namespace std;

const int maxN = 2000;

int h, w;

int main()
{
  registerValidation();
  h = inf.readInt(1, maxN);
  inf.readSpace();
  w = inf.readInt(1, maxN);
  inf.readEoln();

  char pattern[99];
  sprintf(pattern, "[01]{%d}", w);

  int cnt = 0;
  for (int i = 0; i < h; i++)
  {
    string t = inf.readWord(pattern);
    for (int j = 0; j < w; j++) {
      cnt += t[j] == '0';
    }
    inf.readEoln();
  }
  ensure(cnt > 0);
  inf.readEof();
  return 0;
}
