#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cassert>

using namespace std;

const int day = 1440;

struct hhmm {
    int h, m;
    hhmm() { scanf ( "%d:%d\n", &h, &m ); }
};

inline int D ( const hhmm & a, const hhmm & b )
{
    return ( ( a.h - b.h )*60 + a.m - b.m + day ) % day;
}

int main()
{
    freopen ( "i.in", "rt", stdin );
    freopen ( "i.out", "wt", stdout );

    hhmm * t = new hhmm[4];
    int w1 = D ( t[3], t[0] );
    int w2 = D ( t[2], t[1] );
    int r = ( w1 - w2 + day ) % day;
    r -= r/2;
    if ( r == 0 ) r = day/2;
    printf ( "%02d:%02d\n", r/60, r%60 );

    return 0;
}
