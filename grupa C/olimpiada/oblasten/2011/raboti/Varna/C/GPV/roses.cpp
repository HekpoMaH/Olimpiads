#include <iostream>
#define MAX 1000*1000*1000
using namespace std;

int m, n, k, i, j, s, ans, w, r, e;
int a[1024][1024];

int main()
{
scanf("%d%d%d", &m, &n, &k);

for(i=0; i<m; i++)
for(j=0; j<n; j++)
{
scanf("%d", &a[i][j]), s += a[i][j];
if(i == 0) w = 0; else w = a[i-1][j];
if(j == 0) r = 0; else r = a[i][j-1];
if(i == 0 || j == 0) e = 0; else e = a[i-1][j-1];
a[i][j] += w + r - e;
}

for(i=0; i<m; i++)
for(j=0; j<n; j++)
{
if(i < k - 1 || j < k - 1) continue;
if(i == k - 1) w = 0; else w = a[i-k][j];
if(j == k - 1) r = 0; else r = a[i][j-k];
if(i == k - 1 || j == k - 1) e = 0; else e = a[i-k][j-k];
ans = max(ans, a[i][j] - w - r + e);
}
printf("%d\n", s - ans);
return 0;
}
