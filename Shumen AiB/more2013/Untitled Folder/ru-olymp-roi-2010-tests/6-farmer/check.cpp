#define NOFOOTER

#include "testlib.h"

#include <string>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
                    
#define CHECK(f, a) { if (!(a)) quitf(f, #a); }
#define ASSERT(a) CHECK(_fail, a)

const int maxn = 2000;

int h, w;
string s[maxn];
string t[maxn];

void readInput( InStream in )
{
  h = in.readInt();
  w = in.readInt();
  if (!(1 <= h && h <= maxn && 1 <= w && w <= maxn))
    quitf(_fail, "w=%d h=%d maxn=%d", w, h, maxn);
  forn(i, h)
  {
    t[i] = in.readWord();
    ASSERT((int)t[i].length() == w);
    forn(j, w)
      ASSERT('0' <= t[i][j] && t[i][j] <= '1');
  }
}

int checkOutput( InStream out, TResult exit_code )
{
  int ly = out.readInt();
  int lx = out.readInt();
  int ry = out.readInt();
  int rx = out.readInt();
  if (!(1 <= lx && lx <= rx && rx <= w) || !(1 <= ly && ly <= ry && ry <= h))
    quitf(exit_code, "Прямоугольник [%d,%d] - [%d,%d] некорректен", lx, ly, rx, ry);

  for (int i = 0; i < h; i++)
    s[i] = t[i];
  ly--; lx--; ry--; rx--;
  for (int y = ly; y <= ry; y++) {
    for (int x = lx; x <= rx; x++) {
      s[y][x] ^= 1;
    }
  }

  ly = out.readInt();
  lx = out.readInt();
  ry = out.readInt();
  rx = out.readInt();
  if (!(1 <= lx && lx <= rx && rx <= w) || !(1 <= ly && ly <= ry && ry <= h))
    quitf(exit_code, "Прямоугольник [%d,%d] - [%d,%d] некорректен", lx, ly, rx, ry);
  ly--; lx--; ry--; rx--;

  for (int y = ly; y <= ry; y++) {
    for (int x = lx; x <= rx; x++) {
      if (s[y][x] == '0') {
        quitf(exit_code, "В позиции (x=%d, y=%d) ответа есть неудобренная клетка.", x + 1, y + 1);
      }
    }
  }

  int sum = out.readInt();
  if (sum != (ry - ly + 1) * (rx - lx + 1)) {
    quitf(exit_code, "Обещанная площадь ответа не совпадает с фактической (%d вместо %d)",
      sum, (ry - ly + 1) * (rx - lx + 1));
  }
  return sum;
}

int main(int argc, char *argv[])
{
  registerTestlibCmd(argc, argv);

  readInput(inf);

  int ja = checkOutput(ans, _fail);
  int ca = checkOutput(ouf, _wa);

  if (ca > ja)
    quitf(_fail, "Участник построил прямоугольник размера %d, Жюри умеет только %d", ca, ja);
  if (ca < ja)
    quitf(_wa, "Участник построил прямоугольник размера %d, Жюри умеет %d", ca, ja);
  quitf(_ok, "OK (w = %d, h = %d, ответ = %d)", w, h, ja);
  return 0;
}
