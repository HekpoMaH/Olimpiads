/*
PROGRAM NAME: roses
AUTHOR: Evgenii Vassilev
*/
#include <cstdio>
int A[1001][1001], m, n, k, maxsave, s, i, j;
int main(){
  scanf("%d %d %d",&m, &n, &k);
  for (i=1; i<=m; i++) for(j=1; j<=n; j++){
    scanf("%d",&A[i][j]);
    A[i][j] += A[i-1][j] - A[i-1][j-1] + A[i][j-1];
  }
  for(i=1;i<=m;i++)
  {
      for(j=1;j<=n;j++)
      {
          printf("%d ",A[i][j]);
      }
      printf("\n");
  }
  for (i=k; i<=m; i++) for(j=k; j<=n; j++)
    if ((s = A[i][j] - A[i-k][j] + A[i-k][j-k] - A[i][j-k]) > maxsave) maxsave = s;

  printf("%d\n",A[m][n]-maxsave);
  return 0;
}
