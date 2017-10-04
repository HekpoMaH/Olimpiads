/*
TASK:diet
LANG:C++
*/
#include<cstdio>
using namespace std;
int main() {
	int br10 , br20 , br30;
	scanf ( "%d%d%d" , &br10 , &br20 , &br30 );
	printf ( "%d " , ( br10 * 10 + br20 * 20 + br30 * 30 ) / 60 );
	int razr = 0;
	while ( br10 + br20 * 2 + br30 * 3 >= 6 ) {
		bool slojil10 = 0 , slojil20 = 0 , slojil30 = 0;
		if ( !slojil10 && br10 > 0 ) {
			slojil10 = 1;
			--br10;
		}
		if ( !slojil20 && br20 > 0 ) {
			slojil20 = 1;
			--br20;
		}
		if ( !slojil30 && br30 > 0 ) {
			slojil30 = 1;
			--br30;
		}
		if ( !slojil30 && br30 == 0 && br10 + br20 * 2 + br30 * 3 >= 6 ) {
			if ( !slojil30 && br10 > 0 && br20 > 0 ) {
				--br10;
				--br20;
				slojil30 = 1;
			}
			if ( !slojil30 && br10 > 0 && br20 == 0 ) {
				br10 -= 3;
				slojil30 = 1;
			}
			if ( !slojil30 && br10 == 0 && br20 > 1 ) {
				++razr;
				br20 -= 2;
				++br10;
				slojil30 = 1;
			}
		}
		if ( !slojil20 && br20 == 0 && br30 * 3 + br20 * 2 + br10 >= 6 ) {
			if ( !slojil20 && br10 > 1 ) {
				br10 -= 2;
				slojil20 = 1;
			}
			if ( !slojil20 && br30 > 0 ) { 
				++razr;
				--br30;
				++br10;
				slojil20 = 1;
			}
		}
		if ( !slojil10 && br10 == 0 && br30 * 3 + br20 * 2 + br10 >= 6 ) {
			if ( !slojil10 && br20 > 0 ) {
				++razr;
				--br20;
				++br10;
				slojil10 = 1;
			}
			if ( !slojil10 && br30 > 0 ) {
				slojil10 = 1;
				++br20;
				++razr;
			}
		}
	}
	printf ( "%d\n" , razr );
	return 0;
}
