/*浜様様様様様様様様様曜様様様様様様様様様様様様様様様様様様様様様様様様様要
  �   緋� 轢 �珸諤     �   BIBLIOT.CPP                                     �
  �   説鴈�            �   �鞳驪珥 沃褌�                                   �
  �   菩跫蓚瑩鉋       �   BC++ 3.1                                        �
  麺様様様様様様様様様洋様様様様様様様様様様様様様様様様様様様様様様様様様容
  �   �鞳粱瑯轢�纃蒹   �  沃跏鞐 赭襃蓐琺邇 鞐硴鉤辮邇 鞐艨萵琿� 轢 鞳粫�� �
  �                    �  轢 k �瑜鱶.                                      �
  麺様様様様様様様様様擁様様様様様様様様様様様様様様様様様様様様様様様様様容
  �                              "宣竡韆鳰蒻�"                             �
  藩様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様謡*/

#include <stdio.h>
#include <values.h>
#include <stdlib.h>
#define MAX 200
#define max(a,b) ((a > b) ? a : b)  //宅��� 闔-竡諷跏� 瑁笂跂迺

#define IN_FILE  "BIBLIOT.INP"
#define OUT_FILE "BIBLIOT.OUT"

unsigned s[MAX];   // 倥粫�� (陏鞨��� 辣 驟 闔諛矗)
unsigned n;   // 草鉗 繼繻纃鱶 � 鞳粫�瑩�
unsigned k;   // 草鉗 竦齒�
unsigned long p[MAX];  // �鞳�蒻骰� 體跏
unsigned long *f[MAX]; // 帙諷矗 �鼾襁��
unsigned long *b[MAX]; // 楳 碾苟鰰邇��矗辣 轢 鞳�纃蒹鴈
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

unsigned long DoPartition(unsigned long k) { // 泌碾頽矗 鈿鱶赭謐� 鞐舮繼�辣 轢 k 竦齒�
unsigned long i,j,l;
  // �鞳骭�鰰跂 關續蒻骰蓿� 體跏
  p[0] = 0;
  for (i=1; i<=n; i++)
    p[i] = p[i-1] + s[i];

  // 囁鰰邇��矗辣 轢 竦琿蔟辷鱚 齣謗礦�
  for (i=1; i<=n; i++) f[i][1] = p[i];
  for (i=1; i<=k; i++) f[1][j] = s[1];

  // 暦邇矼� �蒻��
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
  fprintf(fpout,"匁辷赭謐銜� 釶�� 碚繻� 艢 關鈞辮袱 �: %lu",DoPartition(k));
  PrintPartition(n,k);
  fclose(fpout);
  Delete();
  return 0;
}
