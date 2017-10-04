#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n , m;
int t , s;

vector < pair < int , int > > a , b;
vector < int > f[1 << 8];
int used[1 << 8] , in[1 << 8];

void read() {
	int i , j , x;
	
	scanf ( "%d%d" , &m , &n );
	scanf ( "%d%d" , &t , &s );
	
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++) {
			scanf ( "%d" , &x );
			
			while ( x -- )
				a.push_back ( make_pair ( i , j ) );
		}
		
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++) {
			scanf ( "%d" , &x );
			
			while ( x -- )
				b.push_back ( make_pair ( i , j ) );
		}
}

int dfs ( int x ) {
	used[x] = 1;
	int i;
	
	for (i = 0; i < (int)f[x].size(); i++) 
		if ( in[ f[x][i] ] == -1 || (!used[ in[ f[x][i] ] ] && dfs ( in[ f[x][i] ] )) ) {
			in[ f[x][i] ] = x;
			return 1;
		}
		
	return 0;
}

int solve() {
	int i , j;
	int dist;
	
	if ( (int)a.size() != (int)b.size() )
		return 0;
	
	for (i = 0; i < (int)a.size(); i++)
		for (j = 0; j < (int)b.size(); j++) {
			dist = abs ( a[i].first - b[j].first ) + abs ( a[i].second - b[j].second );
			
			if ( dist <= t * s && (dist & 1) == ((t * s) & 1) )
				f[i].push_back ( j );
		}
		
	memset ( in , -1 , sizeof in );
		
	for (i = 0; i < (int)a.size(); i++) {
		memset ( used , 0 , sizeof used );
		
		if ( !dfs ( i ) ) 
			return 0;
	}
	
	return 1;
}

int main() {
	read();
	printf ( "%c\n" , solve() ? 'Y' : 'N' );
	
	return 0;
}
