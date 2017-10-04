#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int,int> pii;

vector<pii> bf;

int n;
int le[1<<16];
char col[1024][1024];
bool onstack[1<<16];
vector<int> g[1<<16];

void sc( int x, int y, char c )
{
	if ( x > y )
		swap( x, y );
	col[x][y-1024] = c;
}

char gc( int x, int y )
{
	if ( x > y ) 
	swap( x, y );
	return col[x][y-1024];
}

int dfs( int v, int par, char c )
{
	onstack[v] = 1;
	int u, i;
	for ( ; le[v] < (int) g[v].size(); le[v]++ )
	{
		i = le[v];
		u = g[v][i];
		if ( onstack[u] && u != par )
		{
			sc( u, v, c );
			le[v]++;
			onstack[v] = 0;
			return u;
		}
		else if ( u != par )
		{
			int k = dfs( u, v, (c=='R') ? 'B' : 'R' );
			if ( k != -1 )
			{
				sc( u, v, c );
			}
			if ( k != -1 && k != v )
			{
				le[v]++;
				onstack[v] = 0;
				return k;
			}
		}
	}
	onstack[v] = 0;
	return -1;
}

void colorTree( int v, char nc )
{
	int u;
	for ( int i = 0; i < (int) g[v].size(); i++ )
	{
		u = g[v][i];
		if ( gc( v, u ) == 0 )
		{
			sc( u, v, nc );
			u = g[v][i];
			nc = ((nc == 'R') ? 'B' : 'R');
			colorTree( u, nc );
		}
	}
}

int main()
{
	int i, j, k;
	
	memset( col, -1, sizeof( col ) );
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d %d", &j, &k );
		if ( col[j][k] == -1 )
			col[j][k] = 0;
		else
		{
			bf.push_back( make_pair( j, k ) );
			bf.push_back( make_pair( k, j ) );
			col[j][k] = -1;
		}
	}
	
	for ( i = 0; i < 1024; i++ )
	{
		for ( j = 0; j < 1024; j++ )
		{
			if ( col[i][j] == 0 )
			{
				g[i].push_back( j + 1024 );
				g[j+1024].push_back( i );
			}
		}
	}
	
	memset( le, 0, sizeof( le ) );
	memset( onstack, 0, sizeof( onstack ) );
	for ( i = 0; i < 2048; i++ )
	{
		dfs( i, -1, 'R' );
	}
	
	for ( i = 0; i < 2048; i++ )
	{
		colorTree( i, 'R' );
	}
	
	for ( int i = 0; i < (int) bf.size(); i++ )
	{
		printf( "%d %d %c\n", bf[i].first, bf[i].second, (i&1) ? 'R' : 'B' );
	}
	for ( i = 0; i < 1024; i++ )
	{
		for ( j = 0; j < (int) g[i].size(); j++ )
		{
			printf( "%d %d %c\n", i, g[i][j]-1024, col[i][ g[i][j]-1024 ] );
		}
	}
	
	return 0;
}
