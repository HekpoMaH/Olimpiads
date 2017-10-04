#include "random.h"
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2048;

int n, k, m;
int per[MAXN];
char con[MAXN][MAXN];
int adj[MAXN];

int main(int argc, char* argv[]){
  int p, q;
  sscanf(argv[1], "%d", &n);
  sscanf(argv[2], "%d", &k);
  sscanf(argv[3], "%d", &p);
  sscanf(argv[4], "%d", &q);
  int seed;
  sscanf(argv[5], "%d", &seed);
  initrand(seed);
  int add = k * q - k * p - (n-k-p) * 2;
  add = rndInt(add / 10);
  m = k * p + (n-k-p) * 2 + add;
  printf("%d %d %d\n", n, m, k);
  for (int i=0; i<n; i++){
    per[i] = i;
  }
  for (int i=1; i<n; i++){
    int pi = rndInt(i + 1);
    int t = per[i];
    per[i] = per[pi];
    per[pi] = t;
  }
  int zzz = 0;
  for (int i=k+p; i<n; i++){
    for (int j=0; j<2; j++){
      /*int x = rndInt(k);
      if (adj[x] + 1 + p > q || con[i][x]){
        j--;
        continue;
      }*/
      int x = (2 * i + j) % k;
      adj[x]++;
      printf("%d %d\n", per[i] + 1, per[x] + 1);
      zzz++;
      con[i][x] = con[x][i] = 1;
    }
  }
  //printf("--- %d\n", zzz);
  for (int i=k; i<k+p; i++){
    for (int j=0; j<k; j++){
      printf("%d %d\n", per[i] + 1, per[j] + 1);
      zzz++;
      con[i][j] = con[j][i] = 1;
      adj[j]++;
    }
  }
  //printf("--- %d\n", zzz);
  for (int i=0; i<add; i++){
    int x = rndInt(k);
    if (adj[x] == q){
      i--;
      continue;
    }
    int y = rndInt(n - k) + k;
    if (con[x][y] || con[y][x] || x == y){
      i--;
      continue;
    }
    adj[x]++;
    con[x][y] = con[y][x] = 1;
    printf("%d %d\n", per[x] + 1, per[y] + 1);
  }
  return 0;
}
