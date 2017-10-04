/*
TASK: ship
LANG: C++
*/
#include<cstdio>
#include<iostream>
using namespace std;

long long ans;

int t [ 16384 ], pos [ 16384 ], n, used [ 16384 ], minall;


void read()
{
	int i;
	scanf( "%d", &n );
	scanf( "%d", &t [ 0 ] );
	minall = t [ 0 ];
	for( i = 1; i < n; i++ )
	{
		scanf( "%d", &t [ i ] );
		if( t [ i ] < minall ) minall = t [ i ];
	}
	for( i = 0; i < n; i++ ) scanf( "%d", &pos [ i ] );
}


int min_swap( long long a, long long b)
{
	return (a < b) ? a : b;
}

void solve()
{
	int mint, first, last, cn, sumt;
	for( first = 0; first < n; first++ )
	{
		if( used [ first ] == 0 )
		{
			cn = 0;
			sumt = t [ first ];
			used [ first ] = 1;
			last = pos [ first ];
			mint = t [ first ];
			while( last != first )
			{
				sumt += t [ last ];
				cout<<t[first]<<" "<<t[last]<<endl;
				if( t [ last ] < mint ) mint = t [ last ];
				used [ last ] = 1;
				last = pos [ last ];
				cn++;
			}
			sumt -= mint;
		//	printf("%d %d %d %d\n", minall, mint, sumt, cn );
			ans += min_swap ( (sumt + ( cn*mint )) , (sumt + 2*( minall + mint ) + cn*minall ));
		//	printf("%I64d\n", ans );
		}
	}
	printf("%lld\n", ans );
}

int main()
{
	read();
	solve();
	return 0;
}
