#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double eps = 1e-6;

int main( int argc, char *argv[] )
{
//	FILE * fin = fopen( argv[1], "r" ); //input file
	FILE * fc = fopen( argv[2], "r" );  //competitor file
	FILE * fa = fopen( argv[3], "r" );  //solution file
	
	char stc[128], sta[128];
	double dc, da;
	
	int i = 0;
	while ( fscanf( fa, "%lf", &da ) == 1 )
	{
		i++;
		fgets( stc, 100, fc );
		//fscanf( fc, "%s", stc );
		if ( stc[0] == 'N' )
		{
			sscanf( sta, "%lf", &da );
			if ( da > eps )
			{
			    printf( "0\n" );
				printf( "Wrong Answer %d %s %lf\n", i, stc, da );
				return 0;
			}
			continue;
		}
		if ( da < -eps )
		{
			if ( stc[0] != 'N' )
			{
			    printf( "0\n" );
				printf( "Wrong Answer %d %s %lf\n", i, stc, da );
			}
		}
		sscanf( stc, "%lf", &dc );
		if ( ( abs( dc-da ) < eps ) || ( abs( 1 - da/dc ) < eps ) )
			continue;
	    printf( "0\n" );
		printf( "Wrong Answer %d %s %lf\n", i, stc, da );
		return 0;
	}
	sscanf( argv[4], "%d", &i ); //points
	printf( "%d\n", i );
	printf( "OK\n" );
	return 0;
}
