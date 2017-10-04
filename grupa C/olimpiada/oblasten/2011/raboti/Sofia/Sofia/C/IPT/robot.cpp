#include<cstdio>
using namespace std;

int m , n , r;
int ch_res , nch_res;

int abs ( int a ) {
	if ( a > 0 ) return a;
	return -a;
}

int main() {
	int k;
	scanf ( "%d%d%d%d" , &m , &n , &r , &k );
	int x = (int) ( ( r - 1 ) / n ) , y = ( r - 1 ) % n;
	for ( int i = 0;i < m;++i ) {
		for ( int j = 0;j < n;++j ) {
			if ( abs ( x - i ) + abs ( y - j ) > k ) continue;
			if ( ( abs ( x - i ) + abs ( y - j ) ) % 2 == 0 ) ch_res += i * n + j + 1;
			else nch_res += i * n + j + 1;
		}
	}
	if ( k % 2 == 0 ) printf ( "%d\n" , ch_res );
	else printf ( "%d\n" , nch_res );
	return 0;
}
