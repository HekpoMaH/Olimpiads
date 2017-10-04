#include <cassert>
#include <cstdio>
#include <vector>

using namespace std;

#define maxn 310

int a[maxn], an, was[maxn], d[2 * maxn];
vector < pair <int, int> > res;

int main( void )
{
  freopen("dfs.in", "r", stdin);
  freopen("dfs.out", "w", stdout);

  int n, l;
  scanf("%d%d", &n, &l);

  assert((1 <= n && n <= 300) && (1 <= l && l <= 2 * n - 1));
   

  for (int i = 0; i < l; i++)
  {
    scanf("%d", &d[i]);
    assert(1 <= d[i] && d[i] <= n);
  }

  for (int i = 0; i < l; i++)
  {
    int v = d[i];
    
    if (was[v])
    {
      while (a[an - 1] != v)
        an--;
    }
    else
    {
      was[v] = 1;
      a[an++] = v;
      for (int j = 0; j + 1 < an; j++)
        if (v >= a[j + 1])
          res.push_back(make_pair(a[j], v));
    }
    
    bool f = false;
    for (int j = i + 1; j < l; j++)
      if (d[j] == v)
        f = true;
    if (!f)
    {
      an--;
      was[v] = 0;
    }
  }

  printf("%d\n", res.size());
  
  for (int i = 0; i < (int)res.size(); i++)
    printf("%d %d\n", res[i].first, res[i].second);


  return 0;
}
 