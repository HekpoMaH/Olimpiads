#include "random.h"
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2048;

int n, k, m;
int p[MAXN];
char con[MAXN][MAXN];

int main(int argc, char* argv[]){
  sscanf(argv[1], "%d", &n);
  sscanf(argv[2], "%d", &m);
  sscanf(argv[3], "%d", &k);
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
  //for (int i=0; i<n; i++) printf("%d ", p[i]);
  for (int i=0; i<m; i++){
    int x = rndInt(k);
    int y = rndInt(n);
    if (rndInt(2)){
      swap(x, y);
    }
    if (x == y || con[x][y]){
      i--;
      continue;
    }
    con[x][y] = con[y][x] = true;
    printf("%d %d\n", p[x] + 1, p[y] + 1);
  }
  return 0;
}
