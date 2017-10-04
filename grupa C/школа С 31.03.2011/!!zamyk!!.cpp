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

struct point
{
    int x, y, moves;
    bool operator == ( const point &other ) const
    {
        return x == other.x && y == other.y;
    }
    bool operator < ( const point &other ) const
	{
        return x != other.x ? x < other.x : y < other.y;
    }

};

string g[ 100 ];
bool used[ 100 ][ 100 ];
int mx[] = { 0, 0, 1, -1 };
int my[] = { 1, -1, 0, 0 };
int n, m;
int P;
int ans = -1;
int br = 0;
vector< point > prince;
point ely, ext, a;
    

int bfs( point s, point e )
{
    memset( used, 0, sizeof( used ) );
    queue< point > q;
    point cur, next;
    
    q.push( s );
    used[ s.x ][ s.y ] = 1;
    
    while ( !q.empty() )
    {
        cur = q.front();
        q.pop();
        
        if ( cur == e ) return cur.moves;
        
        next.moves = cur.moves + 1;
        
        for ( int i = 0; i < 4; i++ )
        {
            next.x = ( cur.x + mx[ i ] + n ) % n;
            next.y = ( cur.y + my[ i ] + m ) % m;
            
            if ( !used[ next.x ][ next.y ] && g[ next.x ][ next.y ] == '.' ) 
            {
                used[ next.x ][ next.y ] = 1;
                q.push( next );
            }
        }
        
    }
    return -1;
}

void perm( int k )
{
    if ( k == P )
    {
        br = bfs( ely, prince[ 0 ] );
        cout << br << endl;
        for ( int i = 1; i < P; i++ )
        {
            br += bfs( prince[ i - 1 ], prince[ i ] );
            cout << br << endl;
        }
        br += bfs( prince[ P - 1 ], ext );
        cout << br << endl;SP;
        ans = max( ans, br );
    }
    
    else 
    {
        for ( int i = k; i < P; i++ )
        {
            swap( prince[ i ], prince[ k ] );
            perm( k + 1 );
            swap( prince[ i ], prince[ k ] );   
        } 
    }
}
int main()
{
    cin >> n >> m;
    
    for ( int i = 0; i < n; i++ ) cin >> g[ i ];
    
    
    
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < m; j++ ) 
        {
            if ( g[ i ][ j ] == 'E' )
            {
                ely.x = i;
                ely.y = j;
                ely.moves = 0;
                g[ i ][ j ] = '.';
            }
            if ( g[ i ][ j ] == 'X' )
            {
                ext.x = i;
                ext.y = j;
                ext.moves = 0;
                g[ i ][ j ] = '.';
            }
            else if ( g[ i ][ j ] == 'P' )
            {
                a.x = i;
                a.y = j;
                a.moves = 0;
                //cout << a.x << " " << a.y << endl;
                prince.push_back( a );
            }
        }
    }
    P = prince.size();
    cout << ext.x << " " << ext.y << endl;
    cout << ely.x << " " << ely.y << endl;
    if ( P == 0 )
    {
        ans = bfs( ely, ext );
    }
    else
    {
        sort( prince.begin(), prince.end() );
        perm( 0 );
    }
    cout << ans << endl;
        SP;
	return 0;
}
