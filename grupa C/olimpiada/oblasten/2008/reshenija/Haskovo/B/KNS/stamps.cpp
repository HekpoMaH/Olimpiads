#include <cstdio>
#include <algorithm>

using namespace std;

int S, N, forbit;
int A[1<<12];
int dp[1<<13];

inline int Min(int z, int x)
{
    return (z <= x) ? z : x;
}

int solve(int s)
{
    int k=0;
   
    if (s < 0) return forbit;
    if (dp[s] == forbit)
    {
        for (int i=N-1; i>=0; --i)
        {
            k=s/A[i];
            if (!k) continue;
            else
            {
                for (int j=k; j>=1; --j)
                if (j < dp[s])
                dp[s]=Min(dp[s], j+solve(s-j*A[i]));
            }
        }
    }
    return dp[s];
}

void read()
{
    scanf("%d%d", &S, &N);
    for (int i=0; i<N; ++i)
    scanf("%d", &A[i]);
}

int main()
{
    read();
    memset(dp, 63, sizeof(dp));
    forbit=dp[0];
    dp[0]=0;
    dp[1]=1;
    printf("%d\n", solve(S));
return 0;
}
