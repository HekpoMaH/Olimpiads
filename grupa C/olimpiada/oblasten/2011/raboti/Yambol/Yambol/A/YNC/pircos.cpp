#include <cstdio>

int n;
long long c;
long long xr[64][2];

long long MIN( long long A, long long B )
{
    if ( A < B ) return A;
    return B;
}

long long MAX( long long A, long long B )
{
    if ( A > B ) return A;
    return B;
}

int main()
{
    long long x, a, b;
    int i, j;
    long long k;
    scanf( "%d", &n );
    c = 0;
    for ( j = 0; j <= 62; j++ )
    {
        xr[j][0] = 0;
        xr[j][1] = 0;
    }
    for ( i = 1; i <= n; i++ )
    {
        scanf( "%lld", &x );
        c = (c^x);
        for ( j = 0; j <= 62; j++ )
        {
            k = ((1LL<<j)&x);
            if ( k != 0 ) k = 1;
            xr[j][k] = ( xr[j][k] ^ x );
        }
    }
    for ( j = 0; j <= 62; j++ )
    {
        if ( (1LL<<j)&c )
        {
            a = MIN( xr[j][0], xr[j][1] );
            b = MAX( xr[j][0], xr[j][1] );
            break;
        }
    }
    printf( "%lld %lld\n", a, b );
    return 0;
}
