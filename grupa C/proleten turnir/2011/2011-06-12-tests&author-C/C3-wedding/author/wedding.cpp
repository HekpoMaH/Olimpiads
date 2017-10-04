/*
NAME: Petar Petrov
LANG: C++
TASK: Wedding
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int hs[131072], hm[131072], ans, n, m;


void read()
{
    int i;
    scanf ( "%d %d", &n, &m );
    for ( i = 0; i < n; i++ ) scanf ( "%d", &hs[i] );
    for ( i = 0; i < m; i++ ) scanf ( "%d", &hm[i] );
    
}

int check( int x )
{
    int left, right, cn, i;
 
    left = 0;
    right = m - x;
    cn = 0;
    if ( x*2 > m ) return 0;
    if ( x == 0 ) return 1;
    
    for ( i = 0; i < n; i++ )
    {
	if ( ( hs[i] > hm[left] ) && ( hs[i] < hm[right] ) )
	{
	    left++;
	    right++;
	    cn++;
	    if ( cn == x ) return 1;
	}
    }
    return 0;
}

void binary_search()
{
    int left, right, mid;
    left = 0;
    right = m;
    
    sort ( hs, hs + n );
    sort ( hm, hm + m );
    
    while ( left <= right )
    {
	mid = ( left + right ) / 2;
	if ( check ( mid ) )
	{
	    ans = mid;
	    left = mid + 1;
	}
	else right = mid - 1;
    }
    printf ( "%d\n", ans );
}

int main()
{
    read();
    binary_search();
    return 0;
}