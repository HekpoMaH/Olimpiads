#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>
using namespace std;
char game[105];
int n;
int dp[3][3][105];
int grundy(int p, int len, int nx) {
    if (len == 0)
        return dp[p][nx][len] = 0;
    else if (dp[p][nx][len] != -1)
        return dp[p][nx][len];
    set<int> s;
    for (int k = 1; k <= len; k++) {
        if (!((k == 1 && p == 1) || (k == len && nx == 1)))
            s.insert(grundy(p, k - 1, 1) ^ grundy(1, len - k, nx));
        if (!((k == 1 && p == 2) || (k == len && nx == 2)))
            s.insert(grundy(p, k - 1, 2) ^ grundy(2, len - k, nx));
    }
    dp[p][nx][len] = 0;
    while (s.count(dp[p][nx][len]))
        dp[p][nx][len]++;
    return dp[p][nx][len];
}
int main(int argc, char **argv) {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 105; k++)
                dp[i][j][k] = -1;
    getchar();
    while (tc--) {
        gets(game);
        n = strlen(game);
        int pl = 0;
        for (int i = 0; i < n; i++)
            if (game[i] != '.')
                pl ^= 1;
        cout<<n<<" "<<pl<<"\n";
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (game[i] != '.')
                continue;
            int pr = (i - 1 < 0) ? 0 : (game[i - 1] == 'X') ? 1 : 2;
            int j = i;
            while (j < n && game[j] == '.')
                j++;
            int nx = (j == n) ? 0 : (game[j] == 'X') ? 1 : 2;
            int len = j - i;
            cout<<pr<<" "<<len<<" "<<nx<<" "<<grundy(pr,len,nx)<<"\n";
            res ^= grundy(pr, len, nx);
            i = j;
        }
        cout<<res<<" "<<pl<<"\n";
        if ((!pl && res) || (pl && !res))
            puts("Possible.");
        else
            puts("Impossible.");
    }
    return 0;
}
