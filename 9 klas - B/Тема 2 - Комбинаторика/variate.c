#include <stdio.h>

#define MAXN 100

/* �������� �� n �������� �� ���� k */
const unsigned n = 4;
const unsigned k = 2;

int taken[MAXN];

void print(unsigned i)
{ unsigned k;
  printf("( ");
  for (k = 0; k <= i - 1; k++) printf("%u ", taken[k] + 1);
  printf(")\n");
}

/* �������� */
void variate(unsigned i)
{ unsigned j;
  /* ��� if (i>=k) � return; ��� (� ���� print(i); ��� ������ ������
   * ����������� � ������� 1,2, �, k, � �� ���� ���������� � ������� k */
  if (i >= k) { print(i); return; }
  for (j = 0; j < n; j++) {
    /* if (allowed(k)) { */
    taken[i] = j;
    variate(i + 1);
  }
}

int main(void) {
  variate(0);
  return 0;
}

