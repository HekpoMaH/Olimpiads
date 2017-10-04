#include <cstdio>

int n;
long long a[2][64];

void solve() {
    long long b , c;
    int i , j;
    
    scanf ( "%d" , &n );
    for (i = 1; i <= n; i++) {
        scanf ( "%lld" , &b );
        c = b;
        
        for (j = 0; c; j++) {
            a[c & 1][j] ^= b;
            c >>= 1;
        }
    }
    
    for (j = 0; j < 64; j++)
        if ( a[0][j] && a[1][j] ) {
            if ( a[0][j] < a[1][j] )
                printf ( "%lld %lld\n" , a[0][j] , a[1][j] );
            else
                printf ( "%lld %lld\n" , a[1][j] , a[0][j] );
                
            break ;
        }
}

int main() {
    solve();
    
    return 0;
}
