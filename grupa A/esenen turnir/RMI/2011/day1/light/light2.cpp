/* O(2^K * K) */
#include <cstdio>
#include <vector>

#define ll long long

using namespace std;

ll N, sol;
int K, d[32], st[32], comb[32][32], proc[32];

inline int bit(int x, int nr)
{ return (x & (1<<nr)) != 0; }

inline ll gcd(ll a, ll b)
{ return b ? gcd(b, a%b) : a; }

int main()
{
    scanf("%lld%d", &N, &K);
    for (int i = 0; i < K; ++i)
        scanf("%d", &d[i]);
 
    comb[1][0] = comb[1][1] = 1;
    for (int i = 2; i <= K; ++i)
    {
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
    }
    for (int i = 1; i <= K; ++i)
        for (int j = 1; j <= i; j += 2)
            proc[i] += comb[i][j];

    int nrb;
    ll multiple;
    for (int i = 1; i < (1<<K); ++i)
    {
        nrb = 0; multiple = 1;
        for (int j = 0; j < K; ++j)
            if (bit(i, j))
            {
                ++nrb;
                multiple = multiple * d[j] / gcd(multiple, d[j]);
                if (multiple > N)
                    break;
            }
        if (multiple <= N)
        {
            if (nrb & 1)
                sol += (N / multiple) * proc[nrb];
            else
                sol -= (N / multiple) * proc[nrb];
        }
    }

    printf("%lld\n", sol);
    
    return 0;
}

