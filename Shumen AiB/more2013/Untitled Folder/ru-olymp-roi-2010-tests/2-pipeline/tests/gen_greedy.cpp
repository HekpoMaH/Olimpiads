#include "random.h"
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2048;

int n, k, m;
int p[MAXN], q[MAXN];
char con[MAXN][MAXN];

int main(int argc, char* argv[]){
  int x, y;
  sscanf(argv[1], "%d", &x);
  sscanf(argv[2], "%d", &y);
  n = 1 + x + x * y;
  m = x + x * y + x * y;
  k = x;
  printf("%d %d %d\n", n, m, k);
  int seed;
  sscanf(argv[3], "%d", &seed);
  initrand(seed);
  for (int i=0; i<n; i++){
    p[i] = i;
    q[i] = i;
  }
  for (int i=1; i<n; i++){
    int pi = rndInt(i + 1);
    int t = p[i];
    p[i] = p[pi];
    p[pi] = t;
    int qi = rndInt(i + 1);
    t = q[i];
    q[i] = q[qi];
    q[qi] = t;
  }
  for (int i=1; i<=x; i++){
    con[0][i] = con[i][0] = 1;
  }
  for (int i=1; i<=x; i++){
    for (int j=0; j<y; j++){
      int np = (i-1) * y + j + 1 + x;
      con[i][np] = con[np][i] = 1;
      int ni = (i == x) ? 1 : (i + 1);
      con[np][ni] = con[ni][np] = 1;
    }
  }
  for (int i=0; i<n; i++){
    for (int j=i+1; j<n; j++){
      if (con[q[i]][q[j]]){
        printf("%d %d\n", p[q[i]] + 1, p[q[j]] + 1);
      }
    }
  }
  return 0;
}
