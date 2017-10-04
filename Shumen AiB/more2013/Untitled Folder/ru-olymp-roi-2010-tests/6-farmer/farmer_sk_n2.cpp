#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef unsigned long long ll;

const int maxn = 2010;

void Finalize( int res, int rx1, int ry1, int rx2, int ry2, char (*s)[maxn] );

int h, w, res = 0, rx1, ry1, rx2, ry2;
char A[maxn][maxn];

int ones[maxn], lcp[maxn], good[maxn], num[maxn];

enum {GOOD, ONE, JOIN};

struct event
{
  int i, type;

  event() { }
  event( int _i, int _type ) : i(_i), type(_type) { }
};

const int maxe = maxn * 3;

int en, head[maxn], next[maxe];
event e[maxe];
int p[maxn], size[maxn], isOne[maxn], isGood[maxn];
int left[maxn], right[maxn];

inline void AddEvent( int t, const event &x )
{
  next[en] = head[t], e[en] = x, head[t] = en++;
}

int Get( int v )
{
  if (!(0 <= v && v < h))
    return h;
  return v == p[v] ? v : (p[v] = Get(p[v]));
}

inline void Join( int a, int b )
{
  int l = left[a], r = right[b];
  if (size[a] < size[b])
    swap(a, b);
  p[b] = a, size[a] += size[b];
  left[a] = l, right[a] = r;
}

int LX, RX;

inline void Try( int LY, int RY )
{
  int tmp;
  if ((tmp = (RX - LX) * (RY - LY + 1)) > res)
    res = tmp, rx1 = LX, rx2 = RX, ry1 = LY, ry2 = RY + 1;
}

inline void Try1( int a )
{
  if (isGood[a])
    Try(left[a], right[a]);
}

inline void Try2( int a, int b )
{
  if (isGood[a] && isGood[b] && (isOne[a] + isOne[b] >= 1))
    Try(left[a], right[b]);
}

inline void Try3( int a, int b, int c )
{
  if (isGood[a] && isGood[b] && isGood[c] && (isOne[a] + isOne[b] + isOne[c] >= 2))
    Try(left[a], right[c]);
}

int main()
{
  freopen("farmer.in", "r", stdin);
  freopen("farmer.out", "w", stdout);

  scanf("%d%d ", &h, &w);
  forn(i, h)
    gets(A[i]);

  forn(i, h)
  {
    ones[i] = lcp[i] = good[i] = 0;
    num[i] = (A[i][0] == '0');
  }
  
  forn(lx, w)
  {
    forn(i, h)
    {
      ones[i] = max(lx, ones[i] - 1);
      while (ones[i] < w && A[i][ones[i]] == '1')
        ones[i]++;

      lcp[i] = max(lx, lcp[i] - 1);
      while (lcp[i] < w && A[i][lcp[i]] == A[i + 1][lcp[i]])
        lcp[i]++;

      if (lx > 0 && A[i][lx] == '1' && A[i][lx - 1] == '0')
        num[i]--;
      while (good[i] < w && num[i] < 2)
        num[i] += (A[i][good[i]] == '1' && A[i][good[i] + 1] == '0'), good[i]++;
    }

    forn(i, h)
    {
      p[i] = i, size[i] = 1;
      isOne[i] = isGood[i] = 0;
      left[i] = right[i] = i;
    }
    p[h] = h, left[h] = right[h] = -239;
    isOne[h] = isGood[h] = 0;
    
    en = 0;
    for (int i = lx; i <= w; i++)
      head[i] = -1;
    forn(i, h)
    {
      AddEvent(good[i], event(i, GOOD));
      AddEvent(ones[i], event(i, ONE));
      AddEvent(lcp[i], event(i, JOIN));
    }

    for (int rx = w; rx > lx; rx--)
      for (int i = head[rx]; i != -1; i = next[i])
      {
        int pos = e[i].i;
        switch (e[i].type)
        {
          case ONE: isOne[Get(pos)] = 1; break;
          case GOOD: isGood[Get(pos)] = 1; break;
          case JOIN: Join(Get(pos), Get(pos + 1)); break;
        }

        LX = lx, RX = rx;
        int c = Get(pos);

        Try1(c);
        if (isGood[c])
        {
          int b = Get(left[c] - 1);
          int d = Get(right[c] + 1);
          Try2(b, c);
          Try2(c, d);
          Try3(b, c, d);
          if (isGood[b]) Try3(Get(left[b] - 1), b, c);
          if (isGood[d]) Try3(c, d, Get(right[d] + 1));
        }
      }
  }

  Finalize(res, rx1, ry1, rx2, ry2, A);
  return 0;
}

void Finalize( int res, int rx1, int ry1, int rx2, int ry2, char (*s)[maxn] )
{
  int xmi = rx2, xma = rx1, ymi = ry2, yma = ry1;
  for (int x = rx1; x < rx2; x++)
    for (int y = ry1; y < ry2; y++)
      if (s[y][x] == '0')
      {
        xmi = min(xmi, x), xma = max(xma, x);
        ymi = min(ymi, y), yma = max(yma, y);
      }
  if (xmi > xma)
    forn(x, w)
      forn(y, h)
        if (s[y][x] == '0')
          xmi = xma = x, ymi = yma = y;

  printf("%d %d %d %d\n", ymi + 1, xmi + 1, yma + 1, xma + 1);
  printf("%d %d %d %d\n", ry1 + 1, rx1 + 1, ry2, rx2);
  printf("%d\n", res);
}
