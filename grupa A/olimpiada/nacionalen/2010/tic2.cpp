#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1 << 10;

int n , t , d , s;
int f[MAXN];
vector < int > in[MAXN];
int h[MAXN][MAXN];

long long dp[MAXN][MAXN];
int used[MAXN][MAXN];
int dist[MAXN][MAXN];

vector < pair < int , int > > a[MAXN];

void read() {
	int i;
	int x , y , z;
	
	scanf ( "%d%d%d%d" , &n , &t , &d , &s );
	
	for (i = 1; i <= n; i++) {
		scanf ( "%d" , &f[i] );
		f[i] *= t;
	}
	
	for (i = 1; i < n; i++) {
		scanf ( "%d%d%d" , &x , &y , &z );
		a[x].push_back ( make_pair ( y , z ) );
		a[y].push_back ( make_pair ( x , z ) );
	}
	
	a[0].push_back ( make_pair ( 1 , d + 1 ) );
	a[1].push_back ( make_pair ( 0 , d + 1 ) );
}

void dfs2 ( int x , int y , int st , int z ) {
	dist[st][x] = z;
	int i;
	
	for (i = 0; i < (int)a[x].size(); i++)
		if ( a[x][i].first != y )
			dfs2 ( a[x][i].first , x , st , z + a[x][i].second );
}

void dfs ( int x , int y ) {
	int i , j;
	
	for (i = 0; i < (int)a[x].size(); i++)
		if ( a[x][i].first == y ) {
			a[x].erase ( a[x].begin() + i );
			-- i;
		} else {
			dfs ( a[x][i].first , x );
			
			for (j = 1; j <= n; j++)
				h[x][j] |= h[ a[x][i].first ][j];
		}
		
	h[x][x] = 1;
	for (i = 1; i <= n; i++)
		if ( h[x][i] )
			in[x].push_back ( i );
}

long long go ( int x , int y ) {
	long long &ans = dp[x][y];
	if ( used[x][y] ) return ans;
	used[x][y] = 1;
	
	ans = 0;
	long long cur;
	int i , j;
	int idx = -1;
	
	if ( h[x][y] )
		for (i = 0; i < (int)a[x].size(); i++)
			if ( h[ a[x][i].first ][y] )
				idx = i;
	
	for (i = 0; i < (int)in[x].size(); i++)
		if ( dist[x][ in[x][i] ] < dist[x][y] ) {
			if ( idx != -1 && in[ a[x][idx].first ][ in[x][i] ] ) continue;
			
			cur = -s;
			if ( dist[x][ in[x][i] ] <= d ) cur += f[x];
			
			for (j = 0; j < (int)a[x].size(); j++) {
				if ( j == idx )
					cur += go ( a[x][j].first , y );
				else
					cur += go ( a[x][j].first , in[x][i] );
			}
			
			if ( cur > ans ) ans = cur;
		} else
			break;
		
	cur = 0;
	
	if ( dist[x][y] <= d ) cur += f[x];
	
	for (j = 0; j < (int)a[x].size(); j++)
		cur += go ( a[x][j].first , y );
	
	if ( cur > ans )
		ans = cur;
	
	return ans;
}

int sorting_now;
int cmp ( int x , int y ) {
	return dist[sorting_now][x] < dist[sorting_now][y];
}

void solve() {
	int i;
	
	for (i = 1; i <= n; i++)
		dfs2 ( i , -1 , i , 0 );
	
	dfs ( 0 , -1 );
	
	for (i = 1; i <= n; i++) {
		sorting_now = i;
		sort ( in[i].begin() , in[i].end() , cmp );
	}
	
	printf ( "%lld\n" , go ( 1 , 0 ) );
}

int main() {
	read();
	solve();
	
	return 0;
}
