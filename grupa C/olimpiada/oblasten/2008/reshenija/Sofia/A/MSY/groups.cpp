#include <cstdio>

using namespace std;

const int MAXN     = 512;
const double INF   = 2000000.0;

double a[MAXN];
double s[MAXN];
double s2[MAXN];
double F[MAXN][MAXN];
int n, p;

inline double _min(double a, double b) {
    return (a > b) ? b : a;
}

double g(int ind1, int ind2) {
/*    double s = 0.0;
    for (int i = ind1; i <= ind2; ++i) s += a[i];
    s /= (double) (ind2-ind1+1);
    double sq = 0.0;
    for (int i = ind1; i <= ind2; ++i)
        sq += (a[i] - s) * (a[i] - s);
    return sq;
*/
    double all = (double) (ind2 - ind1 + 1);
    double avg = (s[ind2] - s[ind1-1]) / all;
    return (s2[ind2] - s2[ind1-1]) + avg*avg*all - 2 * avg * (s[ind2] - s[ind1-1]);
}

int main() {

    scanf("%d %d", &n, &p);
    for (int i = 1; i <= n; ++i)
        scanf("%lf", &a[i]);

    s[1] = a[1];
    s2[1] = a[1]*a[1];

    for (int i = 2; i <= n; ++i) {
        s[i] = s[i-1] + a[i];
        s2[i] = s2[i-1] + a[i]*a[i];
    }
//    for (int i = 1; i <= n; ++i)
//        printf("%lf ", s[i]);
//    puts("");

    for (int i = 0; i < MAXN; ++i)
        for (int j = 0; j < MAXN; ++j) F[i][j] = INF;

    for (int i = 1; i <= n; ++i) {
        double x = s[i] / (double) i;
        F[i][0] = 0;
        for (int j = 1; j <= i; ++j)
            F[i][0] += ( a[j] - x ) * ( a[j] - x );
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= p && j < i; ++j) {
            if (i == j) continue ;
            for (int k = 1; k < i; ++k)
                F[i][j] = _min( F[k][j-1] + g(k+1, i), F[i][j] );
        }

    printf("%.4lf\n", F[n][p-1]);

    return 0;
}
