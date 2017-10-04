/* O(3^K) */
#include <cstdio>
#include <vector>

using namespace std;

#define ll long long

ll N, sol;
int K, d[32], st[32];

inline ll gcd(ll a, ll b)
{ return b ? gcd(b, a%b) : a; }

void back(int level, int nrIE, ll multiple)
{
    if (multiple > N)
        return ;
          
    if (level == K)
    {
        if (nrIE & 1)
            sol -= N / multiple;
        else
            sol += N / multiple;
        return ;
    }
    
    if (!st[level])
        back(level+1, nrIE + 1, multiple * d[level] / gcd(multiple, d[level]));
    back(level+1, nrIE, multiple);
}

void take(int level, int nr, ll multiple)
{
    if (multiple > N)
        return ;
    
    if (level == K)
    {
        if (nr & 1)
            back(0, 0, multiple);
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
 
    take(0, 0, 1);

    printf("%lld\n", sol);
    
    return 0;
}

