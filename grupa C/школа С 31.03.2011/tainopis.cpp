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

int main()
{
    string msg;
    string tb[ 10005 ];
    string res = "";
    
    getline( cin, msg );
    
    double nn = sqrt( double( msg.size() ) );
    int n = int( nn );
    
    int k = 0;
    
    for ( int i = 0; i < int( msg.size() ); i++ )
    {
        if ( msg[ i ] >= '0' && msg[ i ] <= '9' ) k += ( msg[ i ] - '0' );
    } 
    int br = 0;
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < n; j++ ) tb[ i ] += msg[ br++ ];
    }
    int r, i, j;
    /*for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < n; j++ ) cout << tb[ i ][ j ];
        cout << endl;
    }*/
    k %= n;
    for ( r = k; r < n; r++ )
    {
        //cout << res << endl;
        for ( i = r, j = 0; i < n; i++, j++ ) res += tb[ i ][ j ];
        for ( i = 0, j--; j < n; i++, j++ ) res += tb[ i ][ j ];
    }
    
    for ( int i = 0; i < int( res.size() ); i++ )
    {
        if ( res[ i ] >= 'A' && res[ i ] <= 'Z' ) cout << res[ i ];
    }
    cout << endl;
        SP;
	return 0;
}
