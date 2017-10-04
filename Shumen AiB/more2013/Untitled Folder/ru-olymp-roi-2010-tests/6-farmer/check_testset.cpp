#include <cstdio>
#include <cassert>

#include <algorithm>

using namespace std;

int cnt, cnt0, cnt1, cnt2, cnt3, cnt4;

int main()
{
  int t = 0;

  while (1)
  {
    t++;

    char buf[99];
    sprintf(buf, "tests/%02d", t);

    FILE *F = fopen(buf, "rt");
    if (!F)
      break;
    int n, m;
    fscanf(F, "%d%d", &n, &m);
    if (2 <= min(n, m) && max(n, m) <= 10) cnt0++;
    else if (20 <= min(n, m) && max(n, m) <= 40) cnt1++;
    else if (60 <= min(n, m) && max(n, m) <= 300) cnt2++;
    else if (500 <= min(n, m) && max(n, m) <= 2000) cnt3++;
    else
    {
      printf("incorrect test: %d (n = %d, m = %d)", t, n, m);
      return 0;
    }
    cnt++;
    fclose(F);
  }
  printf("%d tests : %d, %d, %d, %d\n", cnt, cnt0, cnt1, cnt2, cnt3);
  assert(cnt0 == 5 && cnt1 == 10 && cnt2 == 15 && cnt3 == 20);
  return 0;
}
