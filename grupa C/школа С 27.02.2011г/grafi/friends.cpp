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
#include <cstdio>

#define SP system("pause");
#define x first
#define y second

int maxn = 99999;

typedef long long int lli;

using namespace std;

lli n, m;
vector< int > g[ 2005 ];
int used[ 2005 ];
int br_level[ 2005 ];//sluji za otbelqzvane na koe nivo kolko pyti sme sre6tnali

void solve_bfs()//izpylnqvame standartno bfs kato otbelqzvame nivata na vseki vryh
{
    used[ 1 ] = 1;
    queue< int > q;
    q.push( 1 );
    int next, current;
    
    while ( !q.empty() )
    {
        current = q.front();
        q.pop();
        for ( int i = 0; i < g[ current ].size(); i++ ) 
        {
            next = g[ current ][ i ];
            if ( used[ next ] == 0 )
            {
                used[ next ] = used[ current ] + 1;//otbelqzvame nivoto na naslednika kato nivoto na ba6tata + 1
                q.push( next );
            }
        }
    }
    
    int br = 1, mx = -1;
    for ( int i = 1; i <= n; i++ ) br_level[ used[ i ] ]++;//uveli4avame sre6taniqta na nivoto na teku6tiq vryh i
    for ( int i = 1; i <= n; i++ ) //namirame max broi sre6tanti niva ili max broi vyrhove ot dadeno nivo
        if ( mx < br_level[ i ] ) mx = br_level[ i ];
    cout << mx << endl;
}
int main()
{
    cin >> n >> m;
    for ( int a, b, i = 0; i < m; i++ )
    {
        scanf("%d%d", &a, &b );//vyvejdame sys scanf za6toto e mnogo po-byrzo
                            //ako nqko jelae moje da opita da si testava zad4ata sys cin 
                            //sled tova sys scanf i da otbeleji razlikata
        g[ a ].push_back( b );
        g[ b ].push_back( a );
    }
    solve_bfs();
        SP;
	return 0;
}
