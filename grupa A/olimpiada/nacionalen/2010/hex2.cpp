#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

long long r1 , r2 , r3;

long long b[8];
vector < int > a[8];

int used[1 << 17];
vector < int > f;

void read() {
	int i , j , x;
	
	memset ( used , 0 , sizeof used );
	r1 = r2 = r3 = 0;
	f.clear();
	
	for (i = 1; i <= 3; i++) {
		a[i].clear();
		scanf ( "%d" , &x );
		b[i] = x;
		
		for (j = 2; j * j <= x; j++)
			if ( x % j == 0 ) {
				a[i].push_back ( j );
				used[j] ++;
				
				while ( x % j == 0 ) x /= j;
			}
			
		if ( x > 1 ) {
			a[i].push_back ( x );
			used[x] ++;
		}
	}
}

int prime ( int x ) {
	for (int i = 2; i * i <= x; i++)
		if ( x % i == 0 )
			return 0;
	
	return 1;
}

int valid () {
	int i , j , k;

	for (i = 1; i <= 6; i++)
		for (j = i + 1; j <= 6; j++)
			for (k = j + 1; k <= 6; k++) {
				if ( __gcd ( b[i] , __gcd ( b[j] , b[k] ) ) > 1 )  
					return 0;
				
				if ( __gcd ( b[i] , b[j] ) == 1 && __gcd ( b[i] , b[k] ) == 1 && __gcd ( b[j] , b[k] ) == 1 )
					return 0;
			}
			
	return 1;
}

void go ( int x ) {
	if ( r1 > 0 && r1 + r2 + r3 < b[4] + b[5] + b[6] ) return ;
	int i , j , k , d , e;
	int cnt , bad;
	
	for (i = 1; i < x - 1; i++)
		for (j = i + 1; j < x - 1; j++) {
			if ( __gcd ( b[i] , __gcd ( b[j] , b[x - 1] ) ) > 1 )
				return ;
			
			if ( __gcd ( b[i] , b[j] ) == 1 && __gcd ( b[i] , b[x - 1] ) == 1 && __gcd ( b[j] , b[x - 1] ) == 1 )
				return ;
		}
	
	if ( x == 7 ) {
		r1 = b[4];
		r2 = b[5];
		r3 = b[6];
			
		return ;
	}
	
	for (i = 0; i < (1 << (int)a[1].size()); i++)
		for (j = 0; j < (1 << (int)a[2].size()); j++)
			for (k = 0; k < (1 << (int)a[3].size()); k++) {
				b[x] = 1;
				cnt = 0;
				bad = 0;
			
				for (d = 0; d < (int)a[1].size(); d++)
					if ( (i & (1 << d)) ) {
						if ( used[ a[1][d] ] == 2 ) bad = 1;
						used[ a[1][d] ] ++;
						++ cnt;
						a[x].push_back ( a[1][d] );
						b[x] *= a[1][d];
					}
					
				for (d = 0; d < (int)a[2].size(); d++)
					if ( (j & (1 << d)) ) {
						if ( used[ a[2][d] ] == 2 ) bad = 1;
						used[ a[2][d] ] ++;
						++ cnt;
						a[x].push_back ( a[2][d] );
						b[x] *= a[2][d];
					}
					
				for (d = 0; d < (int)a[3].size(); d++)
					if ( (k & (1 << d)) ) {
						if ( used[ a[3][d] ] == 2 ) bad = 1;
						
						used[ a[3][d] ] ++;
						++ cnt;
						a[x].push_back ( a[3][d] );
						b[x] *= a[3][d];
					}
					
				if ( !bad ) {
					go ( x + 1 );
					
					if ( x >= 5 ) {
						for (d = 4; d <= 5; d++) {
							for (e = 0; e < 2; e++) {
								if ( !used[ f[e] ] ) {
									if ( d == 5 && x == 5 ) continue;
									
									used[ f[e] ] = 1;
									
									b[d] *= f[e];
									b[x] *= f[e];
									
									go ( x + 1 );
									
									if ( x == 6 && d == 4 && !used[ f[2] ] ) {
										b[5] *= f[2];
										b[x] *= f[2];
										
										go ( x + 1 );
										
										b[5] /= f[2];
										b[x] /= f[2];
									}
									
									b[d] /= f[e];
									b[x] /= f[e];
									
									used[ f[e] ] = 0;
								}
							}
						}
					}
				}
				
				while ( cnt -- ) {
					used[ a[x].back() ] --;
					a[x].pop_back();
				}
			}
}

void solve() {
	int i , j;
		
	b[4] = b[5] = b[6] = 1;
	
	for (i = 1; i <= 3; i++) {
		sort ( a[i].begin() , a[i].end() );
		
		for (j = 0; j < (int)a[i].size(); j++)
			if ( used[ a[i][j] ] == 2 ) {
				a[i].erase ( a[i].begin () + j );
				-- j;
			}
			
		while ( (int)a[i].size() > 3 ) a[i].pop_back();
	}
	
	for (i = 2; i <= 100000; i++)
		if ( !used[i] && prime ( i ) && (int)f.size() < 6 )
			f.push_back ( i );

	r1 = -1;
	go ( 4 );
	
	if ( r1 < 0 )
		printf ( "0\n" );
	else
		printf ( "%lld %lld %lld\n" , r1 , r2 , r3 );
}

int main() {
	read();
	solve();
	
	read();
	solve();
	
	return 0;
}
