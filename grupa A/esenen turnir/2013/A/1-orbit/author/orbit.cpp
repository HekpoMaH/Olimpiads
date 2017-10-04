/*
 * Task: orbit
 * Author: Yordan Chaparov
 * 
 */
#include <iostream>
#include <cstdio>
#include <cassert>
#include <cmath>

using namespace std;

const int MAXN = 1 << 17;
const int MAXR = 1e9;
const double eps = 1e-9;

int N;
double R;
double X[MAXN], Y[MAXN], L[MAXN];

void scan(){
  int r;
  scanf ( "%d%d", &N, &r );
  R = r;
  assert ( N <= MAXN && N > 0 );
  assert ( R >= 1 && R <= MAXR );
  
  for ( int i = 0; i < N; ++i ){
    int x, y, l;
    scanf ( "%d%d%d", &x, &y, &l );
    assert ( x >= -MAXR && x <= MAXR );
    assert ( y >= -MAXR && y <= MAXR );
    assert ( l >= -MAXR && l <= MAXR );
    assert ( (double)x * (double)x + (double)y * (double)y > (double)R * (double)R );
    X[i] = x; Y[i] = y; L[i] = l;
  }
}

inline double SQR ( double X )	{ return X * X; }
inline double brightness ( double x, double y, int idx ){ return L[idx] / ( SQR (x - X[idx] ) + SQR ( y - Y[idx] ) ); }

inline double f ( double x, double y ){
  double mn = 0;
  
  for ( int i = 1; i < N; ++i )
    if ( brightness ( x, y, i ) > brightness ( x, y, mn ) )
      mn = i;
  
    
  return brightness ( x, y, mn );
}

inline double g ( double x, double y ){
  return f ( x, y ) - f ( -x, -y );
}

inline double getY ( double x ){
  return sqrt ( R * R - x * x );
}

inline double g ( double x ){
  double y = getY ( x );
  
  return g ( x, y );
}

void print ( double x ){
  double y;
  y = getY ( x );
  printf ( "%.12lf %.12lf %.12lf %.12lf\n", x, y, -x, -y );
 // printf ( "%.12lf %.12lf\n", f ( x, y ), f ( -x, -y ) );
}

void solve(){
  if ( abs ( g ( R ) ) < 1e-9 ){
    print ( R );
    return;
  }
  
  double l = -R, r = R;
  
  if ( g ( r ) < 0 )
    swap ( l, r );
  
  for ( int i = 0; i < 100; ++i ){
    double mid = ( l + r ) / 2.;
    
    if ( g ( mid ) > 0 )
      r = mid;
    else
      l = mid;
  }
  
  
  print ( (l + r) / 2.);
  
}

int main(){
  scan();
  solve();
}
