#include <iostream>
#include <stdio.h>
#include <set>

#define inf -10000000000000LL
using namespace std;

int N, A[100000], T[100000], D[100000];

long long dp[100000];

set < pair <int, int> > pos[6];
set < pair <long long, int> > best[6];

set < pair <int, int> > :: iterator iter;
set < pair <long long, int> > :: iterator iter_best;

int main () {
    scanf ("%d", &N);
    for (int i = 0; i < N; i++)
        scanf ("%d%d%d", A + i, T + i, D + i);

    dp[0] = (long long)A[0];
    pos[T[0]].insert (make_pair (D[0], 0));
    best[T[0]].insert (make_pair (-dp[0], 0));

    int k;

    for (int i = 1; i < N; i++) {
        dp[i] = inf;

        for (int j = 1; j <= 5; j++)
            while (!pos[j].empty()) {
                iter = pos[j].begin();
                if (iter->first < i) {
                    k = iter->second;
                    pos[j].erase (iter);
                    best[j].erase (make_pair (-(dp[k] + (long long)k*T[k]), k));
                } else break;
            }

        for (int j = 1; j <= 5; j++)
            if (!best[j].empty()) {
                iter_best = best[j].begin();
                dp[i] = max (dp[i], -(iter_best->first) + (long long)A[i] - (long long)i*j);
            }

        pos[T[i]].insert (make_pair (i + D[i], i));
        best[T[i]].insert (make_pair (-(dp[i] + (long long)i*T[i]), i));
    }

    printf ("%lld\n", dp[N - 1]);
}
