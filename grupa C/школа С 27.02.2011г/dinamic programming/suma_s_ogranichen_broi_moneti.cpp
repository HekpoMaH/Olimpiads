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
int dp[ 1005 ];
int coin[ 1005 ];

int main()
{
    cin >> n >> k;
    for ( int i = 0; i < k; i++ ) cin >> coin[ i ];
    
    dp[ 1 ] = 1;
    
    for ( int i = 0; i < k; i++ )
    {
        for ( int j = n; j > 0; j-- ) 
        {
            if ( dp[ j ] > 0 )
            {
                if ( j + coin[ i ] <= n )
                {
                    dp[ j + coin[ i ] ]++;
                }
            }
        }
    }
    
    cout << dp[ n ] << endl;
        SP;
	return 0;
}
