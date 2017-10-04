/*
 * Task: lines
 * Complexity: O(n*q)
 * Every two lines should cross!
 */

#include <cstdio>
#include <cstring>

const double eps = 1e-7;
const int xr = (1<<29)-1;

double abs( double x )
{
	if ( x < 0 ) return -x;
	return x;
}

int n, q;
double a[1<<17], b[1<<17];
double c, d;

int main()
{
	double mx;
	int i, j, k;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%lf %lf", &a[i], &b[i] );
	}
	
	scanf( "%d", &q );
	bool fl = 0;
	for ( i = 1; i <= q; i++ )
	{
		scanf( "%d %d", &j, &k );
		if ( fl )
		{
			j = j ^ xr;
			k = k ^ xr;
		}
		c = j; 
		d = k;
		//scanf( "%lf %lf", &c, &d );
		mx = -(1e100);
		for ( j = 1; j <= n; j++ )
		{
			if ( abs( a[j] - c ) > eps )
			{
				//printf( "CR %d %lf %lf :: %.8lf\n", j, a[j], b[j], (d-b[j])/(a[j]-c) );
				if ( (d-b[j])/(a[j]-c) > mx )
				{
					//printf( "CR %d %lf %lf\n", i, a[i], b[i] );
					mx = (d-b[j])/(a[j]-c);
				}
			}
		}
		if ( mx > 1e-10 )
		{
			printf( "%.8lf\n", mx );
			fl = 0;
		}
		else
		{
			printf( "No cross\n" );
			fl = 1;
		}
	}
	return 0;
}
