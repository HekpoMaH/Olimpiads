/*
Contest:
Task:
*/
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <set>

#define SP system("pause");
#define x first
#define y second

int maxn = 99999;

typedef long long int lli;

using namespace std;

int mem[ 1005 ];
pair< int, int > item[ 1005 ];
int n, m;

int fill_in( int k, int next )
{
    if ( mem[ k ] != -1 ) return mem[ k ];
    int mx = 0;
    int sp;
    //cout << k << endl;
    for ( int i = next; i < n; i++ )
    {
        if ( k - item[ i ].x >= 0 )
        {
            sp = fill_in( k - item[ i ].x, i + 1 ) + item[ i ].y;
            if ( sp > mx )
            {
                //cout << " " << sp << endl;
                mx = sp;
            }
        }
    }
    mem[ k ] = mx;
    return mem[ k ];
}
int main()
{
    cin >> n >> m;
    for ( int i = 0; i < n; i++ ) cin >> item[ i ].x >> item[ i ].y;

    for ( int i = 0; i < m + 5; i++ ) mem[ i ] = -1;
    for ( int i = 0; i < n; i++ ) cout << item[ i ].x << " " << item[ i ].y << endl;
    cout << fill_in( m, 0 ) << endl;
        SP;
	return 0;
}
/*
4 6
1 5
2 3
3 2
4 10
*/
