/*
TASK:ship
LANG:C++
*/
#include<iostream>
using namespace std;

long long res = 0;
int t[10001] , p[10001];
int n;

void swap ( int i , int j ) {
	res += ( t[i] + t[j] );
	int sw = p[i];
	p[i] = p[j];
	p[j] = sw;
	sw = t[i];
	t[i] = t[j];
	t[j] = sw;
	return;
}
int main() {
	cin >> n;
	for ( int i = 0;i < n;++i ) {
		cin >> t[i];
	}
	for ( int i = 0;i < n;++i ) {
		cin >> p[i];
	}
	for ( int i = 0;i < n;++i ) {
		if ( p[i] != i ) {
			if ( p[p[i]] == i ) {
				swap ( p[i] , i );
				i = 0;
				continue;
			}
			if ( t[p[i]] > t[p[p[i]]] ) {
				swap ( p[i] , p[p[i]] );
				swap ( i , p[i] );
				i = 0;
				continue;
			}
			if ( t[p[i]] <= t[p[p[i]]] ) {
				swap ( i , p[i] );
				i = 0;
				continue;
			}
		}
	}
	cout << res << "\n";
	return 0;
}
