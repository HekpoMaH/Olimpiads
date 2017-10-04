#include <cstdio>
#include <algorithm>

using namespace std;

int cnt, cnt1, cnt2, cnt3, cnt4;

int main()
{
  int k = 0;

  while (1)
  {
    k++;

    char buf[99];
    sprintf(buf, "tests/%02d", k);

    FILE *F = fopen(buf, "rt");
    if (!F)
      break;
    int n, m, k;
    fscanf(F, "%d%d%d", &n, &m, &k);
    if (max(n, max(m, k)) <= (int)1e1) cnt1++;
    if (max(n, max(m, k)) <= (int)1e2) cnt2++;
    if (max(n, max(m, k)) <= (int)1e3) cnt3++;
    if (max(n, max(m, k)) <= (int)1e4) cnt4++;
    cnt++;
    fclose(F);
  }
  printf("%d tests : %d, %d, %d, %d\n", cnt, cnt1, cnt2, cnt3, cnt4);
  return 0;
}
