#include <stdio.h>
#define MAXN 200/* Максимален брой върхове в графа */
const unsigned n = 6;/* Брой върхове в графа */

const char A[MAXN][MAXN] = {/* Матрица на съседство на графа */
  { 0, 1, 1, 0, 0, 0 },
  { 1, 0, 1, 0, 0, 0 },
  { 1, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 1 },
  { 0, 0, 0, 1, 0, 1 },
  { 0, 0, 0, 1, 1, 0 }
};
char used[MAXN];

void DFS(unsigned i)/* модифицирано DFS */
{ unsigned k;
  used[i] = 1;
  printf("%u ", i + 1);
  for (k = 0; k < n; k++)
    if (A[i][k] && !used[k]) DFS(k);
}

int main(void)
{ unsigned i, comp;
  for (i = 0; i < n; i++) used[i] = 0;/* инициализация */
  printf("\nVsichki komponenti na swyrzanost: \n");
  comp = 0;
  for (i = 0; i < n; i++)
    if (!used[i]) {
      comp++;
      printf("{ ");
      DFS(i);
      printf("}\n");
    }
  if (1 == comp)
    printf("Grafyt e swyrzan.\n");
  else
    printf("Broj swyrzani komponenti: %d \n", comp);
  return 0;
}
