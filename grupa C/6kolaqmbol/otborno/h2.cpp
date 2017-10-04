#include <iostream>
#include <memory>
#define MAX_CAP 201

using namespace std;

char dp[MAX_CAP][MAX_CAP][MAX_CAP];
char used[3 * MAX_CAP];

int x, y, z, ans;

void Dp(int a, int b, int c)
{
if(!used[a]) ans++, used[a] = 1;
if(!used[b]) ans++, used[b] = 1;
if(!used[c]) ans++, used[c]  = 1;
if(!used[a + b]) ans++, used[a + b] = 1;
if(!used[a + c]) ans++, used[a + c] = 1;
if(!used[b + c]) ans++, used[b + c] = 1;
if(!used[a + b + c]) ans++, used[a + b + c] = 1;

// Palnene ot cisternata
if(!dp[x][b][c]) dp[x][b][c] = 1, Dp(x, b, c);
if(!dp[a][y][c]) dp[a][y][c] = 1, Dp(a, y, c);
if(!dp[a][b][z]) dp[a][b][z] = 1, Dp(a, b, z);

//Prehvarlqniq ot tuba v tuba
int r;
cout<<a<<" "<<b<<" "<<c<<endl;
r = a + b;
if(r > x) r = x;
if(b - r + a >= 0 && !dp[r][b - r + a][c]) dp[r][b - r + a][c] = 1, Dp(r, b - r + a, c);
cout<<r<<endl;
r = a + b;
if(r > y) r = y;
if(a - r + b >= 0 && !dp[a - r + b][r][c]) dp[a - r + b][r][c] = 1, Dp(a - r + b, r, c);
cout<<r<<endl;
r = a + c;
if(r > x) r = x;
if(c - r + a >= 0 && !dp[r][b][c - r + a]) dp[r][b][c - r + a] = 1, Dp(r, b, c - r + a);
cout<<r<<endl;
r = a + c;
if(r > z) r = z;
if(a - r + c >= 0 && !dp[a - r + c][b][r]) dp[a - r + c][b][r]  = 1, Dp(a - r + c, b, r);
cout<<r<<endl;
r = b + c;
if(r > y) r = y;
if(c - r + b >= 0 && !dp[a][r][c - r + b]) dp[a][r][c - r + b] = 1, Dp(a, r, c - r + b);
cout<<r<<endl;
r = b + c;
if(r > z) r = z;
if(b - r + c >= 0 && !dp[a][b - r + c][r]) dp[a][b - r + c][r] = 1, Dp(a, b - r + c, r);
}
int main()
{
  int t;
  scanf("%d", &t);
  for(int i=1; i<=t; i++)
  {
      memset(dp,0,sizeof(dp));
      memset(used,0,sizeof(used));
      ans=0;
      scanf("%d%d%d", &x, &y, &z);
      dp[0][0][0] = 1;
      Dp(0, 0, 0);
      printf("%d\n", ans - 1);
  }
  return 0;
}
