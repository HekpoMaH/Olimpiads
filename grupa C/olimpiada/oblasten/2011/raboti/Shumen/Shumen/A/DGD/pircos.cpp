#include<cstdio>
#include<cmath>
using namespace std;
unsigned long long max ( unsigned long long a, unsigned long long b ) {
    
    if( a>b ) return a;
    return b;
}
unsigned long long m[2][64];
void read() {
    
    int n, i, j;
    unsigned long long s=0, k;
    scanf("%d", &n);
    for( i=0; i<n; ++i ) {
        
        scanf("%lld", &k);
        for( j=0; j<64; ++j )  {
            
            if( (k/(1<<j))%2 ) m[1][j]^=k;
            else m[0][j]^=k;
        }
        s^=k;
    }
    for( i=0; i<64; ++j ) {
        
        if( (s/(1<<j))%2 ) {
            
            if( m[0][i+1] > m[1][i+1] ) printf("%lld %lld\n", m[1][i+1], m[0][i+1]);
            else printf("%lld %lld\n", m[0][i+1], m[1][i+1]);
            return;
        }
    }
}
main () {
    
    read();
    return 0;
}
