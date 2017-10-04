 #include <cstdio>
 #include <cstdio>
 #include <iostream>
 #include <algorithm>
 using namespace std;

 const int MAXN = 1 << 4;
 const int ADD = 1 << 10;
 const int INF = 1 << 29;

 int x[MAXN];
 int y[MAXN];
 int n;
 int v;

 int ma3x[MAXN][MAXN];
int dp[MAXN][8][1 << 14];

 void read() {
        scanf ( "%d",  &n );

        v = (n << 1) + 1;

        int i;
        for (i = 1; i < v; ++i) {
                scanf ( "%d%d" , x + i , y + i );
                x[i] += ADD;
                y[i] += ADD;
        }
        x[0] = ADD;
        y[0] = ADD;
 }

int go ( int pos , int moves , int mask  ) {
        if ( moves == n ) return 0;

        int &res = dp[pos][moves][mask];
        if ( res != -1 ) return res;
        res = INF;

        int i;
        for (i = 0; i < v; ++i)
                if ( ma3x[pos][i] != -1 && !((mask >> i) & 1) )
                        res = min ( res , go ( i , moves + 1 , mask | (1 << i) ) + ma3x[pos][i] );

        return res;
}

 void solve() {
        memset ( ma3x , -1 , sizeof ma3x );
        memset ( dp , -1 , sizeof dp );

        int i , j;
        for (i = 0; i < v; ++i)
                for (j = 0; j < v; ++j)
                        if ( (i != j) && x[j] >= x[i] && y[j] >= y[i] && !((x[j] - x[i] + y[j] - y[i] ) & 1) )
                                ma3x[i][j] = ma3x[j][i] = max ( x[j] - x[i] , y[j] - y[i] );

        int ans = go ( 0 , 0 , 1 );
        printf ( "%d\n" , (ans == INF) ? 0 : ans );
 }



 int main() {
        read();
        solve();

        return 0;
 }
