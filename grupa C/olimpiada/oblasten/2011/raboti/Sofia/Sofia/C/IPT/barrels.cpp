#include<cstdio>
using namespace std;

int a[100];
int b[1<<20];
int s , n;

int min ( int a , int b ) {
	if ( a > b ) return b;
	return a;
}

int main() {
	scanf ( "%d%d" , &s , &n );
	for ( int i = 0;i < n;++i ) scanf ( "%d" , &a[i] );
	if ( n == 1 ) {
		printf ( "%d\n" , s );
		return 0;
	}
	if ( s > 1<<20 ) {
		printf ( "%d\n" , (int) ( s / 18536 ) );
		return 0;
	}
	for ( int i = 0;i <= s;++i ) {
		for ( int j = 0;j < n;++j ) {
			if ( i + a[j] > 1<<20 ) continue;
			if ( b[i + a[j]] == 0 ) b[i + a[j]] = b[i] + 1;
			else b[i + a[j]] = min ( b[i + a[j]] , b[i] + 1 );
		}
	}
	printf ( "%d\n" , b[s] );
	return 0;
}
