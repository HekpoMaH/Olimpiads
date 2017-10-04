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

bool mark[ 1000000005 ];
vector< int > prosto;

void eratosten()//genenrirame vsi4ki prosti 4isla koito ni trqbvat
{
    for ( lli i = 2; i <= 100005; i++ )
    {
        if ( !mark[ i ] )
        {
            prosto.push_back( i );
            for ( lli j = i + i; j <= 100005; j += i )mark[ j ] = 1;
        }
    }
}
int main()
{
    int n;
    lli a;
    int br = 0;
    vector< int > ans;
    cin >> n;
    int cnt;
    eratosten();
    for ( int i = 0; i < n; i++ )
    {
        cin >> a;
        cnt = 1;
        for ( int j = 0; prosto[ j ] * prosto[ j ] <= a ; j++ ) 
        {
            br = 0;
            
            while ( a % prosto[ j ] == 0 )//broim kolko pyti se deli 4isloto na
                                        // vsqko prosto 4islo po malko ot kroena ot 4isloto
            {
                br++;
                a /= prosto[ j ];
            }
            cnt *= ( br + 1 );//umnojavame dosega namerenite deliteli
        }
        if ( a > 1 ) cnt *= 2;//ako 4isloto ne e napylno razlojeno to trqbva da udvoim delitelite
        
        ans.push_back( cnt );
    }
    
    for ( int i = 0; i < n; i++ ) cout << ans[ i ] << " ";
    cout << endl;
        SP;
	return 0;
}
