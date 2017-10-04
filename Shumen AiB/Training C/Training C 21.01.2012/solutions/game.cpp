#include <cstdio>
#include <cstring>

using namespace std;

int sumrow [ 1024 ][ 1024 ], sumcol [ 1024 ][ 1024 ], ans [ 1024 ][ 1024 ], n;

void read ()
{
    int i, j, a;
    scanf ( "%d", &n );
    for ( i = 1; i <= n; i++ )
	for ( j = 1; j <= n; j++ )
	{
	    scanf ( "%d", &a );
	    sumrow [ i ][ j ] = sumrow [ i ][ j - 1 ] + a;
	    sumcol [ i ][ j ] = sumcol [ i - 1 ][ j ] + a;
	}
}

void solve ()
{
    int i, j;
    for ( i = 1; i <= n; i++ )
	for ( j = 1; j <= n; j++ )
	    if ( sumrow [ i ][ j ] % 2 == 0 && ans [ i - 1 ][ j ] == 0 ) ans [ i ][ j ] = 1;
	    else
		if ( sumcol [ i ][ j ] % 2 == 0 && ans [ i ][ j - 1 ] == 0 ) ans [ i ][ j ] = 1;
		else ans [ i ][ j ] = 0;
		if ( ans [ n ][ n ] ) printf ( "W\n" );
		else printf ( "L\n" );
}


int main ()
{
    int test;
	read ();
	solve ();
    return 0;
}