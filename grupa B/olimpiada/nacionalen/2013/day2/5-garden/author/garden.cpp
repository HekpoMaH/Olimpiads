//Task: garden
//Author: Yordan Chaparov

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int bsize = 45;

typedef pair<int,int> pii;

struct point
{
	int x, y;
	bool operator<( const point &p ) const
	{
		if ( x == p.x ) return y < p.y;
		return x < p.x;
	}
};

int n;
point p[100020];

bool us[2000020];

map<point,int> mp;

int main()
{
	int i, j, k, l;
	int cnt;
	point a;
	long long ans = 0;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d %d", &p[i].x, &p[i].y );
	}
	
	sort( p + 1, p + n + 1 );
	
	mp.clear();
	ans = 0;
	for ( i = 1; i <= n; )
	{
		j = i;
		while ( ( p[j].x == p[i].x ) && ( j <= n ) )
			j++;
		if ( j-i >= bsize )
		{
			//golqmo
			memset( us, 0, sizeof( us ) );
			for ( k = i; k < j; k++ )
				us[ p[k].y + 1000000 ] = 1;
			for ( k = 1; k <= n; )
			{
				l = k;
				while ( ( p[k].x == p[l].x ) && ( l <= n ) )
					l++;
				
				if ( k == i )
				{
					k = l;
					continue;
				}
				if ( l-k < bsize || k < i )
				{
//					printf( "ADD %d %d :: %d %d\n", i, k, p[i].x, p[k].x );
					cnt = 0;
					while ( k < l )
					{
						if ( us[ p[k].y + 1000000 ] ) cnt++;
						k++;
					}
					ans = ans + (long long)cnt*(cnt-1)/2;
				}
				else k = l;
			}
		}
		else
		{
			for ( k = i; k < j; k++ )
			{
				a.x = p[k].y;
				for ( l = k+1; l < j; l++ )
				{
					a.y = p[l].y;
					ans += mp[ a ];
					mp[a]++;
				}
			}
		}
		
		i = j;
	}
	printf( "%lld\n", ans );
	return 0;
}
