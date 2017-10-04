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

int koefic[ 100 ];

int main()
{
    int n, m;
    cin >> n >> m;
    
    int x = m;
    int br = 0;
    
    while ( x > 0 )
    {
        koefic[ br ] = x % 3;
        if ( koefic[ br ] == 2 ) koefic[ br ] = -1;
        x = ( x - koefic[ br++ ] ) / 3;
    }
    cout << m;
    x = 1;
    for ( int i = 0; i < n; i++ )
    {
        if ( koefic[ i ] == 0 ) cout << " ";
        x *= 3;
    }
    
    cout << endl;
    x = 1;
    for ( int i = 0; i < n - 1; i++ )
    {
        if ( koefic[ i ] == 1 ) cout << x << " ";
        x *= 3;
    }
    if ( koefic[ n - 1 ] == 1 ) cout << x;
    cout << endl;
        SP;
	return 0;
}
