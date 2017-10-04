#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int a, b, c, d;
long long f[64];
long long co[64][64];
long long ans = 0, all, st;

long long gc( int n, int k )
{
	if ( k == 0 ) return 1;
	if ( n < k ) return 0;
	if ( co[n][k] != -1 ) return co[n][k];
	co[n][k] = gc( n-1, k ) + gc( n-1, k-1 );
	return co[n][k];
}

void bt( int k, int p )
{
//	printf( "BT %d %d %lld %lld\n", k, p, all, st );
	if ( k == a )
	{
		if ( st + c-p -d-d+2 > 0 )
			all = all + st+c-p-d-d+2;

		ans = ans + gc( all, b )*f[a]*f[b];
		if ( st + c-p -d-d+2 > 0 )
			all = all -( st+c-p-d-d+2);
		return;
	}
	
	for ( int i = p+1; i <= c; i++ )
	{
		if ( k == 0 )
		{
			st = i-1;
			bt( k+1, i );
		}
		else
		{
			if ( i-p-1-d-d+2 > 0 )
			{
				all = all + (i-p-1-d-d+2);
			}
			bt( k+1, i );
			if ( i-p-1-d-d+2 > 0 )
			{
				all = all - (i-p-1-d-d+2);
			}
		}
	}
}

int main()
{
	//int i, j, k, fl;
	int i;
	int all;
	
	f[0] = 1;
	for ( i = 1; i <= 60; i++ )
	{
		f[i] = f[i-1]*i;
	}
	
	memset( co, -1, sizeof( co ) );
	
	scanf( "%d %d %d %d", &a, &b, &c, &d );
	

	
	ans = 0;
	all = 0;
	
	bt( 0, 0 );
	
	cout << ans << "\n";

	return 0;
}

