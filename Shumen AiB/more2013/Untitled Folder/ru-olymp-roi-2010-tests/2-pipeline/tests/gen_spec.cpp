#include "random.h"
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2048;

int n, k, m;
int p[MAXN];
char con[MAXN][MAXN];
int add_anti;

int main(int argc, char* argv[]){
  int z;
  sscanf(argv[1], "%d", &n);
  sscanf(argv[2], "%d", &z);
  sscanf(argv[3], "%d", &add_anti);
  int n2 = 0, m2 = 0, k2 = 0;
  if (add_anti){
    n2 = 9;
    m2 = 12;
    k2 = 4;
  }
  m = n * (n - 1) / 2 - z * (z - 1) / 2 + m2;
  k = n - z + k2;
  n += n2;
  printf("%d %d %d\n", n, m, k);
  int seed;
  sscanf(argv[4], "%d", &seed);
  initrand(seed);
  for (int i=0; i<n; i++){
    p[i] = i;
  }
  for (int i=1; i<n; i++){
    int pi = rndInt(i + 1);
    int t = p[i];
    p[i] = p[pi];
    p[pi] = t;
  }
  if (add_anti){
    for (int i=0; i<4; i++){
      int zx = n-n2+i+1;
      //con[n-n2][zx] = con[zx][n-n2] = 1;
      printf("%d %d\n", p[n-n2] + 1, p[zx] + 1);
      //con[zx][zx+4] = con[zx+4][zx] = 1;
      printf("%d %d\n", p[zx] + 1, p[zx + 4] + 1);
      int zy = (i % 2 == 0) ? zx + 5 : zx + 3;
      //con[zx][zy] = con[zy][zx] = 1;
      printf("%d %d\n", p[zx] + 1, p[zy] + 1);
    }
  }
  for (int i=0; i<n-n2-z; i++){
    for (int j=i+1; j<n-n2-z; j++){
      printf("%d %d\n", p[i] + 1, p[j] + 1);
      //con[i][j] = 1;
    }
  }
  for (int i=0; i<n-n2-z; i++){
    for (int j=n-n2-z; j<n-n2; j++){
      printf("%d %d\n", p[i] + 1, p[j] + 1);
      //con[i][j] = 1;
    }
  }
  return 0;
}
