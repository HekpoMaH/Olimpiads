#include <iostream>
using namespace std;
int m, n, r, k, x, y, ans, i, j;
int main()
{
scanf("%d%d%d%d", &m, &n, &r, &k);
if(r % n == 0) x = r / n, y = n;
else x = r / n + 1, y = r % n;

for(i=1; i<=m; i++)
for(j=1; j<=n; j++)
if(abs(x - i) + abs(y - j) <= k && (abs(x - i) + abs(y - j) - k) % 2 == 0)
ans += (i-1) * n + j;
printf("%d\n", ans);
return 0;
}
