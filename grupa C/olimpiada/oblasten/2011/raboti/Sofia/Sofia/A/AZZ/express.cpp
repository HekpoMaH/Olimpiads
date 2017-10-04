#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;
const int MAXN = 1 << 5;
const lli INF = 1ll << 62;

lli dp[MAXN][MAXN];
lli a[MAXN];
bool u[MAXN][MAXN];

char oper[MAXN];

char s[MAXN];
int n;

void read() {
        scanf ( "%s" , s );

        int i , len = (int)strlen ( s );
        for (i = 0; i < len; ++i) {
                if ( s[i] >= '0' && s[i] <= '9' )
                        a[ n++ ] = s[i] - '0';
                else
                        oper[n - 1] = s[i];
        }
}

lli go ( int l , int r ) {
        if ( l > r ) return 0ll;
        if ( u[l][r] ) return dp[l][r];

        u[l][r] = 1;
        dp[l][r] = INF;

        lli p1 , p2;
        for (int i = l; i <= r; ++i) {
                p1 = go ( l , i );
                p2 = go ( i + 1 , r );

                if ( i < r ) {
                    if ( oper[i] == '+' )
                                dp[l][r] = min ( dp[l][r] , p1 + p2 );
                        if ( oper[i] == '-' )
                                dp[l][r] = min ( dp[l][r] , p1 - p2 );
                        if ( oper[i] == '*' )
                                dp[l][r] = min ( dp[l][r] , p1 * p2 );
                }
                else
                        dp[l][r] = min ( dp[l][r] , p1 );
        }
        return dp[l][r];
}

void solve() {
        int i;
        for (i = 0; i < n; ++i) {
                dp[i][i] = a[i];
                u[i][i] = 1;
                if ( i + 1 < n ) {
                        u[i][i + 1] = 1;
                        if ( oper[i] == '+' )
                                dp[i][i + 1] = a[i] + a[i + 1];
                        if ( oper[i] == '-' )
                                dp[i][i + 1] = a[i] - a[i + 1];
                        if ( oper[i] == '*' )
                                dp[i][i + 1] = a[i] * a[i + 1];
                }
        }

        lli res = go ( 0 , n - 1 );
        cout << res << endl;
}

int main() {
        read();
        solve();
        return 0;
}
