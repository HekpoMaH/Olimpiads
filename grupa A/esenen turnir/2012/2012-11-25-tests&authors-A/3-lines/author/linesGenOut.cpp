/*
 * Task: lines
 * Complexity: O(n*log n + q*log n)
 * Author: Yordan Chaparov
 * Solution Idea: Vladislav Haralampiev
 * Every two lines should cross!
 */

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

const double eps = 1e-9;
const double minf = -100;

const int xr = (1<<29)-1;

typedef pair<double,double> pdd;      // a[i], b[i]
typedef pair<double,int> pdi;         //start point, index

int n, q;
pdd ab[1<<17];

int cnode;
double tri[1<<17], trd[1<<17];
double syi[1<<17], syd[1<<17];
int pari[1<<17][18], pard[1<<17][18];

//O(1)
double cross( pdd l, pdd s )
{
	return (l.second-s.second)/(s.first-l.first);
}

//O(1)
double evalLine( pdd l, double x )
{
	return l.first * x + l.second;
}

void addLineInc( int p )
{
    //add ab[p] to upper envelope tree
    while ( ( cnode > 0 ) && ( cross( ab[p], ab[ cnode ] ) < tri[cnode] ) )
        cnode = pari[cnode][0];
    if ( cnode == 0 )
    {
        tri[p] = minf;
        pari[p][0] = cnode;
        syi[p] = evalLine( ab[p], minf );
        cnode = p;
    }
    else
    {
        tri[p] = cross( ab[p], ab[ cnode ] );
        pari[p][0] = cnode;
        syi[p] = evalLine( ab[p], tri[p] );
        cnode = p;
    }
}

void addLineDec( int p )
{
    //add ab[p] to lower envelope tree
    while ( ( cnode > 0 ) && ( cross( ab[p], ab[ cnode ] ) < trd[cnode] ) )
        cnode = pard[cnode][0];
    if ( cnode == 0 )
    {
        trd[p] = minf;
        pard[p][0] = cnode;
        syd[p] = evalLine( ab[p], minf );
        cnode = p;
    }
    else
    {
        trd[p] = cross( ab[p], ab[ cnode ] );
        pard[p][0] = cnode;
        syd[p] = evalLine( ab[p], trd[p] );
        cnode = p;
    }
}

int main()
{
	int i, j, k, ub;
	double c, d;
	double mxx;
	pdd ql;

	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%lf %lf", &ab[i].first, &ab[i].second );
	}
	sort( ab + 1, ab + n + 1 );

	//build upper envelope tree
	ab[0] = make_pair( 0, -1e300 );
	cnode = 0;
	for ( i = 1; i <= n; i++ )
		addLineInc( i );
		
	//build lower envelope tree
	ab[n+1] = make_pair( 0, 1e300 );
	cnode = 0;
	for ( i = n; i > 0; i-- )
		addLineDec( i );

    for ( j = 1; j <= 17; j++ )
    {
        for ( i = 1; i <= n; i++ )
        {
            pari[i][j] = pari[ pari[i][j-1] ][j-1];
            pard[i][j] = pard[ pard[i][j-1] ][j-1];
        }
    }

	scanf( "%d", &q );
	bool fl = 0;
	for ( i = 1; i <= q; i++ )
	{
		scanf( "%d %d", &j, &k );
		if ( fl )
		{
			k = k ^ xr;
			j = j ^ xr;
		}
		c = j;
		d = k;
		ql = make_pair( c, d );

		mxx = minf;

		ub = (int) (upper_bound( ab + 1, ab + n + 1, ql ) - ab);
		j = ub - 1;

		//listo j;
        for ( k = 17; k >= 0; k-- )
        {
            if ( ( pari[j][k] != 0 ) && ( syi[ pari[j][k] ] + eps < c * tri[ pari[j][k] ] + d ) )
            {
                j = pari[j][k];
            }
        }
        if ( syi[ j ] + eps < evalLine( ql, tri[ j ] ) )
			j = pari[j][0];
        if ( ( j != 0 ) && ( j != n+1 ) )
        {
            mxx = max( mxx, cross( ab[ j ], ql ) );
        }

		j = ub;
		//listo j;
        for ( k = 17; k >= 0; k-- )
        {
            if ( ( pard[j][k] != 0 ) && ( syd[ pard[j][k] ] > c*trd[ pard[j][k] ] + d + eps ) )
            {
                j = pard[j][k];
            }
        }
        if ( syd[ j ] > evalLine( ql, trd[ j ] ) + eps )
			j = pard[j][0];
        if ( ( j != 0 ) && ( j != n+1 ) )
        {
            mxx = max( mxx, cross( ab[ j ], ql ) );
        }

		printf( "%.9lf\n", mxx );
		if ( mxx > 1e-10 )
		{
//			printf( "%.8lf\n", mxx );
			fl = 0;
		}
		else
		{
//			printf( "No cross\n" );
			fl = 1;
		}
	}
	return 0;
}
