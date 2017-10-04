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

#define x first
#define y second

int maxn = 99999;

typedef long long int lli;

using namespace std;

int n, k;
int p[ 25 ][ 200 ];
int c[ 25 ][ 200 ];

int main()
{
    cin >> n >> k;

    int t, a;

    for ( int i = 0; i < n; i++ )
    {
        cin >> t;

        for ( int j = 0; j < t; j++ )
        {
            cin >> a;
            p[ i ][ a ] = 1;
        }
    }

    for ( int i = 0; i < 200; i++ ) c[ 0 ][ i ] = p[ 0 ][ i ];

    for ( int i = 1; i < n; i++ )
    {
        for ( int x = 0; x < 200; x++ )
        {
            for ( int y = 0; y < 200; y++ )
            {
                if ( c[ i - 1 ][ x ] != 0 && p[ i ][ y ] != 0 )
                {
                    c[ i ][ x + y ] += c[ i - 1 ][ x ] * p[ i ][ y ];
                }
            }
        }
    }

    cout << c[ n - 1 ][ k ] << endl;
	return 0;
}
