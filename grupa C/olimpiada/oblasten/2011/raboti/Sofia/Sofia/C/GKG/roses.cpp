# include <iostream>

using namespace std;

int main () {

    int m, n, k, i, j, t = 0;

    cin >> m >> n >> k;

    k *= k;

    int x [m+1][n+1];

    int max = 0;

    for ( i = 0 ; i < m ; i ++ )
         for ( j = 0 ; j < n ; j ++ ) {

              cin >> x [i][j];

              if ( max < x [i][j] )
                   max = x [i][j];

              t += x [i][j];

         }

    for ( i = m ; i <= m ; i ++ )
         for ( j = n ; j <= n ; j ++)
              x [i][j] = 0;

    int m1, m2, m3;

    for ( i = 0 ; i < m ; i ++ )
         for ( j = 0 ; j < n ; j ++ )
              if ( x [i][j] == max ) {

                   break;
                   break;

              }

    t -= max;
    k --;

    while ( k > 0 ) {

    if ( x [i-1][j] > x [i+1][j] )
         m1 = x [i-1][j];

    else m1 = x [i+1][j];

    if ( x [i][j-1] > x [i][j+1] )
         m2 = x [i][j-1];

    else m2 = x [i][j+1];

    if ( m1 > m2 )
         m3 = m1;

    else m3 = m2;

    t -= m3;

    for ( i = 0 ; i < m ; i ++ )
         for ( j = 0 ; j < n ; j ++ )
              if ( x [i][j] == m3 ) {

                   break;
                   break;

              }
    k --;

    }

    cout << t << endl;

    return 0;
}