#include <iostream>
#define MAX 1000*1000*1000
using namespace std;
int i, j, n, s, dp[500000];
int c[100];

int main()
{
scanf("%d%d", &s, &n);
for(i=0; i<n; i++) scanf("%d", &c[i]);
sort(c, c+n);
for(i=1; i<=s; i++)
{
dp[i] = MAX;
for(j=0; j<n && c[j] <= i; j++)
dp[i] = min(dp[i - c[j]] + 1, dp[i]);
}
printf("%d\n", dp[s]);
return 0;
}
