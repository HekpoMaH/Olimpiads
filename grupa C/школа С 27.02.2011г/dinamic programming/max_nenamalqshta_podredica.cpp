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
int dp[ 1005 ];

int main()
{
    int n;
    
    
    cin >> n;
    
    for ( int i = 0; i < n; i++ ) cin >> a[ i ];
    
    dp[ 0 ] = 1;
    int m;
    
    for ( int i = 1; i < n; i++ )
    {
        m = -1;
        
        for ( int j = i - 1; j >= 0; j-- ) 
        {
            if ( a[ i ] >= a[ j ] && dp[ j ] > 0 ) 
            {
                if ( m < dp[ j ] ) m = dp[ j ];
            }
        }    
        
        dp[ i ] = m + 1;
    }
    
    m = -1;
    for ( int i = 0; i < n; i++ ) 
        if ( m < dp[ i ] ) m = dp[ i ];
        
    cout << m << endl;
        SP;
	return 0;
}
/*
6
1 1 2 -3 4 -5
*/
