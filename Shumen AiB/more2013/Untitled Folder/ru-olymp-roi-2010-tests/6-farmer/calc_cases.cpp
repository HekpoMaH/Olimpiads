#include <cstdio>
#include <cassert>

#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int maxn = 2010;

int cnt, cnt0, cnt1, cnt2, cnt3;

int main()
{
  int t = 0;

  while (1)
  {
    t++;

    char buf[99];
    sprintf(buf, "tests/%02d.a", t);

    FILE *F = fopen(buf, "rt");
    if (!F)
      break;

    int a[2][4];
    forn(i, 2)
      forn(j, 4)
        assert(fscanf(F, "%d", &a[i][j]) == 1);

    int k1 = (a[0][0] == a[1][0]) + (a[0][2] == a[1][2]);
    int k2 = (a[0][1] == a[1][1]) + (a[0][3] == a[1][3]);

    cnt++;
    if (k1 == 1 && k2 == 1)
      cnt0++;
    else if (k1 + k2 == 1)
      cnt1++;
    else if (k1 + k2 == 0)
      cnt2++;
    else
      cnt3++;
    fclose(F);
  }

  printf("%d tests: %d coner, %d side, %d inside, %d throw\n", cnt, cnt0, cnt1, cnt2, cnt3);
  return 0;
}
