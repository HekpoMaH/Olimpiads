#include <cstdio>
#define MAXN 497393
using namespace std;
bool num[MAXN];
int main()
{
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
  {
    int k;
    scanf("%d", &k);
    k = k%MAXN;
    num[k] = !num[k];
  }
  int ans[10], f = 0;
  for(int i = 0; i < MAXN; ++i)
  {
    if(num[i]) {ans[f] = i; ++f;}
  }
  if(ans[0] > ans[1])
  {
    int t = ans[0];
    ans[0] = ans[1];
    ans[1] = t;
  }
  printf("%d %d\n", ans[0], ans[1]);
  return 0;
}
