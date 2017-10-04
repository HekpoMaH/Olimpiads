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

string c = "";
string n, m;

void dev()
{
    int sz = max( n.size(), m.size() ) - 1;
    int i = n.size() - 1;
    int j = m.size() - 1;
    int k, p = 0, t, q;
    while ( sz >= 0 )
    {
        if ( i < 0 ) k = 0;
        else k = n[ i ] - '0';
        if ( j < 0 ) t = 0;
        else t = m[ j ] - '0';
        k -= p;
        if ( k >= t )
        {
            q = k - t;
            p = 0;
        }
        else
        {
            k += 10;
            p = 1;
            q = k - t;
        }
        c += ( q + '0' );
        q = 0;
        i--;
        j--;
        sz--;
    }
}
string mult( int k, string a )
{
    string q = "";
    int ost = 0;
    int p;
    
    for ( int i = 0; i < a.size(); i++ )
    {
        p = a[ i ] - '0';
        q += ( ( ( k * p + ost ) % 10 ) + '0' );
        if ( k * p + ost > 9 )
        {
            ost = ( k * p + ost ) / 10;
        }
        else ost = 0;
    }
    if ( ost > 0 ) q += ( ost + '0' );
    return q;
}
string sbor( string a, string b )
{
    string t = "";
    t += a[ 0 ];
    int sz = mix( a.size(), b.size() );
    sz--;
    int i = 1, j = 0
}
int main()
{
    
    cin >> n;
    cin >> m;
    /*if ( n.size() < m.size() ) swap( n, m );
    else if ( n.size() == m.size() )
    {
        int i;
        for ( i = 0; i < n.size(); i++ )
        {
            if ( n[ i ] < m[ i ] ) break;
        }
        if ( i < n.size() ) swap( n, m );
    }*/
    int k;
    cin >> k;
    
    dev();
    string t = mult( k / 10, c );
    string w = mult( k % 10, c );
    cout << t << endl;
    cout << w << endl;
    string h = sbor( t, w );
    cout << h << endl;
    
    
    
    
        SP;
	return 0;
}
