#include <cstdio>
#include <cassert>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int maxn = 2010;

int h, w;
char s[maxn][maxn];

int tx1, ty1, tx2, ty2;
int rx1, ry1, rx2, ry2;

int main( int argc, char *argv[] )
{
  if (argc < 3)
  {
    puts("Usage: <input> <output>");
    return 0;
  }

  FILE *In = fopen(argv[1], "rt");
  FILE *Out = fopen(argv[2], "rt");

  assert(In && Out);

  fscanf(In, "%d%d", &h, &w);
  forn(i, h)
    fscanf(In, "%s", s[i]);

  fscanf(Out, "%d%d%d%d", &ty1, &tx1, &ty2, &tx2), tx1--, ty1--, tx2--, ty2--;
  fscanf(Out, "%d%d%d%d", &ry1, &rx1, &ry2, &rx2), rx1--, ry1--, rx2--, ry2--;

  for (int y = ty1; y <= ty2; y++)
    for (int x = tx1; x <= tx2; x++)
      if (s[y][x] == '0')
        s[y][x] = '2';
      else 
        s[y][x] = '*';
  forn(i, h)
    forn(j, w)
      if ((i == ry1 - 1 || i == ry2 + 1) && (rx1 - 1 <= j && j <= rx2 + 1) || 
          (j == rx1 - 1 || j == rx2 + 1) && (ry1 - 1 <= i && i <= ry2 + 1))
        s[i][j] = ' ';
  forn(i, h)
    puts(s[i]);

  fclose(In);
  fclose(Out);
  return 0;
}
