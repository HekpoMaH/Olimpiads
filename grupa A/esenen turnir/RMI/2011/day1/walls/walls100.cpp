#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

static const char *yesno[] = { "NO", "YES" };
const int MAXN = 131072, MAXT = 2 * MAXN, INF = 0x3f3f3f3f;
const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;
int n, m;
int wWall[MAXN], hWall[MAXN];
long long xWall[MAXN];
int heightTree[MAXT];

#define LEFT_SON( x )       ( ((x) << 1) + 1 )
#define RIGHT_SON( x )      ( ((x) << 1) + 2 )

void updateTree( int tLow, int tHigh, int tInd, int pos, int newVal )
{
    if( tLow > tHigh )
        return;
    if( tLow == tHigh )
    {
        heightTree[tInd] = newVal;
        return;
    }

    int tMid = tLow + ((tHigh - tLow) >> 1);
    if( pos <= tMid )
        updateTree( tLow, tMid, LEFT_SON( tInd ), pos, newVal );
    else
        updateTree( tMid + 1, tHigh, RIGHT_SON( tInd ), pos, newVal );
    heightTree[tInd] = max( heightTree[LEFT_SON( tInd )],
                            heightTree[RIGHT_SON( tInd )] );
}

int findRightmostWall( int tLow, int tHigh, int tInd, int posx, int posy )
{
    if( posx < xWall[tLow] || posy > heightTree[tInd] || tLow > tHigh )
        return -1;
    if( tLow == tHigh )
        return tLow;

    int tMid = tLow + ((tHigh - tLow) >> 1), res;
    res = findRightmostWall( tMid + 1, tHigh, RIGHT_SON( tInd ), 
                             posx, posy );
    if( res == -1 )
        res = findRightmostWall( tLow, tMid, LEFT_SON( tInd ), 
                                 posx, posy ); 
    return res;
}

int main( )
{
    int i;
    scanf( "%d", &n );
    for( i = 0 ; i < n ; i++ )
    {
        scanf( "%d%d", &wWall[i], &hWall[i] );
        updateTree( 0, n - 1, 0, i, hWall[i] ); 
    }

    // Compute the x positions of the walls
    xWall[0] = 1;
    for( i = 1 ; i < n ; i++ )
        xWall[i] = xWall[i - 1] + wWall[i - 1] + 1;

    map< pair< int, int >, int > destroyedCells;
    scanf( "%d", &m );
    for( i = 0 ; i < m ; i++ )
    {
        int ballX, ballY;
        scanf( "%d%d", &ballX, &ballY );

        // Compute the wall that was hit
        int hitWall = findRightmostWall( 0, n - 1, 0, ballX, ballY );
        if( hitWall == -1 )
        {
            printf( "MISS\n" );
            continue;
        }

        pair< int, int > cell( hitWall, ballY );
        int &cntCell = destroyedCells[cell];
        cntCell++;
        if( cntCell == wWall[hitWall] )
            updateTree( 0, n - 1, 0, hitWall, ballY - 1 );
        printf( "HIT %lld %d %s\n",
                xWall[hitWall] + wWall[hitWall] - cntCell, 
                hitWall + 1, yesno[cntCell == wWall[hitWall]] );
    }
    return 0;    
}

