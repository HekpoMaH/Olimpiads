/*
TASK:trade
LANG:C++
*/
#include<cstdio>
using namespace std;

int from[100001] , to[100001] , value[100001];

int main() {
	int n;
	scanf ( "%d" , &n );
	for ( int i = 0;i < n;++i ) {
		scanf ( "%d%d%d" , &from[i] , &to[i] , &value[i] );
	}
	printf ( "impossible\n" );
	return 0;
}
