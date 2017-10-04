#include <cstdio>
#include <algorithm>
#include <climits>
#define MAXM 10000
#define MAXG 10001

typedef unsigned char uchar;

const int LLONG_SIZE = sizeof(long long),
          LLONG_BITS = LLONG_SIZE*8,
          INT_CORR   = (1<<sizeof(short)*8)+1;

union Tp { int a;
           struct {short int x, y;};
         } p[MAXG];

unsigned long long A[MAXM][MAXM/LLONG_BITS+1], smask, emask;
int m,n,t,cg,sum, sll, ell, sbit, ebit,du,dd,d;//,ml;
uchar BITS[256], *q;

void make_apples_rotted(int row, int s/*start pos*/, int e/*end pos*/);
void make_apples_rotted_symmetrically(int row, int s_origin, int e_origin, int count_rows);

int main() {
  int i,j,k;
  for (j=1 ; j<=128; j<<=1) for (i=0;i<j;BITS[j+i++]=BITS[i]+1);
  scanf("%d %d %d", &n, &m, &t);

  for (cg=0; scanf("%hd %hd", &p[cg].y, &p[cg].x) == 2; p[cg++].a -= INT_CORR );
  p[cg].x = p[cg].y = SHRT_MAX;

  std::sort((int*)p,(int*)p+cg);

  for (i=j=0; i<cg; i=++j) {
    while (p[j+1].a-p[j].a == 1) j++;
    make_apples_rotted( p[i].y, p[i].x, p[j].x);
    du = p[i].y + t; if (du >= n) du = n-1;
    dd = p[i].y - t; if (dd < 0)   dd = 0;
    d = std::min(du-p[i].y,p[i].y-dd);
    if (d) make_apples_rotted_symmetrically( p[i].y, p[i].x, p[j].x, d );
    if (du > d+p[i].y)
      for (k=  p[i].y + ++d; k<=du; d++, k++) make_apples_rotted( k, p[i].x+d, p[j].x-d );
    if (dd < p[i].y-d)
      for (k=  p[i].y - ++d; k>=dd; d++, k--) make_apples_rotted( k, p[i].x+d, p[j].x-d );
  }
  // count rotted apples
  for (i=0, k=m/LLONG_BITS+(m%LLONG_BITS>0); i<n; i++) for (j=0; j<k; j++)
    switch (A[i][j]) {
      case ULLONG_MAX : sum += LLONG_BITS;
      case 0          : break;
      default :
        q = (uchar*) &A[i][j];
        sum += BITS[q[0]] + BITS[q[1]] + BITS[q[2]] + BITS[q[3]] + BITS[q[4]] + BITS[q[5]] + BITS[q[6]] + BITS[q[7]] ;
    }
  printf( "%d\n", m*n-sum);
  return 0;
}

void make_apples_rotted(int row, int s/*start pos*/, int e/*end pos*/) {
  s-=t; if (s<0) s=0;
  e+=t; if (e>=m) e=m-1;
  sll = s / LLONG_BITS; sbit = s % LLONG_BITS;
  ell = e / LLONG_BITS; ebit = e % LLONG_BITS;
  smask = (ULLONG_MAX << sbit);
  emask = (ULLONG_MAX >> (LLONG_BITS-ebit-1));
  for (int i =sll+1 ; i< ell; A[row][i++] |= ULLONG_MAX );
  if (ell-sll) A[row][ell] |= emask;
  else smask = smask & emask;
  A[row][sll] |= smask;
}

void make_apples_rotted_symmetrically(int row, int s_origin, int e_origin, int count_rows) {
  int i, j, above=row+1, below=row-1, s, e;
  for (j=1; j<=count_rows; above++, below--, j++) {
    s=s_origin-t+j; if (s<0) s=0;
    e=e_origin+t-j; if (e>=m) e=m-1;
    sll = s / LLONG_BITS; sbit = s % LLONG_BITS;
    ell = e / LLONG_BITS; ebit = e % LLONG_BITS;
    smask = (ULLONG_MAX << sbit);
    emask = (ULLONG_MAX >> (LLONG_BITS-ebit-1));
    for (i =sll+1 ; i< ell; i++) {
      A[above][i] |= ULLONG_MAX ;
      A[below][i] |= ULLONG_MAX ;
    }
    if (ell-sll) {
      A[above][ell] |= emask ;
      A[below][ell] |= emask ;
      }
    else smask = (smask & emask);
    A[above][sll] |= smask ;
    A[below][sll] |= smask ;
  }
}
