#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
int x[16], y[16];
int bdist = (1<<29);
bool us[16];

int mx( int a, int b )
{
    if ( a > b ) return a;
    return b;
}

int ia( int x )
{
    if ( x < 0 ) return -x;
    return x;
}

int di( int x1, int y1, int x2, int y2 )
{
    return mx( ia( x1-x2 ), ia( y1-y2 ) );
}

void rec( int bel, int cdist, int lx, int ly )
{
    if ( cdist >= bdist ) return;
    if ( bel >= n )
    {
        if ( cdist < bdist )
            bdist = cdist;
        return;
    }
    int i, j, k;
    for ( i = 1; i <= 2*n; i++ )
    {
        if ( us[i] == 0 )
        {
            us[i] = 1;
            rec( bel+1, cdist + di( lx, ly, x[i], y[i] ), x[i], y[i] );
            us[i] = 0;
        }
    }
}

int main()
{
    int i, j, k;

    scanf( "%d", &n );
    for ( i = 1; i <= 2*n; i++ )
    {
        scanf( "%d %d", &x[i], &y[i] );
    }
    memset( us, 0, sizeof( us ) );
    rec( 0, 0, 0, 0 );
    printf( "%d\n", bdist );
    return 0;
}
