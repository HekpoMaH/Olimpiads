// Задача "Обход в глубину"
// IX Всероссийская командная олимпиада школьников по программированию
// Автор задачи: Елена Андреева, Виктор Матюхин
// Автор решения: Олег Давыдов, burunduk3@gmail.com

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fi first
#define mp make_pair
#define pb push_back
#define se second

#define maxn 610

int n, l, c[maxn], a[maxn], d[maxn], cur[maxn];

int main()
{
  freopen("dfs.in", "r", stdin);
  freopen("dfs.out", "w", stdout);

  scanf("%d%d", &n, &l);
  forn (i, l)
    scanf("%d", &a[i]), a[i]--;
  memset(d, 0, sizeof(d));
  forn (i, l)
    d[a[i]]++;
  memset(c, 0, sizeof(c));
  vector <pair <int, int> > ans;
  forn (i, l)
  {
    cur[a[i]] = a[i + 1];
    if (++c[a[i]] == d[a[i]])
      forn (j, n)
        if (c[j] > 0 && c[j] < d[j] && cur[j] <= a[i])
          ans.pb(mp(a[i], j));
  }

  forn (i, ans.size())
    if (ans[i].fi > ans[i].se)
      swap(ans[i].fi, ans[i].se);
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  forn (i, ans.size())
    printf("%d %d\n", ans[i].fi + 1, ans[i].se + 1);

  return 0;
}
