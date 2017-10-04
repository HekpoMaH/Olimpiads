//Task: reflatten
//Author: Yordan Chaparov

#include <cstdio>

int n;
long long a[1<<17], ps[1<<17], k;

long long dp[1<<17];
int cand[1<<17], cb, ce;

long long value( int x, int p )
{
	int m;
	long long ret = dp[x] + ps[x];
	m = (x + 1 + p)/2;
	ret -= ps[m];
	if ( (p-x)%2 == 0 )
		ret -= ps[m];
	else
		ret -= ps[m-1];
	return ret;
}

int cross( int x, int y )
{
	int l, r, m;
	if ( value( x, n ) <= value( y, n ) )
		return n+1;
	l = y; r = n;
	while ( l+1 < r )
	{
		m = (l+r)/2;
		if ( value( x, m ) > value( y, m ) )
			r = m;
		else
			l = m;
	}
	return r;
}

int main()
{
	int i;
	
	scanf( "%d %lld", &n, &k );
	ps[0] = 0;
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%lld", &a[i] );
		ps[i] = ps[i-1] + a[i];
	}
	cb = 1;
	ce = 0;
	cand[++ce] = 0;
	dp[0] = -k;
	
	for ( i = 1; i <= n; i++ )
	{
		while ( ( cb < ce ) && ( value( cand[cb], i ) >= value( cand[cb+1], i ) ) )
			cb++;
		dp[i] = k + ps[i] + value( cand[cb], i );
		while ( (ce > cb) && ( cross( cand[ce], i ) <= cross( cand[ce-1], cand[ce] ) ) )
			ce--;
		if ( cross( cand[ce], i ) <= n )
			cand[++ce] = i;
	}
	printf( "%lld\n", dp[n] );
	return 0;
}
