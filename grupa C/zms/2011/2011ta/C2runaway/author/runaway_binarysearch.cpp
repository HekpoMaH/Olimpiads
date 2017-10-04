#include <cstdio>
#include <cmath>

using namespace std;

int a [1024][1024], x, n, k, ans;

void read ()
{
    int i, j; 
    scanf ( "%d", &n);
    for ( i = 0; i < n; i++ )
	for ( j = 0; j < n; j++ )
	    scanf ( "%d", &a [i][j] );
}

int binary_search ( int pos )
{
    int l, r, mid;
    l = 0;
    r = n-1;
    while ( l <= r )
    {
	mid = (l + r)/2;
	if ( a [pos][mid] == x ) return mid;
	if ( a [pos][mid] > x ) r = mid - 1;
	else l = mid + 1;
    }
    return -1;
}

void solve ()
{
    int i, j, min_ans = n*n;
    for ( i = 0; i < n; i++ )
    {
	j = binary_search ( i );
	if ( j != -1 )
	{
	    ans = ( i + int ( abs ( double ( n - 1 ) - j ) ) );
	    if ( ans < min_ans ) min_ans = ans;
	    //printf ( "%d %d\n",  (i + 1), (j + 1) );
	}
    }
    if ( min_ans == n*n ) printf ( "No Solution\n" );
    else printf ( "%d\n", min_ans );
}

int main ()
{
    int i;
    read ();
   // printf ( "das\n" );
    scanf ( "%d", &k ); 
    while ( k-- )
    {
	scanf ( "%d", &x );
	solve ();
    }
    return 0;
}