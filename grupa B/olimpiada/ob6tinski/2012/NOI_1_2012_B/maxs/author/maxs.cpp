/*
PROGRAM NAME: maxs
AUTHOR: Evgenii Vassilev
*/
#include <cstdio>
#include <cmath>
#define PRECISION (1.0e-7)

double S(double r){
  double yprev=0, y=r/2, step=r/2, sprev=0, s, rr=r*r;
  for (; fabs(y-yprev)>PRECISION; yprev=y, y+=step, sprev=s){
    s = ((y*y>rr || y<0)?0:2*y*sqrt(rr-y*y));
    if (s<sprev) step=-step/2;
  }
  return ((y*y>rr || y<0)?0:2*y*sqrt(rr-y*y));
}

int main(){
  double R;
  scanf("%lf", &R);
  printf("%.3lf\n", S(R));
  return 0;
}
