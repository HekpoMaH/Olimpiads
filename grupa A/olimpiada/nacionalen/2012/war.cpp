#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1 << 20;
const int INF = 1 << 30;

int n;
int last[MAX];
int to[MAX * 2];
int next[MAX * 2];
int cost[MAX * 2];
int adj[MAX];
int cc;

vector < int > f;
int cnt[MAX];

int par[MAX];
int up[MAX];
queue < int > q;

int mn1[MAX] , mn2[MAX] , mx1[MAX] , mx2[MAX];
int root;

char buf[30000000 + 5];

void read() {
	int x , y , z;
	int i , j;
	
	cc = 2;
	
    fread ( buf , 30000000 , 1 , stdin );
	
	n = 0;
	j = 0;
	while ( buf[j] < '0' || buf[j] > '9' ) ++ j;
	for (; !( buf[j] < '0' || buf[j] > '9'); j++) {
        n = n * 10 + (buf[j] - '0');
    }
	
	for (i = 1; i < n; i++) {
        x = y = z = 0;
		while ( buf[j] < '0' || buf[j] > '9' ) ++ j;
       	for (; !( buf[j] < '0' || buf[j] > '9'); j++) {
            x = x * 10 + (buf[j] - '0');
        }
        while ( buf[j] < '0' || buf[j] > '9' ) ++ j;
       	for (; !( buf[j] < '0' || buf[j] > '9'); j++) {
            y = y * 10 + (buf[j] - '0');
        }
        while ( buf[j] < '0' || buf[j] > '9' ) ++ j;
       	for (; !( buf[j] < '0' || buf[j] > '9'); j++) {
            z = z * 10 + (buf[j] - '0');
        }		
        
		++ adj[x];
		++ adj[y];
		
		to[cc] = y;
		to[cc + 1] = x;
		
		next[cc] = last[x];
		next[cc + 1] = last[y];
		
		cost[cc] = z;
		cost[cc + 1] = z;
		
		last[x] = cc;
		last[y] = cc + 1;
		
		cc += 2;
	}
}

void bfs1 ( int x ) {
	int i;
	
	par[x] = -1;
	q.push ( x );
	
	while ( !q.empty() ) {
		x = q.front();
		q.pop();
		
		for (i = last[x]; i > 0; i = next[i]) {
			if ( to[i] != par[x] ) {
				up[ to[i] ] = cost[i];
				par[ to[i] ] = x;
				q.push ( to[i] );
			}
		}
	}
}

void bfs2() {
	int i , x;
	
	for (i = 1; i <= n; i++) {
		cnt[i] = adj[i] - (i != root);
		
		if ( adj[i] == 1 ) {
			q.push ( i );
		}
	}
	
	while ( !q.empty() ) {
		x = q.front();
		q.pop();
		
// 		printf ( " -- %d   %d   %d\n" , x , par[x] , cnt[ par[x] ] );
		
		f.push_back ( x );
		if ( par[x] && !(-- cnt[ par[x] ]) ) {
			q.push ( par[x] );
		}
	}
}

void solve() {
	if ( n == 2 ) {
		printf ( "1 0\n" );
		return ;
	}
	int i , j;
	int x , y , z;
	int idx = -1 , ans = INF;
	
	root = -1;
	for (i = 1; i <= n; i++) {
		if ( adj[i] > 1 ) {
			root = i;
			break;
		}
	}
	
// 	printf ( "root = %d\n" , root );
	
	bfs1 ( root );
	bfs2();
	
	for (i = 1; i <= n; i++) {
		mn1[i] = mn2[i] = INF;
		mx1[i] = mx2[i] = -INF;
		
		if ( adj[i] == 1 ) {
			mn1[i] = 0;
			mx1[i] = 0;
		}
	}
	
	for (i = 0; i + 1 < (int)f.size(); i++) {
		x = f[i];
		y = par[ f[i] ];
		
		if ( mn1[x] + up[x] < mn1[y] ) {
			mn2[y] = mn1[y];
			mn1[y] = mn1[x] + up[x];
		} else {
			if ( mn1[x] + up[x] < mn2[y] ) {
				mn2[y] = mn1[x] + up[x];
			}
		}
		
		if ( mx1[x] + up[x] > mx1[y] ) {
			mx2[y] = mx1[y];
			mx1[y] = mx1[x] + up[x];
		} else {
			if ( mx1[x] + up[x] > mx2[y] ) {
				mx2[y] = mx1[x] + up[x];
			}
		}/*
		
		printf ( "(%d,%d)    (%d,%d)    (%d,%d)\n" , x , y , 
							mn1[x] , mn2[x] , mx1[x] , mx2[x] );*/
	}
	
	for (i = (int)f.size() - 1; i >= 0; i--) {
		x = f[i];
		if ( adj[x] == 1 ) continue;
		
		for (j = last[x]; j > 0; j = next[j]) {
			if ( to[j] == par[x] ) continue;
			y = to[j];
			z = cost[j];
			
// 			printf ( "%d %d   %d\n" , x , cost[j] , to[j] );
			
			if ( mn1[x] - z == mn1[y] ) {
				if ( mn2[x] + z < mn1[y] ) {
					mn2[y] = mn1[y];
					mn1[y] = mn2[x] + z;
				} else {
					if ( mn2[x] + z < mn2[y] ) {
						mn2[y] = mn2[x] + z;
					}
				}
			} else {
				if ( mn1[x] + z < mn1[y] ) {
					mn2[y] = mn1[y];
					mn1[y] = mn1[x] + z;
				} else {
					if ( mn1[x] + z < mn2[y] ) {
						mn2[y] = mn1[x] + z;
					}
				}
			}
			
			if ( mx1[x] - z == mx1[y] ) {
				if ( mx2[x] + z > mx1[y] ) {
					mx2[y] = mx1[y];
					mx1[y] = mx2[x] + z;
				} else {
					if ( mx2[x] + z > mx2[y] ) {
						mx2[y] = mx2[x] + z;
					}
				}
			} else {
				if ( mx1[x] + z > mx1[y] ) {
					mx2[y] = mx1[y];
					mx1[y] = mx1[x] + z;
				} else {
					if ( mx1[x] + z > mx2[y] ) {
						mx2[y] = mx1[x] + z;
					}
				}
			}
		}
	}
	
	for (i = 1; i <= n; i++) {
		x = i;
// 		printf ( "%d    (%d,%d)  (%d,%d)\n" , i , mn1[x] , mn2[x] , mx1[x] , mx2[x] );
		
		if ( adj[i] == 1 ) {
			if ( mx1[i] - mn2[i] < ans ) {
				ans = mx1[i] - mn2[i];
				idx = i;
			}
		} else {
			if ( mx1[i] - mn1[i] < ans ) {
				ans = mx1[i] - mn1[i];
				idx = i;
			}
		}
	}
	
	printf ( "%d %d\n" , idx , ans );
}

int main() {
	read();
	solve();
	
	return 0;
}
