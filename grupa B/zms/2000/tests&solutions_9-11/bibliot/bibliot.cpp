/*ษออออออออออออออออออออหอออออออออออออออออออออออออออออออออออออออออออออออออออื
  ว   ศ์ๅ ํเ ๔เ้๋เ     ว   BIBLIOT.CPP                                     ว
  ว   ภโ๒๎๐            ว   ฯ๐ๅ๑๋เโ อเ๊๎โ                                   ว
  ว   ส๎์๏่๋เ๒๎๐       ว   BC++ 3.1                                        ว
  ฬออออออออออออออออออออฮอออออออออออออออออออออออออออออออออออออออออออออออออออฦ
  ว   ฯ๐ๅไํเ็ํเ๗ๅํ่ๅ   ว  อเ์่๐เ ์เ๊๑่์เ๋ํ๎ ๐เโํ๎์ๅ๐ํ๎ ๐เ็แ่โเํๅ ํเ ๐ๅไ่๖เ ว
  ว                    ว  ํเ k ๗เ๑๒่.                                      ว
  ฬออออออออออออออออออออสอออออออออออออออออออออออออออออออออออออออออออออออออออฦ
  ว                              "ภ๋ใ๎๐่๒์่๊๑"                             ว
  ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออุ*/

#include <stdio.h>
#include <values.h>
#include <stdlib.h>
#define MAX 200
#define max(a,b) ((a > b) ? a : b)  //ย๐๚๙เ ๏๎-ใ๎๋ๅ์่ÿ เ๐ใ๓์ๅํ๒

#define IN_FILE  "BIBLIOT.INP"
#define OUT_FILE "BIBLIOT.OUT"

unsigned s[MAX];   // ะๅไ่๖เ (๏๚๐โ่ÿ๒ ํๅ ๑ๅ ๏๎๋็โเ)
unsigned n;   // ม๐๎้ ๅ๋ๅ์ๅํ๒่ โ ๐ๅไ่๖เ๒เ
unsigned k;   // ม๐๎้ ใ๐๓๏่
unsigned long p[MAX];  // ฯ๐ๅ๔่๊๑ํ่ ๑๓์่
unsigned long *f[MAX]; // ึๅ๋ๅโเ ๔๓ํ๊๖่ÿ
unsigned long *b[MAX]; // วเ โ๚็๑๒เํ๎โÿโเํๅ ํเ ๐ๅ๘ๅํ่ๅ๒๎
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

unsigned long DoPartition(unsigned long k) { // ศ็โ๚๐๘โเ ๎๏๒่์เ๋ํ๎ ๐เ็ไๅ๋ÿํๅ ํเ k ใ๐๓๏่
unsigned long i,j,l;
  // ฯ๐ๅ๑์ÿ๒เ์ๅ ๏๐ๅ๔่๊๑ํ่๒ๅ ๑๓์่
  p[0] = 0;
  for (i=1; i<=n; i++)
    p[i] = p[i-1] + s[i];

  // ำ๑๒เํ๎โÿโเํๅ ํเ ใ๐เํ่๗ํ่๒ๅ ๓๑๋๎โ่ÿ
  for (i=1; i<=n; i++) f[i][1] = p[i];
  for (i=1; i<=k; i++) f[1][j] = s[1];

  // ฮ๑ํ๎โๅํ ๖่๊๚๋
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
  fprintf(fpout,"ฬ่ํ่์เ๋ํ๎๒๎ ๎แ๙๎ โ๐ๅ์ๅ ็เ ๏๐๎โๅ๐๊เ ๅ: %lu",DoPartition(k));
  PrintPartition(n,k);
  fclose(fpout);
  Delete();
  return 0;
}
