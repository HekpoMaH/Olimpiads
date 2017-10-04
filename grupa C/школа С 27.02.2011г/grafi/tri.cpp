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

int n, m;
bool g[ 2005 ][ 2005 ];
pair< int, int > fr[ 2005 ];

int main()
{
    cin >> n >> m;
    for ( int i = 0; i < m; i++ )
    {
        cin >> fr[ i ].x >> fr[ i ].y;
        g[ fr[ i ].x ][ fr[ i ].y ] = 1;
        g[ fr[ i ].y ][ fr[ i ].x ] = 1;
    }
    
    lli mn = maxn;
    
    for ( int i = 0; i < m; i++ )//za vsqko rebro 
    {
        int j;
        for ( j = 1; j <= n && g[ fr[ i ].x ][ j ] == 0 || g[ fr[ i ].y ][ j ] == 0 ; j++ );//tyrsim pyrviqt vryh
                                                                                            //koito obrazuva tiygylnik
        if ( j <= n )
        {
            //ako sme namerili triygylnik proverqvame dali sumata mu e min
            if ( fr[ i ].x + fr[ i ].y + j < mn ) 
            {
                mn = fr[ i ].x + fr[ i ].y + j;
            }
        }
    }
    cout << mn << endl;
        SP;
	return 0;
}
