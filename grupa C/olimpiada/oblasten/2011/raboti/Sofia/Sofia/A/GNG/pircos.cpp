#include <cstdio>

#define lll long long

using namespace std;

int N;

lll mod2[2], mod787[787], mod607[607], mod3[3], mod797[797], mod883[883];

char check3(){
    lll t1 = -1, t2 = -1;

    for ( int i = 0; i < 3; ++i )
        if ( mod3[i] )
            if ( t1 == -1  ) t1 = mod3[i];
            else t2 = mod3[i];
    if ( t2 == -1 ) return 0;

    if ( t1 > t2 ){
        long long t = t1;
        t1 = t2;
        t2 = t;
    }
        printf ( "%lld ", t1 );
        printf ( "%lld\n", t2 );
    return 1;
}

char check787(){
    lll t1 = -1, t2 = -1;

    for ( int i = 0; i < 787; ++i )
        if ( mod787[i]  )
            if ( t1 == -1  ) t1 = mod787[i];
           else t2 = mod787[i];
    if ( t2 == -1 ) return 0;

    if ( t1 > t2 ){
        long long t = t1;
        t1 = t2;
        t2 = t;
    }
        printf ( "%lld ", t1 );
        printf ( "%lld\n", t2 );
    return 1;
}

char check607(){
    lll t1 = -1, t2 = -1;

    for ( int i = 0; i < 607; ++i )
        if ( mod607[i] )
            if ( t1 == -1  ) t1 = mod607[i];
           else t2 = mod607[i];
    if ( t2 == -1 ) return 0;

    if ( t1 > t2 ){
        long long t = t1;
        t1 = t2;
        t2 = t;
    }
        printf ( "%lld ", t1 );
        printf ( "%lld\n", t2 );
    return 1;
}

char check797(){
    lll t1 = -1, t2 = -1;

    for ( int i = 0; i < 797; ++i )
        if ( mod797[i] )
            if ( t1 == -1  ) t1 = mod797[i];
           else t2 = mod797[i];
    if ( t2 == -1 ) return 0;

    if ( t1 > t2 ){
        long long t = t1;
        t1 = t2;
        t2 = t;
    }
        printf ( "%lld ", t1 );
        printf ( "%lld\n", t2 );
    return 1;
}


char check883(){
    lll t1 = -1, t2 = -1;

    for ( int i = 0; i < 883; ++i )
        if ( mod883[i] )
            if ( t1 == -1  ) t1 = mod883[i];
           else t2 = mod883[i];
    if ( t2 == -1 ) return 0;

    if ( t1 > t2 ){
        long long t = t1;
        t1 = t2;
        t2 = t;
    }
        printf ( "%lld ", t1 );
        printf ( "%lld\n", t2 );
    return 1;
}

void solve(){
    scanf ( "%d", &N );

    for ( int i = 0; i < N; ++i ){
        lll a;

        scanf ( "%lld", &a );

        mod2[ a & 1 ] ^= a;
        mod787[ a - ( a / 787 ) * 787 ] ^= a;
        mod607[ a - ( a / 607 ) * 607 ] ^= a;
        mod797[ a - ( a / 797 ) * 797 ] ^= a;
        mod883[ a - ( a / 883 ) * 883 ] ^= a;
        mod3[ a - ( a / 3 ) * 3 ] ^= a;
    }


    if ( mod2[0] != 0 && mod2[1] != 0){
        lll t1 = mod2[0];
        lll t2 = mod2[1];

        if ( t1 > t2 ){
            long long t = t1;
            t1 = t2;
            t2 = t;
        }

        printf ( "%lld ", t1 );
        printf ( "%lld\n", t2 );
        return;
    }
    if ( check3 ( ) ) return;
    if ( check787 ( ) ) return;
    if ( check607 ( ) ) return;
    if ( check797 ( ) ) return;
    if ( check883 ( ) ) return;
}
int main(){
    solve();
}
