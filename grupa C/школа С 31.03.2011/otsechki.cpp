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

vector< pair< int, int > > nachalo, krai;
vector< int > koord;
int n;

int main()
{
    lli from, to, cost;
    cin >> n;
    for ( int i = 0; i < n; i++ )
    {
        cin >> from >> to >> cost;
        nachalo.push_back( make_pair( from, cost ) );
        krai.push_back( make_pair( to, cost ) );
        koord.push_back( from );
        koord.push_back( to );
    }
    
    sort( nachalo.begin(), nachalo.end() );
    sort( krai.begin(), krai.end() );
    sort( koord.begin(), koord.end() );
    koord.resize( unique( koord.begin(), koord.end() ) - koord.begin() );
    reverse( nachalo.begin(), nachalo.end() );
    reverse( krai.begin(), krai.end() );
    
    lli res = 0, sm = 0, zaEdinica = 0;
    lli sz = int( koord.size() );
    
    for ( int i = 0; i < sz; i++ )
    {
        if ( i > 0 )
        {
            sm += ( koord[ i ] - koord[ i - 1 ] ) * zaEdinica;
        }
        sm = max( sm, 0LL );
        res = max( sm, res );
        
        while ( krai.size() > 0 && krai.back().x == koord[ i ] )
        {
            zaEdinica -= krai.back().y;
            krai.pop_back();
        }
        while ( nachalo.size() > 0 && nachalo.back().x == koord[ i ] )
        {
            zaEdinica += nachalo.back().y;
            nachalo.pop_back();
        }
    }
    
    cout << res << endl;
        SP;
	return 0;
}
