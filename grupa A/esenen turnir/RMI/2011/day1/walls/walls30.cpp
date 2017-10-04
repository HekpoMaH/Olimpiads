#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

static const char *yesno[] = { "NO", "YES" };
const int MAXN = 131072, MAXM = 131072, INF = 0x3f3f3f3f;
const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;
int n, m;
int wWall[MAXN], hWall[MAXN];
long long xWall[MAXN];
int ballHits[MAXM], ballHeights[MAXM];

int main( )
{
    int i, j;
    scanf( "%d", &n );
    for( i = 0 ; i < n ; i++ )
        scanf( "%d%d", &wWall[i], &hWall[i] );

    // Compute the x positions of the walls
    xWall[0] = 1;
    for( i = 1 ; i < n ; i++ )
        xWall[i] = xWall[i - 1] + wWall[i - 1] + 1;

    scanf( "%d", &m );
    for( i = 0 ; i < m ; i++ )
    {
        int ballX;
        scanf( "%d%d", &ballX, &ballHeights[i] );

        // Compute the wall that was hit
        int hitWall;
        for( hitWall = n - 1 ; hitWall >= 0 && 
             (hWall[hitWall] < ballHeights[i] || 
              xWall[hitWall] > ballX) ; )
            hitWall--;
        ballHits[i] = hitWall;
        if( hitWall == -1 )
        {
            printf( "MISS\n" );
            continue;
        }

        int cntCell = 1;
        for( j = 0 ; j < i ; j++ )
            if( ballHits[j] == hitWall &&
                ballHeights[i] == ballHeights[j] )
                cntCell++;
        if( cntCell == wWall[hitWall] )
            hWall[hitWall] = ballHeights[i] - 1;
        printf( "HIT %lld %d %s\n",
                xWall[hitWall] + wWall[hitWall] - cntCell, 
                hitWall + 1, yesno[cntCell == wWall[hitWall]] );
    }
    return 0;    
}

