#include <stdio.h>
#include<iostream>
#define MAXN 1001
#define MAXK 10001
#define MAXD 101
#define MAXL 1001
using namespace std;
long dp[MAXN][MAXK];
long treas[MAXN], back[MAXN], cost[MAXN];
long map[MAXD][MAXL];
long n, k, l, d, i, j, m, curr, backto, answ;
long max(long a, long b) {
     return (a < b ? b : a);
}
int main(){
    scanf("%ld %ld %ld %ld", &n, &k, &l, &d);
    for (i = 1; i <= d; i++)
        for (j = 1; j <= l; j++)
            scanf("%ld", &map[i][j]);
    m = 0;
    for (j = 1; j <= l; j++) {
        backto = m;
        curr = 0;
        for (i = 1; i <= d; i++) {
            curr += map[i][j];
            if (map[i][j] > 0) {
               m++;
               treas[m] = curr;
               cost[m] = i;
               back[m] = backto;
            }
        }
    }
    
    for (i = 0; i <= k; i++)
        dp[0][i] = 0;
    for (i = 1; i <= n; i++)
        dp[i][0] = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= k; j++) {
            if (j < cost[i]) continue;
            dp[i][j] = max(dp[i-1][j], dp[back[i]][j-cost[i]] + treas[i]);
        }
    answ = 0;
    for (i = 1; i <= k; i++)
        answ = max(answ, dp[n][i]);
    printf("%ld\n", answ);
    return 0;
}
