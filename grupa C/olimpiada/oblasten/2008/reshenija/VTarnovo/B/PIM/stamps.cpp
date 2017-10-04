#include <iostream>
#include <cstdio>
using namespace std;

const int MAXS = 5000;
const int MAXN = 3000;
const int INF  = 2000000000;

int S, N;

int DP[MAXS];

int coins[MAXN];

int main()
{
 scanf("%d %d", &S, &N);
 
 for (int i = 0; i < N; i++)
  scanf("%d", &coins[i]);
 
 sort(coins, coins + N);
 
 for (int i = 0; i <= S; i++) DP[i] = INF;
 
 DP[0] = 0;
 
 for (int i = 1; i <= S; i++)
  for (int j = 0; j < N; j++)
  {
   if (i - coins[j] < 0) break;
   if (DP[i - coins[j]] + 1 < DP[i])
    DP[i] = DP[i - coins[j]] + 1;
  }
  
 printf("%d\n", DP[S]);
 
 return 0;
}
