/*
TASK:odd
LANG:C++
*/
#include<iostream>
using namespace std;

int a[1000000];

int main() {
	int n;
	cin >> n;
	for ( int i = 0;i < n;++i ) {
		cin >> a[i];
	}
	sort ( a , a + n );
	int tek = 1;
	for ( int i = 1;i < n;++i ) {
		if ( a[i] == a[i - 1] ) ++tek;
		if ( a[i] != a[i - 1] ) {
			if ( tek % 2 == 1 ) {
			cout << a[i - 1] << "\n";
				return 0;
			}
			tek = 1;
		}
	}
	return 0;
}
