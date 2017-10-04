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

int n;
vector< int > pr;
vector< bool > can_make_sum;

int main()
{
    cin >> n;
    
    pr.resize( n + 2 );
    int sm = 0;
    
    for ( int i = 0; i < n; sm += pr[ i++ ] ) cin >> pr[ i ];
    
    can_make_sum.resize( sm + 2, 0 );
    
    can_make_sum[ 0 ] = 1;
    
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = sm; j >= 0; j-- ) 
        {
            if ( can_make_sum[ j ] )
            {
                can_make_sum[ j + pr[ i ] ] = 1;
                //cout << "YES " << j << endl;
            }
        }
    }
    int k;
    for ( k = sm / 2; k >= 1; k-- ) 
        if ( can_make_sum[ k ] ) break;
    cout << k << " " << sm - k << endl;
        SP;
	return 0;
}
