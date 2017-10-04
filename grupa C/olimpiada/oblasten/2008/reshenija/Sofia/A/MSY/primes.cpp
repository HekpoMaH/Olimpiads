#include <cstdio>
#include <vector>

using namespace std;

const int MAXN      = 50100;
const int MAXP      = 6059;

int n;
int primes[MAXP];
bool p[MAXN];
int dp[MAXN];
int s;

int main() {

    scanf("%d", &n);
    primes[ s++ ] = 2;  
    register int i, j;
    for (i = 3; s < MAXN; i += 2) {
        if ( p[i] ) continue;
        primes[s++] = i;
        if ( i > n ) break;
        for (j = i; j < MAXN; j += i) if ( i + j < MAXN ) p[i + j] = 1;
    }

    dp[0] = 1;
    for (i = 0; i < s-1; ++i)
        for (j = primes[i]; j <= n; ++j)
            dp[j] = (dp[j] + dp[j-primes[i]]) % primes[ s - 1 ];

    if ( !p[ n ] ) dp[n] = (dp[n] + primes[ s-1 ] - 1) % primes[ s-1 ];
    if ( !p[n] && (n % 2 == 0 && n != 2) ) dp[n]++;
    printf("%d\n", dp[ n ] % primes[ s - 1 ] );

    return 0;
}
