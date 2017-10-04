#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 1 << 9;
const double INF = 99999999999.0;

int i, j, k, n, p;
double a[MAXN];
double f[MAXN][MAXN];
double pp[MAXN][MAXN];
double sum[MAXN][MAXN], pre[MAXN][MAXN];

double group (int p1, int p2) {
    return pp[p1][p2] - sum[p1][p2] / double(p2 - p1 + 1);
}

void init () {
    for (i = 1; i <= n; i++)
        for (j = i; j <= n; j++) {
            pp[i][j] = pp[i][j-1] + a[j]*a[j];
            sum[i][j] = sum[i][j-1] + a[j];
        }
    for (i = 1; i <= n; i++)
        for (j = i; j <= n; j++) sum[i][j] *= sum[i][j];
    for (i = 1; i <= n; i++)
        for (j = i; j <= n; j++) pre[i][j] = group (i, j);
}

void solve () {
    for (i = 0; i <= n; i++)
        for (j = 0; j <= p; j++)
            f[i][j] = INF;

    for (i = 1; i <= n; i++) f[i][1] = pre[1][i];

    f[1][1] = 0.0;

    double cur1, cur2, cur;
    
    for (i = 1; i <= n; i++)
        for (j = 2; j <= p; j++)
            for (k = 1; k < i; k++)
                f[i][j] = min (f[i][j], f[k][j-1] + pre[k+1][i]);

    printf ("%.4lf\n", f[n][p]);
}

int main () {
//    freopen ("groups.in", "rt", stdin);
    scanf ("%d %d", &n, &p);
    for (i = 1; i <= n; i++) scanf ("%lf", &a[i]);
    init ();
    solve ();
    return 0;
}

