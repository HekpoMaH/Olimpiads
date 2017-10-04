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

int a[ 1005 ];
int b[ 1005 ];
int c[ 1005 ][ 1005 ];

int main()
{
    int sa, sb;
    
    cin >> sa;
    for ( int i = 0; i < sa; i++ ) cin >> a[ i ];
    cin >> sb;
    for ( int i = 0; i < sb; i++ ) cin >> b[ i ];
    
    for ( int i = 0; i < sa; i++ ) 
    {
        c[ i ][ 0 ] = 0;
        if ( a[ i ] == b[ 0 ] ) c[ i ][ 0 ] = 1;
    }
    for ( int i = 0; i < sb; i++ ) 
    {
        c[ 0 ][ i ] = 0;
        if ( b[ i ] == a[ 0 ] ) c[ 0 ][ i ] = 1;
    }
    
    for ( int i = 1; i < sa; i++ )
    {
        for ( int j = 1; j < sb; j++ ) 
        {
            if ( a[ i ] == b[ j ] )c[ i ][ j ] = c[ i - 1 ][ j - 1 ] + 1;
            else c[ i ][ j ] = max( c[ i - 1 ][ j ], c[ i ][ j - 1 ] );
        }
    }
    
    cout << c[ sa - 1 ][ sb - 1 ] << endl;
        SP;
	return 0;
}
/*
4
1 3 5 7
5
1 3 4 7 9
-------------
3
*/
