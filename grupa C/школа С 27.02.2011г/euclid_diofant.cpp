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

int ext_euclid( int a, int b, int &x, int &y )
{
    int x1, y1;
    x = 1;
    x1 = 0;
    y = 0;
    y1 = 1;
    while ( a != b )
    {
        if ( a > b ) 
        {
            a -= b;
            x -= x1;
            y -= y1;
        }
        else
        {
            b -= a;
            x1 -= x;
            y1 -= y;
        }
    }
    return a;
}
int main()
{
    int a, b, d;
    cin >> a >> b >> d;
    a = abs( a );
    b = abs( b );
    d = abs( d );
    
    int x, y;
    int c;
    c = ext_euclid( a, b, x, y );
    if ( d % c == 0 ) 
    {
        a /= c;
        b /= c;
        d /= c;
        cout << c << endl;
        c = ext_euclid( a, b, x, y );
        int x1, y1;
        x1 = x * d;
        y1 = y * d;
        //cout <<"x0 i y0 " << x1 << " " << y1 << endl;
        for ( int i = -c; i <= c; i++ )
        {
            x = x1 - b * i;
            y = y1 + a * i;
            cout << x << " " << y << endl;
        }
    }
    else cout << "NR " << endl;
    
        SP;
	return 0;
}
