#include <stdio.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

FILE *F = NULL;

char s[(int)1e5 + 1];

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
  int w, h;

  while (scanf("%d%d", &h, &w) == 2)
  {
    NewTest();
    fprintf(F, "%d %d\n", h, w);
    while (h--)
    {
      scanf("%s", s);
      fprintf(F, "%s\n", s);
    }
  }

  if (F)
    fclose(F);
  return 0;
}
