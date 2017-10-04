/* O(2^K) */
#include <cstdio>
#include <vector>

#define ll long long

using namespace std;

ll N, sol;
int K, d[32], st[32], comb[32][32], proc[32];

inline ll gcd(ll a, ll b)
{ return b ? gcd(b, a%b) : a; }

void take(int level, int nr, ll multiple)
{
    if (multiple > N)
        multiple = N+1;
        
    if (level == K)
    {
        if (nr & 1)
            sol += (N / multiple) * proc[nr];
        else
            sol -= (N / multiple) * proc[nr];
        return ;
    }
    
    st[level] = 0; take(level+1, nr, multiple);
    st[level] = 1; take(level+1, nr+1, multiple * d[level] / gcd(multiple, d[level]));
}

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

    take(0, 0, 1);

    printf("%lld\n", sol);
    
    return 0;
}

