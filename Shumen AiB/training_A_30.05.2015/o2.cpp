

// Задача "Оптимизация"
// IX Всероссийская командная олимпиада школьников по программированию
// Автор задачи: Сергей Копелиович
// Автор решения: Олег Давыдов, burunduk3@gmail.com
#include <cstdio>
#include<cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forit(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)

#define maxit (1 << 17)
#define maxn 100010

int m, n;
int a[maxn], b[maxn], p[maxn], it[maxit + maxn];
ll r[maxn], s[maxn];

bool pless( const int &a, const int &b )
{
  return r[a] < r[b];
}

void itadd( int i, int d )
{
  for (i += maxit; i >= 1; i >>= 1)
    it[i] += d;
}

int itget( int i, int j )
{
  i += maxit, j += maxit;
  if (i == j)
    return it[i];
  int res = it[i] + it[j];
  for (; i / 2 < j / 2; i >>= 1, j >>= 1)
  {
    if (i % 2 == 0)
      res += it[i ^ 1];
    if (j % 2 == 1)
      res += it[j ^ 1];
  }
  return res;
}

int main()
{
  //freopen("optimize.in", "r", stdin);
  //freopen("optimize.out", "w", stdout);

  scanf("%d%d", &n, &m);
  forn (i, m)
    scanf("%d", &a[i]);
  forn (j, n)
  {
    int k;
    scanf("%d", &k);
    forn (i, k)
    {
      int a;
      scanf("%d", &a);
      b[a - 1] = j;
    }
  }

  int k = 0;
  set <int> as;
  map <int, int> am;
  as.insert(0);
  forn (i, m)
    as.insert(a[i]);
  forit (i, as)
    am[*i] = k++;

  memset(s, 0, sizeof(s));
  forn (i, m)
    s[b[i]] += a[i];
  forn (i,m)
     cout<<s[b[i]]<<" ";
  cout<<"\n";
  forn (i, m)
    r[i] = s[b[i]] - a[i], p[i] = i;
  sort(p, p + m, pless);

  forn (i,m)
     cout<<p[i]<<" ";
  cout<<"\n";
  ll ans = 0;
  memset(it, 0, sizeof(it));
  for (int i = 0, j; i < m; i = j)
  {
    for (j = i; j < m && r[p[j]] == r[p[i]]; j++)
      ans += itget(0, am[a[p[j]]] - 1);
    for (j = i; j < m && r[p[j]] == r[p[i]]; j++)
      itadd(am[a[p[j]]], 1);
  }

  #ifdef WIN32
    #warning "it's generally bad idea to use m$ windows"
    cout << ans << endl;
  #else
    printf("%lld\n", ans);
  #endif
  
  return 0;
}
