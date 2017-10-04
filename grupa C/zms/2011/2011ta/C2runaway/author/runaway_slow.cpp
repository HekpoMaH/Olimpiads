#include <cstdio>
#include <cmath>

using namespace std;

int a[1024][1024], n, k, x, ans;

void read ()
{
    int i, j;
    scanf ( "%d", &n);
    for ( i = 0; i < n; i++ )
	for ( j = 0; j < n; j++ )
	    scanf ( "%d", &a[i][j] );
}

void solve ()
{
    int i, j; 
    for ( i = 0; i < n; i++ )
	for ( j = 0; j < n; j++ )
	    if ( a[i][j] == x )
	    {
		ans = i + int ( abs ( double(n - 1) - double(j) ) );
		//printf ( "%d %d\n", (i+1), (j+1) );
		printf ( "%d\n", ans );
		return;
	    }
	    printf ( "No Solution\n" );
}

int main ()
{
    read ();
    scanf ( "%d", &k );
    while ( k-- )
    {
	scanf ( "%d", &x );
	solve ();
    }
    return 0;
}