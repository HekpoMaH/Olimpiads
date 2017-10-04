#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 200/* ���������� ���� ������� � ����� */
#define MAXM 2000/* ���������� ���� ����� � ����� */
int n = 9, m = 14;  /* ���� ������� � ���� ����� � ����� */
struct arc { int i, j, f;};
bool comp(arc x, arc y) { return (x.f<y.f); }
arc S[MAXM] = {  /* ������ �� ������� �� ����� � ������� ����� */
  { 1, 2, 1 },
  { 1, 4, 2 },
  { 2, 3, 3 },
  { 2, 5, 13 },
  { 3, 4, 4 },
  { 3, 6, 3 },
  { 4, 6, 16 },
  { 4, 7, 14 },
  { 5, 6, 12 },
  { 5, 8, 1 },
  { 5, 9, 13 },
  { 6, 7, 1 },
  { 6, 9, 1 }
};
int prev[MAXN + 1];//������� �� ���� i, ��������� �� ������ � -1

int getRoot(int i)/* �������� �� ������ �� ������� */
{ int root = i, savei;
  while (prev[root] != -1) root = prev[root];
  while (i != root) /* ������� �� ���� */
  {  savei = i;
    i = prev[i];
    prev[savei] = root;
  }
  return root;
}

void kruskal()
{ int MST = 0;
  unsigned i, j;
  sort(S, S+m, comp);/* ������� ������� � ������� � ��������� ���*/
  printf("Rebrata v MST:\n");
  for (i = 0; i < m; i++) {
    int r1 = getRoot(S[i].i);
    int r2 = getRoot(S[i].j);
    if (r1 != r2) {
      printf("(%u,%u) ", S[i].i, S[i].j);
      MST += S[i].f;
      prev[r2] = r1;
    }
  }
  printf("\nCenata na MST e %d.\n", MST);
}

int main()
{ unsigned i;
  for (i = 0; i < n + 1; i++) prev[i] = -1;
  kruskal();
  return 0;
}
