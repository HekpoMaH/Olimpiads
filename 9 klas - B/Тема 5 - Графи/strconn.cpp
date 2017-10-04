#include <stdio.h>
#define MAXN 150/* Максимален брой върхове в графа */
const unsigned n = 10; /* Брой върхове в графа */
/* Матрица на съседство на графа */
const char A[MAXN][MAXN] = {
  { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }
};

bool used[MAXN];
unsigned postnum[MAXN], count = 0;

void DFS(unsigned i)/* Обхождане в дълбочина със запазване на номерацията */
{ unsigned j;
  used[i] = 1;
  for (j = 0; j < n; j++)
    if (!used[j] && A[i][j]) DFS(j);
  postnum[i] = count++;
}

void backDFS(unsigned i)/* Обхождане в дълбочина на графа G’ */
{ unsigned j;
  printf("%u ", i + 1);
  count++; used[i] = 1;
  for (j = 0; j < n; j++)
    if (!used[j] && A[j][i]) backDFS(j);
}

/* Намира силно свързаните компоненти на графа */
void strongComponents(void)
{ unsigned i;
  for (i = 0; i < n; i++) used[i] = 0;
  while (count < n - 1) {
    for (i = 0; i < n; i++)
      if (!used[i]) DFS(i);
  }
  for (i = 0; i < n; i++) used[i] = 0;
  count = 0;
  while (count < n - 1) {
    unsigned max = 0, maxv = 0;
    for (i = 0; i < n; i++)
      if (!used[i] && postnum[i] > max) {
        max = postnum[i];
        maxv = i;
      }
    printf("{ ");
    backDFS(maxv);
    printf("}\n");
  }
}

int main(void) {
  printf("Silno svarzani komponenti w grafa sa:\n");
  strongComponents();
  return 0;
}
