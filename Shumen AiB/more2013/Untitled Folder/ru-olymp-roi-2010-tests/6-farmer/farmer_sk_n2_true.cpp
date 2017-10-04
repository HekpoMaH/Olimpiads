#include <cstdio>
#include <cstring>
#include <cassert>

#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef unsigned long long ll;

const int MAX = 2000;
const int maxn = MAX + 10;

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
int live[maxn], isOne[maxn], isGood[maxn];
int left[maxn], right[maxn];

inline void AddEvent( int t, const event &x )
{
  next[en] = head[t], e[en] = x, head[t] = en++;
}

int LX, RX;

inline void Try( int LY, int RY )
{
  int tmp;
  if ((tmp = (RX - LX) * (RY - LY)) > res)
    res = tmp, rx1 = LX, rx2 = RX, ry1 = LY, ry2 = RY;
}

int main()
{
  freopen("farmer.in", "r", stdin);
  freopen("farmer.out", "w", stdout);

  assert(scanf("%d%d ", &h, &w) == 2);
  assert(1 <= h && h <= MAX);
  assert(1 <= w && w <= MAX);
  int is[2] = {0, 0};
  forn(i, h)
  {
    assert(gets(A[i]));
    forn(j, w)
    {
      assert('0' <= A[i][j] && A[i][j] <= '1');
      is[A[i][j] - '0'] = 1;
    }
  }
  assert(is[0]), assert(is[1]);

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
      live[i] = 1;
      isOne[i] = isGood[i] = 0;
      left[i] = i - 1, right[i] = i + 1;
    }
    left[h] = right[h] = h;
    live[h] = isOne[h] = isGood[h] = 0;
    
    en = 0;
    for (int i = lx; i <= w; i++)
      head[i] = -1;
    forn(i, h)
    {
      AddEvent(good[i], event(i, GOOD));
      AddEvent(ones[i], event(i, ONE));
      AddEvent(lcp[i], event(i, JOIN));
    }

    LX = lx;
    for (int rx = w; rx > lx; rx--)
      for (int i = head[rx]; i != -1; i = next[i])
      {
        int pos = e[i].i;
        RX = rx;

        if (e[i].type == ONE)
          isOne[pos] = 1;
        else if (e[i].type == GOOD)
          isGood[pos] = 1;
        else if (live[pos] || live[pos + 1])
        {
          if (live[pos + 1])
            pos = left[pos + 1];

          int r = right[pos];
          live[r] = 0;
          right[pos] = right[r];
          left[right[pos]] = pos;
        }

        int c = pos;
        if (!live[c] || !isGood[c])
          continue;

        Try(c, right[c]);
        if (!isOne[c])
        {
          int L = c, R = right[c];
          int b = left[c];
          int d = right[c];
          if (isOne[b])
            L = b;
          if (isOne[d])
            R = right[d];
          Try(L, R);
        }
        else
        {
          int a, b = left[c];
          if (isGood[b])
            if (isOne[a = left[b]])
              Try(a, right[c]);
            else
              Try(b, right[c]);

          b = right[c];
          if (isGood[b])
            if (isOne[a = right[b]])
              Try(c, right[a]);
            else
              Try(c, right[b]);
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
