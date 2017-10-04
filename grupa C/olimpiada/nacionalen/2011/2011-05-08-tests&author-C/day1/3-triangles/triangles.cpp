/*
PROGRAM NAME: triangles
AUTHOR: Evgenii Vassilev
*/
#include <cstdio>
#define SWAPTRIANGLES {f ^= 1; s ^= 1;}
#define NOJOINTLY {printf("0.000\n");return 0;}
#define CUTLEFT(a,b,d) {b = (b) * (a-d) / a; a -= d;}

struct Ttriangle {double x, y, a, b;} A[2];
int f, s=1, i;

int main(){
  for (i=0;i<2;i++) scanf("%lf %lf %lf %lf", &A[i].x, &A[i].y, &A[i].a, &A[i].b);

  if (A[f].x > A[s].x) SWAPTRIANGLES
  if ((i=A[s].x - A[f].x) >= A[f].a) NOJOINTLY
  else CUTLEFT(A[f].a, A[f].b, i)

  if (A[f].y > A[s].y) SWAPTRIANGLES
  if ((i=A[s].y - A[f].y) >= A[f].b) NOJOINTLY
  else CUTLEFT(A[f].b, A[f].a, i)

  if (A[f].b < A[s].b) SWAPTRIANGLES

  double S = A[s].a * A[s].b;
  if (A[s].a > A[f].a) S -= (A[s].a-A[f].a)*(A[s].a-A[f].a)*A[f].b*A[s].b/(A[s].a*A[f].b-A[f].a*A[s].b);
  printf("%.3lf\n",S/2.0);
  return 0;
}
