#include <cstdio>

const int MAXN = 65536;

int n;
int primes[MAXN];
int p[MAXN];
int dp[MAXN];
int br;
int mx;

void read() {
    scanf ("%d",&n);
}

void init_primes() {
    int i , j;
    mx = 0;
    primes[1] = 1;
    
    for (i=1;mx<=n;i++)
        if ( !primes[i] ) {
            if ( i > mx ) mx = i;
            
            if ( i <= 500 ) 
            for (j=i*i;j<MAXN;j+=i)
                primes[j] = 1;
        }
}

void solve() {
    int i , j;
    primes[n] = 1;
    
    br = 0;
    for (i=1;i<=n;i++) {
        if ( !primes[i] ) p[++br] = i;
        dp[i] = 0;
    }
    
    dp[0] = 1;
    for (i=1;i<=br;i++)
        for (j=p[i];j<=n;j++) {
            dp[j] += dp[j-p[i]];
            if ( dp[j] > mx ) dp[j] -= mx;
        }
        
    printf ("%d\n",dp[n]);
}  

int main() {
    read();
    init_primes();
    solve();
    
    return 0;
}
