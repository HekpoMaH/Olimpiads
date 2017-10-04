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

bool tb[ 1006 ][ 1006 ];
int dist[ 1006 ][ 1006 ];
int n, X, Y;
pair< int, int > st, ed, point;

pair< int, int > get_coordinates( int k )//vry6ta koordinatite na kletka
{
    int p = k % n;//za kolonata
    if ( p == 0 ) p = n;//ako ostatyka e 0 tova e poslednata kolona
    return make_pair( 1 + ( k - 1 ) / n, p );
}

void bfs()
{
    queue< pair< int, int > > q;
    q.push( st );
    pair< int, int > p;
    dist[ st.x ][ st.y ] = 0;
    
    while ( !q.empty() )
    {
        p = q.front();
        q.pop(); 
        cout << p.x << " " << p.y << endl;
        if ( p.x == ed.x && p.y == ed.y ) break;
        
        for ( int i = p.x + 1; !tb[ i ][ p.y ]; i++ )//proverqvame kolonata nadolu 
        {
            if ( dist[ i ][ p.y ] == -1 ) 
            {
                dist[ i ][ p.y ] = dist[ p.x ][ p.y ] + 1;
                q.push( make_pair( i, p.y ) );
            }
        }   
        for ( int i = p.x - 1; !tb[ i ][ p.y ]; i-- )//proverqvame kolonata nagore
        {
            if ( dist[ i ][ p.y ] == -1 ) 
            {
                dist[ i ][ p.y ] = dist[ p.x ][ p.y ] + 1;
                q.push( make_pair( i, p.y ) );
            }
        } 
        for ( int i = p.y + 1; !tb[ p.x ][ i ]; i++ ) //proverqvamr reda nadqsno
        {
            if ( dist[ p.x ][ i ] == -1 ) 
            {
                dist[ p.x ][ i ] = dist[ p.x ][ i ] + 1;
                q.push( make_pair( p.x, i ) );
            }
        }   
        for ( int i = p.y - 1; !tb[ p.x ][ i ]; i-- ) // proverqvame reda nalqvo
        {
            if ( dist[ p.x ][ i ] == -1 ) 
            {
                dist[ p.x ][ i ] = dist[ p.x ][ i ] + 1;
                q.push( make_pair( p.x, i ) );
            }
        } 
    }
}
int main()
{
    memset( dist, -1, sizeof( dist ) );
    memset( tb, 0, sizeof( tb ) );
    
    cin >> n >> X >> Y;
    
    for ( int i = 0; i <= n + 1; i++ )
    {
        tb[ i ][ 0 ] = 1;
        tb[ 0 ][ i ] = 1;
        tb[ n + 1 ][ i ] = 1;
        tb[ i ][ n + 1 ] = 1; 
    }
    
    st = get_coordinates( X );
    ed = get_coordinates( Y );
    
    int br;
    cin >> br;
    int a;
    
    for ( int i = 0; i < br; i++ )
    {
        cin >> a;
        point = get_coordinates( a );
        tb[ point.x ][ point.y ] = 1;
    }
    
    for ( int i = 0; i <= n + 1; i++ )
    {
        for ( int j = 0; j <= n + 1; j++ ) cout << tb[ i ][ j ] << " ";
        cout << endl;
    }
    bfs();
    
    for ( int i = 0; i <= n + 1; i++ )
    {
        for ( int j = 0; j <= n + 1; j++ ) cout << dist[ i ][ j ] << " ";
        cout << endl;
    }
    cout << dist[ ed.x ][ ed.y ] << endl;
        SP;
	return 0;
}
