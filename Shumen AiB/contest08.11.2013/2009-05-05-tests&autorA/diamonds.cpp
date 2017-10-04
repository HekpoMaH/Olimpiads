/*
TASK: diamonds
LANG: C++
*/
#include <cstdio>
#define MAXN 101

int a[MAXN][MAXN][MAXN];

int main() {
  int i, j, k, L, M, N, x1, y1, z1, x2, y2, z2;

  scanf("%d %d %d",&L, &M, &N);
  for (i=1; i<=N; i++) for (j=1; j<=M; j++) for (k=1; k<=L; k++){
    scanf("%d",&a[i][j][k]);
    a[i][j][k] += a[i][j][k-1] - a[i][j-1][k-1] + a[i][j-1][k] -
                  a[i-1][j][k-1] + a[i-1][j][k] - a[i-1][j-1][k] + a[i-1][j-1][k-1];
  }

  while (scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2)==6)
    printf ("%d\n",a[z2][y2][x2] - a[z2][y2][x1] - a[z2][y1][x2] + a[z2][y1][x1] -
                   a[z1][y2][x2] + a[z1][y2][x1] - a[z1][y1][x1] + a[z1][y1][x2]);
  return 0;
}
