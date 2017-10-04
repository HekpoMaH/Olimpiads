/*
TASK:metro
LANG:C++
*/
#include<iostream>
using namespace std;

long long end_min[1001][100];

long long min ( long long a , long long b ) {
	if ( a > b ) return b;
	return a;
}

int main() {
	int n;
	cin >> n;
	int vis[1001];
	for ( int i = 1;i <= n;++i ) {
		cin >> vis[i];
		--vis[i];
	}
	for ( int i = 1;i <= n;++i ) {
		for ( int j = 0;j < 100;++j ) {
			long long tek_min = 99999999;
			
			if ( j < 98 ) {
				if ( j < vis[i] ) tek_min = min ( tek_min , end_min[i - 1][j + 1] + ( vis[i] - j ) * ( vis[i] - j ) );
				if ( j == vis[i] ) tek_min = min ( tek_min , end_min[i - 1][j + 1] + 1 );
				if ( j > vis[i] ) tek_min = min ( tek_min , end_min[i - 1][j + 1] + 7 * ( j - vis[i] ) );
			}
			
			if ( j < 99 ) {
				if ( j < vis[i] ) tek_min = min ( tek_min , end_min[i - 1][j + 2] + ( vis[i] - j ) * ( vis[i] - j ) );
				if ( j == vis[i] ) tek_min = min ( tek_min , end_min[i - 1][j + 2] + 1 );
				if ( j > vis[i] ) tek_min = min ( tek_min , end_min[i - 1][j + 2] + 7 * ( j - vis[i] ) );
			}
			
			if ( j < vis[i] ) tek_min = min ( tek_min , end_min[i - 1][j] + ( vis[i] - j ) * ( vis[i] - j ) );
			if ( j == vis[i] ) tek_min = min ( tek_min , end_min[i - 1][j] + 1 );
			if ( j > vis[i] ) tek_min = min ( tek_min , end_min[i - 1][j] + 7 * ( j - vis[i] ) );
			
			if ( j > 0  ) {
				if ( j < vis[i] ) tek_min = min ( tek_min , end_min[i - 1][j - 1] + ( vis[i] - j ) * ( vis[i] - j ) );
				if ( j == vis[i] ) tek_min = min ( tek_min , end_min[i - 1][j - 1] + 1 );
				if ( j > vis[i] ) tek_min = min ( tek_min , end_min[i - 1][j - 1] + 7 * ( j - vis[i] ) );
			}
			end_min[i][j] = tek_min;
		}
	}
	long long out = 99999999;
	for ( int i = 0;i < 100;++i ) {
		if ( end_min[n][i] < out ) out = end_min[n][i];
	}
	cout << out << "\n";	
	return 0;	
}
