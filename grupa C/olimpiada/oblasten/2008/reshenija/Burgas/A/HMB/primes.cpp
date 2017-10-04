#include <cstdio>

const int MAXN = 1 << 16;

int i, j, n, m, MOD;
bool p[MAXN], calc[MAXN];
int f[MAXN];
int a[MAXN];

void find_primes () {
    for (i = 2; i <= n + 1000; i++)
        if (!p[i]) {
            for (j = 2*i; j <= n + 1000; j += i)
                p[j] = 1;
        }
    for (i = 2; i <= n; i++) if (!p[i]) a[++m] = i;
    for (i = n + 1;; i++) if (!p[i]) {MOD = i; break;}
    p[0] = p[1] = 1;
//    printf ("\nMOD = %d m = %d", MOD, m);
}

void solve () {
    f[0] = 1;
    calc[0] = 1;
    int k, pos;
    for (i = 1; i <= m; i++)
        for (j = 0; a[i] + j <= n; j++)
            if (f[j]) {
                k = a[i]+j;
                f[k] += f[j];

                if (f[k] >= MOD) f[k] %= MOD;
            }


    if (n == 0 || n == 1) printf ("0\n");
    else if (!p[n]) printf ("%d\n", f[n] - 1);
    else printf ("%d\n", f[n]);
}

int main () {
    scanf ("%d", &n);
    find_primes ();
    solve ();
    return 0;
}

