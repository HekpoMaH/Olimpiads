#include <cmath>
#include "testlib.h"
using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-9;

const int MAXN = 100;
const int MAXC = 10000;
const int MAXL = 10000;

int n, xs[MAXN + 2], ys[MAXN + 2], l;

int vpv(int x1, int y1, int x2, int y2){
  return x1 * y2 - x2 * y1;
}

int spv(int x1, int y1, int x2, int y2){
  return x1 * x2 + y1 * y2;
}

int main()
{
    registerValidation();

    n = inf.readInt(3, MAXN);
    inf.readEoln();
	
    for (int i=0; i<n; i++){
      xs[i] = inf.readInt(-MAXC, MAXC);
      inf.readSpace();
      ys[i] = inf.readInt(-MAXC, MAXC);
      inf.readEoln();
    }
    
    int x0 = inf.readInt(-MAXC, MAXC);
    inf.readSpace();
    int y0 = inf.readInt(-MAXC, MAXC);
    inf.readSpace();
    l = inf.readInt(1, MAXL);
    inf.readEoln();

    xs[n] = xs[0];
    ys[n] = ys[0];
    xs[n+1] = xs[1];
    ys[n+1] = ys[1];
    long long s = 0;
    bool onside = false;
    for (int i=0; i<n; i++){
      s += (ys[i] + ys[i+1]) * (xs[i+1] - xs[i]);
      if (vpv(x0-xs[i], y0-ys[i], x0-xs[i+1], y0-ys[i+1]) == 0
       && spv(xs[i]-x0, ys[i]-y0, xs[i+1]-x0, ys[i+1]-y0) <= 0){
        onside = true;
      }
    }
    ensuref(s > 0, "Incorrect traversal order!");
    ensuref(onside, "(x0, y0) doesn't lie on the border!");
 
    double sdeg = 0;

    for (int i=1; i<=n; i++){
      int s = spv(xs[i-1]-xs[i], ys[i-1]-ys[i], xs[i+1]-xs[i], ys[i+1]-ys[i]);
      int v = vpv(xs[i-1]-xs[i], ys[i-1]-ys[i], xs[i+1]-xs[i], ys[i+1]-ys[i]);
      ensuref(v > 0, "Incorrect angle at vertex %d!", i % n);
      sdeg += atan2(1.0 * v, 1.0 * s);
    }

    double ndeg = PI * (n - 2);
    ensuref(fabs(ndeg - sdeg) < EPS, "The polygon is not convex or have self-intersections!");

    inf.readEof();
    return 0;
}
