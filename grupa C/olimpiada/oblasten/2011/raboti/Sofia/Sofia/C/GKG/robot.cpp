# include <iostream>

using namespace std;

int main () {

    int m, n, r, k;

    cin >> m >> n >> r >> k;

    int i, j;
    int rr, rc;
    int x [m+1][n+1];
    int p = 1;

    for ( i = 1 ; i <= m ; i ++ )
         for ( j = 1; j <= n ; j ++, p ++ ) {
              x [i][j] = p;

              if ( p == r ) {

                   rr = i;
                   rc = j;

              }
         }

    i = rr;
    j = rc;
    p = 1;

    int s = 0, q = k - p;

    for ( k ; k > 0 ; p ++ && q -- && k -- ) {

         if ( i + p <= m ) {

              if ( j + q <= n )
                   s += x [i+p][j+q];

              if ( j - q > 0 )
                   s += x [i+p][j-q];
         }

         if ( i - p > 0 ) {

              if ( j + q <= n )
                   s += x [i-p][j+q];

              if ( j - q > 0 )
                   s += x [i-p][j-q];

         }
    }

    cout << s << endl;

    return 0;
}