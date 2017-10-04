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

bool coin[ 1005 ];
int dp[ 1005 ][ 1005 ];

int find_sum( int s, int m )
{
    if ( s <= 0 ) return 0;
    if ( dp[ s ][ m ] > 0 ) return dp[ s ][ m ];
    
    if ( s < m ) m = s;
    
    if ( s == m && coin[ m ] ) dp[ s ][ m ] = 1;
    
    for ( int i = m; i > 0; i-- ) 
    {
        if ( coin[ i ] ) dp[ s ][ m ] += find_sum( s - i, i );
    }
    
    return dp[ s ][ m ];
    
}
int main()
{
    cin >> n >> k;
    
    for ( int i = 1; i <= k; i++ ) coin[ i ] = 1;
    
    cout << find_sum( n, k ) << endl;   
        SP;
	return 0;
}
