#include<iostream>
#include<cmath>
#include<string>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<limits>

using namespace std;

struct point
{
    int x, y;
}p[ 20 ];

bool used[ 20 ];
int dp[ 20 ];

bool cmp( point a, point b )
{
    if ( a.x > b.x ) return false;
    if ( a.x < b.x ) return true;
    if ( a.y > b.y ) return false;
    if ( a.y < b.y ) return true;
}
int main()
{
    int n;
    cin >> n;
    p[ 0 ].x = 0;
    p[ 0 ].y = 0;

    for ( int i = 1; i <= 2 * n; i++ )
    {
        cin >> p[ i ].x >> p[ i ].y;
    }

    used[ 0 ] = 1;

    sort( p + 1, p + ( 2 * n + 1 ), cmp );
    int l = 0, cl;
    int cx, cy;
    int m;

    for ( int i = 1; i <= n; i++ )
    {
        dp[ i ] = numeric_limits< int > :: max();
        used[ l ] = 1;
        for ( int j = 1; j <= 2 * n; j++ )
        {
            cx = abs( p[ l ].x - p[ j ].x );
            cy = abs( p[ l ].y - p[ j ].y );

            if ( ( cx + cy ) % 2 == 0 && !used[ j ] )
            {
                m = max( cx, cy );
                if ( dp[ i ] > dp[ i - 1 ] + m )
                {
                    dp[ i ] = dp[ i - 1 ] + m;
                    cl = j;
                }
            }
        }
        //cout << l << endl;
        l = cl;
    }
    //cout << l << endl;
    cout << dp[ n ] << endl;
    return 0;
}
