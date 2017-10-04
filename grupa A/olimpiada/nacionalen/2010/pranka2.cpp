// typ si top40
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int dx[] = { -1 , 0 , 0 , 1 };
int dy[] = { 0 , -1 , 1 , 0 };

int n , m;
char a[1024][32];
int in[1 << 15] , used[1 << 15];
vector < int > f[1 << 15];
vector < int > left , res;

void read() {
	int i;
	
	scanf ( "%d%d" , &n , &m );
	for (i = 0; i < n; i++)
		scanf ( "%s" , a[i] );
}

int dfs ( int x ) {
	used[x] = 1;
	int i;
	
	for (i = 0; i < (int)f[x].size(); i++)
		if ( in[ f[x][i] ] == -1 || (!used[ in[ f[x][i] ] ] && dfs ( in[ f[x][i] ] )) ) {
//			printf ( "%d %d    %d %d\n" , x / m , x % m , f[x][i] / m , f[x][i] % m );
			in[ f[x][i] ] = x;
			return 1;
		}
		
	return 0;
}

void solve() {
	int i , j , d;
	int x , y;
	int l = 0 , r = 0;
	
	memset ( in , -1 , sizeof in );
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if ( a[i][j] == '#' ) continue;
			
			if ( (i & 1) ^ (j & 1) ) {
				left.push_back ( i * m + j );
				++ l;
			} else
				++ r;
			
			for (d = 0; d < 4; d++) {
				x = i + dx[d];
				y = j + dy[d];
				
				if ( x >= 0 && y >= 0 && x <= i && y < m ) {
					if ( a[x][y] == '#' )
						continue;
					
					if ( (i & 1) ^ (j & 1) )
						f[i * m + j].push_back ( x * m + y );
					else
						f[x * m + y].push_back ( i * m + j );
				}
			}
		}
		
//		printf ( " -- %d\n" , i );
		
		while ( (int)left.size() ) {
			memset ( used , 0 , sizeof used );
			
//			printf ( "%d %d\n" , left.back() / m , left.back() % m );
			
			if ( dfs ( left.back() ) )
				left.pop_back();
			else 
				break;
		}
		
		if ( !(int)left.size() && l == r )
			res.push_back ( i + 1 );
	}
	
	printf ( "%d\n" , (int)res.size() );
	for (i = 0; i < (int)res.size(); i++) {
		printf ( "%d" , res[i] );
		
		if ( i + 1 == (int)res.size() )
			printf ( "\n" );
		else
			printf ( " " );
	}
}

int main() {
	read();
	solve();
	
	return 0;
}
