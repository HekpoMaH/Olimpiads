#include <iostream>

using namespace std;

const int MAXS = (1 << 20);
const int MAXN = (1 << 7);
      int dp[MAXS];
      int s, n, i, j;

int mymin (int x, int y) {
    if (x < y) return x;
    return y;
}

int main () {
    scanf ("%d %d", &s, &n);

    dp[0] = 0;
    dp[1] = 1;
    for (i = 2; i <= s; ++ i) {
        dp[i] = dp[i-1] + 1;
        for (j = 2; j <= n; ++ j) {
            if (i % j == 0) {if (dp[i] > (dp[(int) (i / j)] + 1)) dp[i] = (dp[(int) (i / j)] + 1);}
            if (i - j >= 0) {if (dp[i] > (dp[(int) (i - j)] + 1)) dp[i] = (dp[(int) (i - j)] + 1);}
        }
    }

    printf ("%d\n", dp[s]);

    return 0;
}
