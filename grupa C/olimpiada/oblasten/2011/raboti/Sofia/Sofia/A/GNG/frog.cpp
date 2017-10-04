#include <iostream>
#include <algorithm>

using namespace std;

int ABS ( int x ){
    if ( x < 0 ) return -x;
    return x;
}

struct point{
    int x, y;

    int man_dist ( point t1 ){
        int p = ABS( t1.x - x ), q = ABS( t1.y - y );
        return ( p > q ) ? p : q;
    }
};

int N;
point a[16];
int ans = ( 1 << 30 );

void scan(){
    cin >> N;

    for ( int i = 0; i < 2 * N; ++i )
        cin >> a[i].x >> a[i].y;
}

void check ( int mask ){
    int idx[16], sz = 0;

    for ( int i = 0; i < ( 2 * N ); ++i )
        if ( (1 << i ) & mask )
            idx[sz++] = i;
    do{
        point zero;
        zero.x = zero.y = 0;
        int cur = zero.man_dist ( a[ idx[0] ] );

        for ( int i = 1; i < N; ++i )
            cur += ( a[ idx[i - 1] ].man_dist ( a[ idx[i] ] ) );
        if ( ans > cur) ans = cur;
    }
    while ( next_permutation ( idx, idx + N ) );
}
void solve(){
    for ( int i = 0; i < ( 1 <<  ( 2 * N ) ); ++i ){
        int br = 0;

        for ( int j = 0; j < N * 2; ++j )
            if ( ( 1 << j ) & i ) ++br;
        if ( br == N ){
            check ( i );
        }
    }
    cout << ans << endl;
}
int main(){
    scan();
    solve();
}
