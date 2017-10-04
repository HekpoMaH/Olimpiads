/*
  ID: nigo1
  LANG: C++
  TASK: straw
*/
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <stack>

using namespace std;

int N, T, K, a;

int highest_bit ( int a){
    int k = 0;

    for ( int i = 0; ( 1 << i ) <= a; ++i )
        if ( (1 << i ) & a ) k = i;

    return k;
}

int main()
{
	//freopen ("straw.in", "r", stdin);
	//freopen ("straw.out", "w", stdout);
    scanf ("%d", &T);

    while ( T-- ) {
        scanf ("%d%d", &N, &K);

        int xr = 0;
        for ( int i = 0; i < N; i++ ) {
            scanf ("%d", &a);
            xr ^= a;
        }
        int st1 = highest_bit ( K ), st2 = highest_bit ( xr );

        if ( xr == 0 )
            printf ("0\n");
        else {
            if ( st1 < st2 ) printf ("-1\n");
            else {
                if (xr > K) printf ("2\n");
                else
                    printf ("1\n");
            }
        }
    }

}
