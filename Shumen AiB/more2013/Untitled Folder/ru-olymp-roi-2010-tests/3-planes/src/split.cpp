#include <stdio.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

FILE *F = NULL;

void NewTest()
{
  int static cnt = 0;
  char buf[99];

  do
  {
    if (F)
      fclose(F);
    cnt++;
    sprintf(buf, "%02d.tmp", cnt);
    F = fopen(buf, "rt");
  } while (F);

  sprintf(buf, "%02d.tmp", cnt);
  F = fopen(buf, "wt");
}

int main()
{
  int n, m, k;

  while (scanf("%d%d%d", &n, &m, &k) == 3)
  {
    NewTest();
    fprintf(F, "%d %d %d\n", n, m, k);
    while (n--)
    {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      fprintf(F, "%d %d %d\n", a, b, c);
    }
  }

  if (F)
    fclose(F);
  return 0;
}
