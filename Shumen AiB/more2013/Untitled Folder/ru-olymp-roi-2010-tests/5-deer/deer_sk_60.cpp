#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>

#include <algorithm>
#include <iostream>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long double dbl;

const dbl eps = 1e-9;

struct pnt;

struct pnt
{
  dbl x, y;

  pnt() { }
  pnt( dbl _x, dbl _y ) : x(_x), y(_y) { }
  pnt( dbl ang ) : x(cos(ang)), y(sin(ang)) { }

  pnt operator - ( pnt p ) { return pnt(x - p.x, y - p.y); }
  pnt operator + ( pnt p ) { return pnt(x + p.x, y + p.y); }
  pnt operator * ( dbl k ) { return pnt(x * k, y * k); }
  pnt operator / ( dbl k ) { return pnt(x / k, y / k); }
  dbl operator * ( pnt p ) { return x * p.y - y * p.x; }

  void read() { cin >> x >> y; }
  dbl d2() { return x * x + y * y; }
  dbl d() { return sqrt(d2()); }
  pnt norm() { return *this / d(); }
  dbl ang() { return atan2(y, x); }
  pnt ort() { return pnt(-y, x); }

  char *str()
  {
    char *s = new char[99];
    sprintf(s, " %.5lf %.5lf ", (double)x, (double)y);
    return s;
  }

  bool operator == ( pnt p ) { return fabs(x - p.x) + fabs(y - p.y) < eps; }
};

template <class T> bool operator != ( T a, T b ) { return !(a == b); }

const int maxn = 103;

int n;
dbl len, Res = 0;
pnt c, q, p[maxn];

pnt &P( int i ) { return p[(i % n + n) % n]; }

dbl Area()
{
  dbl sum = 0;
  forn(i, n)
    sum += p[i] * p[(i + 1) % n];
  return sum;
}

dbl Area( dbl ang, dbl r )
{
  return ang * r * r * 0.5;
}

void MakeLess( dbl &a, dbl st )
{
  while (a < st - eps) a += 2 * M_PI;
  while (a > st + eps) a -= 2 * M_PI;
}

dbl Cor( dbl a )
{
  while (a < -eps) a += 2 * M_PI;
  while (a >= 2 * M_PI - eps) a -= 2 * M_PI;
  if (a > 2 * M_PI - a) a = 2 * M_PI - a;
  return a;
}

dbl sqr( dbl x ) { return x * x; }

int Intr( pnt st1, pnt a1, pnt b1, dbl r1, pnt st2, pnt a2, pnt b2, dbl r2 )
{
  if (st1 == st2)
    return 0;
  st2 = st2 - st1;

  dbl A, B, C, no;
  A = 2 * st2.x;
  B = 2 * st2.y;
  C = sqr(r2) - sqr(r1) - st2.d2();
  no = sqrt(A * A + B * B);
  A /= no, B /= no, C /= no;

}

int main()
{ 
  freopen("deer.in", "r", stdin);
  freopen("deer.out", "w", stdout);

  cin >> n;
  forn(i, n)
    p[i].read();
  assert(Area() < 0);
  q.read();
  cin >> len;

  forn(i, n)
    c = c + P(i);
  c = c / n;
  forn(i, n)
    p[i] = p[i] - c;
  q = q - c;
  
  int st = -1;
  forn(i, n)
    if ((P(i + 1) - P(i)) * (q - P(i)) == 0 &&
        min(P(i).x, P(i + 1).x) <= q.x && q.x <= max(P(i).x, P(i + 1).x) &&
        min(P(i).y, P(i + 1).y) <= q.y && q.y <= max(P(i).y, P(i + 1).y))
      st = i;
  assert(st != -1);

  if (q != P(st) && q != P(st + 1))
  {
    for (int i = n++; i > st; i--)
      p[i] = p[i - 1];
    p[++st] = q;
  }
  else if (q != P(st))
    st++;

  dbl rest, tmp;
  int end;
  pnt L, R;

  rest = len;
  end = st;
  while ((end - (st + 1)) % n != 0 && rest > (tmp = (P(end - 1) - P(end)).d()))
    rest -= tmp, end--;
  if ((end - (st + 1)) % n == 0)
    L = P(end);
  else
    L = P(end) + (P(end - 1) - P(end)).norm() * rest;

  rest = len;
  end = st;
  while ((end - (st - 1)) % n != 0 && rest > (tmp = (P(end + 1) - P(end)).d()))
    rest -= tmp, end++;
  if ((end - (st - 1)) % n == 0)
    R = P(end);
  else
    R = P(end) + (P(end + 1) - P(end)).norm() * rest;

  dbl a0 = P(st).ang();
  dbl aL = L.ang();
  dbl aR = R.ang();
  MakeLess(aL, a0);
  MakeLess(aR, a0);

  if (aL <= aR + eps) // score = 60
  {
    pnt v, v1, v0 = (P(st + 1) - P(st - 1)).norm().ort();
    int iL, iR;

    iL = st, v = v0, rest = len;
    while (rest > (tmp = (v1 = P(iL - 1) - P(iL)).d()))
    {
      Res += Area(Cor(v.ang() - v1.ang()), rest);
      rest -= tmp, v = v1.norm(), iL--;
    }
    Res += Area(Cor(v.ang() - v1.ang()), rest);

    iR = st, v = v0, rest = len;
    while (rest > (tmp = (v1 = P(iR + 1) - P(iR)).d()))
    {
      Res += Area(Cor(v.ang() - v1.ang()), rest);
      rest -= tmp, v = v1.norm(), iR++;
    }
    Res += Area(Cor(v.ang() - v1.ang()), rest);
  }
  else
  {
    puts("Fail!");
  }
  printf("%.20lf\n", (double)Res);
  return 0;
}
