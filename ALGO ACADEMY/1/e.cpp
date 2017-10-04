#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int,int> pii;

int n, m, h;
long long be = (1LL<<62);
int d[10020];
bool ih[100020];

vector<pii> g[100020];

priority_queue<pii, vector<pii>, greater<pii> > pq;

void dejkstra( int v )
{
	int i, j, k, u;
	pii a;
	
	while ( pq.size() > 0 ) pq.pop();
	
	memset( d, 127, sizeof( d ) );
	pq.push( make_pair( 0, v ) );
	while ( pq.size() )
	{
		a = pq.top();
		pq.pop();
		k = a.first;
		v = a.second;
		if ( d[v] < k )
		{
			continue;
		}
		d[v] = k;
		for ( i = 0; i < (int) g[v].size(); i++ )
		{
			j = g[v][i].second;
			u = g[v][i].first;
			if ( d[u] > k+j )
			{
				d[u] = k+j;
				pq.push( make_pair( k+j, u ) );
			}
		}
	}
	
	long long c = 0;
	for ( i = 1; i <= n; i++ )
	{
		if ( !ih[i] ) c = c + d[i];
	}
	if ( c < be ) be = c;
}

int main()
{
	memset( ih, 0, sizeof( ih ) );
	int i, j, k, l;
	
	scanf( "%d %d %d", &n, &m, &h );
	for ( i = 1; i <= h; i++ )
	{
		scanf( "%d", &k );
		ih[k] = 1;
	}
	
	for ( i = 1; i <= m; i++ )
	{
		scanf( "%d %d %d", &j, &k, &l );
		g[j].push_back( make_pair( k, l ) );
		g[k].push_back( make_pair( j, l ) );
	}
	
	for ( i = 1; i <= n; i++ )
	{
		if ( ih[i] )
		{
			dejkstra( i );
		}
	}
	cout << be << endl;
	return 0;
}
