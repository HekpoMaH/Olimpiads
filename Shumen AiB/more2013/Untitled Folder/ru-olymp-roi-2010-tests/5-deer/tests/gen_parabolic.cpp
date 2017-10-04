#include "random.h"
#include <cstdio>
#include <algorithm>

using namespace std;

inline int gcd(int a, int b){
  return (b == 0) ? a : gcd(b, a % b);
}

const int MAXL = 100000;
const int MAXC = 10000;
const int MAXN = 100;
const double PI = acos(-1.0);

double phi[MAXN * 2];
int xs[MAXN * 2], ys[MAXN * 2];

int main(int argc, char* argv[]){
  int n, rx, ry, more;
  double percent;
  sscanf(argv[1], "%d", &n);
  sscanf(argv[2], "%d", &rx);
  sscanf(argv[3], "%d", &ry);
  sscanf(argv[4], "%d", &more);
  sscanf(argv[5], "%lf", &percent);
  int seed;
  sscanf(argv[6], "%d", &seed);
  initrand(seed);

  int s = rndInt(n), fr = rndInt(n);
  for (int i=0; i<n; i++){
    xs[fr] = rx * (i - s);
    ys[fr] = ry * (i - s) * (i - s);
    fr = (fr + n - 1) % n;
  }
  xs[n] = xs[0];
  ys[n] = ys[0];

  int wh = rndInt(n), x0 = 0, y0 = 0;
  bool found = false;
  while (!found){
    int dx = xs[wh+1] - xs[wh];
    int dy = ys[wh+1] - ys[wh];
    int g = gcd(abs(dx), abs(dy));
    if (g > 1 || rndInt(4) == 0){
      int t = rndInt(g);
      x0 = xs[wh] + (dx / g) * t;
      y0 = ys[wh] + (dy / g) * t;
      //printf("!!! %d %d %d %d %d %d %d %d\n", wh, xs[wh], ys[wh], x0, y0, dx, dy, g);
      found = true;
    }
    wh = (wh + 1) % n;
  }
  
  double pp = 0;
  for (int i=0; i<n; i++){
    pp += sqrt((xs[i]-xs[i+1])*(xs[i]-xs[i+1]) + (ys[i]-ys[i+1])*(ys[i]-ys[i+1]));
  }

  int per = int(pp / 2.0 - 1e-9);

  //int r = (more == 0) ? R(1, per) : R(per+2, (int)(per * 1.1));
  //int r = (more == 0) ? R(1, per) : int(per * percent);
  int r = int(per * percent);

  int zx = R(-100, 100);
  int zy = R(-100, 100);

  printf("%d\n", n);
  for (int i=0; i<n; i++) printf("%d %d\n", zx + xs[i], zy + ys[i]);
  printf("%d %d %d\n", zx + x0, zy + y0, r);
  return 0;
}
