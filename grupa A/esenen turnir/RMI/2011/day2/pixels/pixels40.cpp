#include<stdio.h>
#include<time.h>
#include<string.h>

#define maxn 128

int a[ maxn ][ maxn ][ 2 ];
int c[ maxn ][ maxn ][ 4 ];
int X[ 4 ] = { -1, 0, 1, 0};
int Y[ 4 ] = { 0, 1, 0, -1}, N;
int mat[ 128 ][ 2048 ];

time_t start;

int main()
{
	scanf("%d", &N);
	
	for( int i = 1; i <= N; ++i)
		for( int j = 1; j <= N; ++j)
			scanf("%d ", &a[ i ][ j ][ 0 ] );
	
	for( int i = 1; i <= N; ++i)
		for( int j = 1; j <= N; ++j)
			scanf("%d ", &a[ i ][ j ][ 1 ] );
	
	for( int i = 1; i <= N; ++i)
		for( int j = 1; j <= N; ++j)
			for( int k = 0; k <= 3; ++k)
				scanf("%d", &c[ i ][ j ][ k ] );
		
	int nr_var = 1 << N;
	int V[ maxn ], last[ maxn ];
	memset( V, 0,sizeof(V));
	for( int i = 0; i < nr_var; ++i)
	{
		int k = i;
		int cost = 0;
		for( int j = 1; j <= N; ++j)
		{
			V[ j ] = k	% 2;
			cost += a[ 1 ][ j ][ V[ j ]];
			if( V[ j ] != V[ j - 1 ] )
				cost -= c[ 1 ][ j ][ 3 ];
			k /= 2;
		}
		mat[ 1 ][ i ] = cost;
		
	}
	for( int i = 2; i <= N; ++i)
		for( int j = 0; j < nr_var; ++j) // j - current line configuration
		{
			int optim = -2000000000;
			for( int k = 0; k < nr_var; ++k)// k - last line configuration
			{
				int cost = mat[ i - 1][ k ];
				int p = j, q = k;
				for( int l = 1; l <= N; ++l) 
				{
					V[ l ] = (p & 1); p >>= 1;
					last[ l ] = (q & 1); q >>= 1;
					cost += a[ i ][ l ][ V[ l ]];
					if( V[ l ] != V[ l - 1 ] )
						cost -= c[ i ][ l ][ 3 ];
					if( V[ l ] != last[ l ] )
						cost -= c[ i ][ l ][ 0 ];
				}
				if( optim < cost)
					optim = cost;
					
			}
			if( mat[ i ][ j ] < optim)
				mat[ i ][ j ] = optim;
			
		}
	int rez = 0;
	for( int i = 0; i <= nr_var; ++i)
		if( mat[ N ][ i ] > rez) 
			rez = mat[ N ][ i ];
	
	printf("%d\n", rez);
	
	
	return 0;
}

