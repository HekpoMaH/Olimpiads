#include<cstdio>
using namespace std;

int a[1000][1000];
int sbor[1000][1000];

int main() {
	int n , m , k;//m reda ,n koloni
	scanf ( "%d%d%d" , &m , &n , &k );
	for ( int i = 0;i < m;++i ) {
		for ( int j = 0;j < n;++j ) {
			scanf ( "%d" , &a[i][j] );
		}
	}
	sbor[0][0] = a[0][0];
	for ( int i = 1;i < n;++i ) {
		sbor[0][i] = sbor[0][i - 1] + a[0][i];
	}
	for ( int i = 1;i < m;++i ) {
		sbor[i][0] = sbor[i - 1][0] + a[i][0];
	}
	for ( int i = 1;i < m;++i ) {
		for ( int j = 1;j < n;++j ) {
			sbor[i][j] = sbor[i][j - 1] + sbor[i - 1][j] - sbor[i - 1][j - 1] + a[i][j];
		}
	}
	int max = sbor[k - 1][k - 1];
	int tek;
	for ( int j = 1;j < n - k;++j ) {
		tek = sbor[k - 1][j + k - 1] - sbor[k - 1][j - 1];
		if ( max < tek ) max = tek;
	}
	for ( int i = 1;i < m - k;++i ) {
		tek = sbor[i + k - 1][k - 1] - sbor[i - 1][k - 1];
		if ( max < tek ) max = tek;
	}
	for ( int i = 1;i <= m - k;++i ) {
		for ( int j = 1;j <= n - k;++j ) {
			tek = sbor[i + k - 1][j + k - 1] - sbor[i + k - 1][j - 1] - sbor[i - 1][k + j - 1] + sbor[i - 1][j - 1];
			if ( max < tek ) max = tek;
		}
	}
	printf ( "%d\n" , sbor[m - 1][n - 1] - max );
	return 0;
}
