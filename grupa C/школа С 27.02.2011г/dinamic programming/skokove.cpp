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

int tb[ 200 ][ 200 ];
int dp[ 200 ][ 200 ];
int n;

int main()
{
    cin >> n;
    
    for ( int i = 1; i <= n; i++ ) 
    {
        for ( int j = 1; j <= n; j++ ) cin >> tb[ i ][ j ];
    }
    dp[ 1 ][ 1 ] = 1;
    
    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = 1; j <= n; j++ )
        {
            if ( dp[ i ][ j ] > 0 && tb[ i ][ j ] != 0 )
            {
                if ( i + tb[ i ][ j ] <= n ) dp[ i + tb[ i ][ j ] ][ j ] += dp[ i ][ j ];
                if ( j + tb[ i ][ j ] <= n ) dp[ i ][ j + tb[ i ][ j ] ] += dp[ i ][ j ];
            }
        }
    }
    
    cout << dp[ n ][ n ] << endl;
        SP;
	return 0;
}
