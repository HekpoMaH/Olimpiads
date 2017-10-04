#include <stdio.h>
#define MAXN 150/* ���������� ���� ������� � ����� */
const unsigned n = 7;/* ���� ������� � ����� */
char A[MAXN][MAXN] = {/* ������� �� ��������� �� �����*/
  { 0, 1, 0, 0, 0, 0, 0 },
  { 1, 0, 1, 0, 0, 1, 0 },
  { 0, 1, 0, 1, 0, 1, 0 },
  { 0, 0, 1, 0, 1, 1, 0 },
  { 0, 0, 0, 1, 0, 0, 0 },
  { 0, 1, 1, 1, 0, 0, 1 },
  { 0, 0, 0, 0, 0, 1, 0 }
};
unsigned prenum[MAXN], lowest[MAXN], cN;
unsigned min(unsigned a, unsigned b) { return (a < b) ? a : b; }

void DFS(unsigned i)
{ unsigned j;
  prenum[i] = ++cN;
  for (j = 0; j < n; j++)
    if (A[i][j] && !prenum[j]) {
      A[i][j] = 2;  /* ������ ��������� ����� T */
      DFS(j);
    }
}
void postOrder(unsigned i)/* ��������� �� ������� � ���*/
{ unsigned j;
  for (j = 0; j < n; j++)
    if (2 == A[i][j]) postOrder(j);
  lowest[i] = prenum[i];
  for (j = 0; j < n; j++)
    if (1 == A[i][j]) lowest[i] = min(lowest[i], prenum[j]);
  for (j = 0; j < n; j++)
    if (2 == A[i][j]) lowest[i] = min(lowest[i], lowest[j]);
}

void findArticPoints()
{ unsigned artPoints[MAXN], i, j, count;
  for (i = 0; i < n; i++) {
    prenum[i] = 0; lowest[i] = 0; artPoints[i] = 0;
  }
  cN = 0;
  DFS(0);
  for (i = 0; i < n; i++)
    if (0 == prenum[i]) {
      printf("������ �� � ������� - \n");
      return;
    }
  postOrder(0);
  /* ����������� 3.1) */
  count = 0;
  for (i = 0; i < n; i++)
    if (2 == A[0][i]) count++;
  if (count > 1) artPoints[0] = 1;
  /* ��������� ������ 2) */
  for (i = 1; i < n; i++) {
    for (j = 0; j < n; j++)
      if (2 == A[i][j] && lowest[j] >= prenum[i]) break;
    if (j < n) artPoints[i] = 1;
  }
  printf("Razdelqshti tochki sa:\n");
  for (i = 0; i < n; i++)
    if (artPoints[i]) printf("%u ", i + 1);
  printf("\n");
}

int main(void) {
  findArticPoints();
  return 0;
}
