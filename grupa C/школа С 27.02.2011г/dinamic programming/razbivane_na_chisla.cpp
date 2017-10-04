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

int n, k;
int dp[ 1005 ][ 1005 ];

int solve()
{
    for ( int i = 1; i <= n; i++ ) dp[ i ][ 1 ] = 1;
    for ( int i = 1; i <= n; i++ ) dp[ 1 ][ i ] = 1;
    
    for ( int i = 2; i <= n; i++ )
    {
        for ( int j = 2; j <= k; j++ )
        {
            if ( i < j ) dp[ i ][ j ] = dp[ i ][ i ];
            else if ( i == j ) dp[ i ][ j ] = 1 + dp[ i ][ j - 1 ];
            else dp[ i ][ j ] = dp[ i - j ][ j ] + dp[ i ][ j - 1 ];
        }
    }
    
    return dp[ n ][ k ];
}
int main()
{
    cin >> n >> k;
    
    cout << solve() << endl;
        SP;
	return 0;
}
