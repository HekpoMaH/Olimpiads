/*��������������������������������������������������������������������������
  �   ��� �� �����     �   BIBLIOT.CPP                                     �
  �   �����            �   ������� �����                                   �
  �   ����������       �   BC++ 3.1                                        �
  ��������������������������������������������������������������������������
  �   ��������������   �  ������ ���������� ���������� ��������� �� ������ �
  �                    �  �� k �����.                                      �
  ��������������������������������������������������������������������������
  �                              "�����������"                             �
  ��������������������������������������������������������������������������*/

#include <stdio.h>
#include <values.h>
#include <stdlib.h>
#define MAX 200
#define max(a,b) ((a > b) ? a : b)  //����� ��-������� ��������

#define IN_FILE  "BIBLIOT.INP"
#define OUT_FILE "BIBLIOT.OUT"

unsigned s[MAX];   // ������ (������� �� �� ������)
unsigned n;   // ���� �������� � ��������
unsigned k;   // ���� �����
unsigned long p[MAX];  // ��������� ����
unsigned long *f[MAX]; // ������ �������
unsigned long *b[MAX]; // �� �������������� �� ���������
FILE *fpout;

void Init() { // Read the input file
  FILE *fp;
  unsigned int i;

  if ((fp = fopen(IN_FILE,"rt")) == NULL) {
    fprintf(stderr,"\nError while trying to open %s for reading!",IN_FILE);
    exit(-1);
  }
  // Read k first
  fscanf(fp,"%u",&k);

  // Get the next values
  for (n = 0; !feof(fp); n++)
    fscanf(fp,"%u",&s[n+1]);

  fclose(fp);

  for (i = 1; i < n+1; i++) {
    f[i] = (unsigned long *) malloc(n*sizeof(unsigned long));
    b[i] = (unsigned long *) malloc(n*sizeof(unsigned long));
    if (f[i] == NULL || b[i] == NULL) {
      fprintf(stderr,"\nError while trying to allocate a memory: %u!",i);
      exit(-1);
    }
  }
}

unsigned long DoPartition(unsigned long k) { // �������� ��������� ��������� �� k �����
unsigned long i,j,l;
  // ���������� ����������� ����
  p[0] = 0;
  for (i=1; i<=n; i++)
    p[i] = p[i-1] + s[i];

  // ������������ �� ���������� �������
  for (i=1; i<=n; i++) f[i][1] = p[i];
  for (i=1; i<=k; i++) f[1][j] = s[1];

  // ������� �����
  for (i=2; i<=n; i++)
    for (j=2; j<=k; j++) {
      f[i][j] = 4900000000;
      for (l=1; l<=i-1; l++) {
        unsigned long m = max(f[l][j-1],p[i]-p[l]);
        if (f[i][j] > m) {
          f[i][j] = m;
          b[i][j] = l;
        }
      }
    }
  return f[n][k];
}

void Print(unsigned from, unsigned to) {
  fprintf(fpout,"\n");
  for (int i=from; i<=to; i++)
    fprintf(fpout,"%u ",s[i]);
}

void PrintPartition(unsigned n, unsigned k) {
  if (k == 1)
    Print(1,n);
  else {
    PrintPartition(b[n][k],k-1);
    Print(b[n][k]+1,n);
  }
}

void Delete()
{
  for (unsigned int i = 0; i < n; i++) {
    free(f[i]);
    free(b[i]);
  }
}

int main() {
  Init();
  if ((fpout = fopen(OUT_FILE,"wt")) == NULL) {
    fprintf(stderr,"\nError while trying to open %s for writing!",OUT_FILE);
    exit(-1);
  }
  fprintf(fpout,"����������� ���� ����� �� �������� �: %lu",DoPartition(k));
  PrintPartition(n,k);
  fclose(fpout);
  Delete();
  return 0;
}
