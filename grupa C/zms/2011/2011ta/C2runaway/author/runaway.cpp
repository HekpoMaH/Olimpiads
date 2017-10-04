/* 
Runaway.cpp
Perar Petrov
*/

#include <cmath>
#include <cstdio>

using namespace std;

int a [1024][1024], n, m, x, k;

void read ()
{
    int i, j;
    scanf ( "%d", &n );
    for ( i = 0; i < n; i++ )
	for ( j = 0; j < n; j++ )
	    scanf ( "%d", &a [i][j] );
}

void solve ()
{
    int row, col, ans = 0;
    row = 0;
    col = n - 1;
    while ( 1 )
    {
	if ( a [row][col] == x )
	{
	    ans = row + int ( abs ( double ( n - 1 ) - double ( col ) ) );
	    printf ( "%d\n", ans );
	    return;
	}
	if ( a [row][col] > x ) col--;
	else row++;
	if ( row == n || col < 0 )
	{
	    printf ( "No Solution\n" );
	    return;
	}
    }
}

int main ()
{
    read ();
    scanf( "%d", &k );
    while ( k-- )
    {
	scanf ( "%d", &x );
	solve ();
    }
    return 0;
}