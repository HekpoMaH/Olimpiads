#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

int n;
int tb[ 105 ][ 105 ];
int dp[ 105 ][ 105 ];

int min_path( int x, int y )
{
    for ( int i = 2; i <= n; i++ )
    {
        for ( int j = 2; j <= n; j++ )
        {
            dp[ i ][ j ] = min( dp[ i - 1 ][ j ], dp[ i ][ j - 1 ] ) + tb[ i ][ j ];
        }
    }
    return dp[ x ][ y ];
}

int main()
{
    cin >> n;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= n; j++ ) cin >> tb[ i ][ j ];

    memset( dp, -1, sizeof( dp ) );

    dp[ 1 ][ 1 ] = tb[ 1 ][ 1 ];
    for ( int i = 2; i <= n; i++ )
    {
        dp[ i ][ 1 ] = dp[ i - 1 ][ 1 ] + tb[ i ][ 1 ];
    }

    for ( int i = 2; i <= n; i++ )
    {
        dp[ 1 ][ i ] = dp[ 1 ][ i - 1 ] + tb[ 1 ][ i ];
    }

    cout << min_path( n, n ) << endl;

    return 0;
}


/*
3
1 2 3
4 5 6
7 8 9

4
1 2 3 4
2 5 6 8
3 7 9 8
4 8 8 10
*/
