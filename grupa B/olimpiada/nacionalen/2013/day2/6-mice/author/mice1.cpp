//Task: mice
//Author: Yordan Chaparov

// Бързо решение, използващо индексно дърво
// за броене на инверсиите
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

int it[1<<20];

void initIT( int n )
{
	memset( it, 0, (n+20)*sizeof( int ) );
}

void addIT( int n, int p )
{
	p++;
	for ( int i = p; i <= n; i += (i&(-i)) )
		it[i]++;
}

int getIT( int n, int p )
{
	p++;
	int r = 0;
	for ( int i = p; i > 0; i -= (i&(-i)) )
		r += it[i];
	return r;
}

pair<int,int> p[1<<20];

bool cmp( pair<int,int> a, pair<int,int> b )
{
	return a.second < b.second;
}

//broeneto na inversii stana malko tromavo, zashtoto se nalozhi da
//"kompresiram" chislata, za da izpolzvam indeksno darvo
long long countInversions( int n, int a[] )
{
	long long inv = 0;
	
	for ( int i = 0; i < n; i++ )
		p[i] = make_pair( a[i], i );
	
	sort( p, p + n );
	for ( int i = 0; i < n; i++ )
		p[i].first = i;
	
	sort( p, p + n, cmp );

	initIT( n );
	for ( int i = n-1; i >= 0; i-- )
	{
		inv += getIT( n, p[i].first );
		addIT( n, p[i].first );
	}
	return inv;
}

int countInversions_n2( int n, int a[] )
{
	int inv = 0;
	for ( int i = 0; i < n; i++ )
	{
		for ( int j = i+1; j < n; j++ )
		{
			if ( a[j] < a[i] )
				inv++;
		}
	}
	return inv;
}

void print( int n, int a[] )
{
	for ( int i = 0; i < n; i++ )
		fprintf( stderr, "%d ", a[i] );
	fprintf( stderr, "\n" );
}

int n, k;
int a[1<<20];
int lb, b[1<<20];
int best = (1<<29);

int main()
{
	int i, j;
	int oddcount = 0;
	
	scanf( "%d %d", &n, &k );
	for ( i = 0; i < n; i++ )
		scanf( "%d", &a[i] );
	
	if ( k == 1 )
	{
		printf( "1\n" );
		return 0;
	}
	else if ( k + k > n )
	{
		printf( "%s\n", countInversions( n, a ) == 0 ? "1" : "0" );
		return 0;
	}
	
	for ( i = 0; i < k; i++ )
	{
		lb = 0;
		for ( j = i; j < n; j += k )
			b[lb++] = a[j];
		if ( countInversions( lb, b ) % 2 )
		{
			oddcount++;
		}
		std::sort( b, b + lb );
		for ( j = i; j < n; j += k )
			a[j] = b[j/k];
	}
	
	for ( i = 0; i+1 < n; i++ )
	{
		if ( a[i] > a[i+1] )
			break;
	}
	
	printf( "%s\n", (oddcount == k || !oddcount) && i+1 >= n ? "1" : "0" );
	
	return 0;
}
