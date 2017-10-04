#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

#define DPI (2*3.1415926536)
#define EPS .0001

typedef pair<double,double> prd;

inline bool lt(double a, double b)  {return a<b-EPS;}
inline bool eq(double a, double b)  {return fabs(a-b)<=EPS;}
inline void normalize(prd & a)  {if (a.first>a.second)  a.second += DPI;}

bool onarc(double a, prd arc)  {
  if (a>=DPI)  a -= DPI;
  return lt(arc.first,a) && lt(a,arc.second)
      || lt(arc.first,a+DPI) && lt(a+DPI,arc.second);
}

double xsect(prd a1, prd a2, prd & x)  {
  bool on11,on12,on21,on22;
  on12 = onarc(a1.first,a2);
  on22 = onarc(a1.second,a2);
  on11 = onarc(a2.first,a1);
  on21 = onarc(a2.second,a1);
  if (!(on11 || on12 || on21 || on22 ||
        eq(a1.first,a2.first) && eq(a1.second,a2.second)))
    return 0.;
  else if (on11 && on12 && on21 && on22) return -1.;
  x.first = on12 ? a1.first : a2.first;
  x.second = on21 ? a2.second : a1.second;
  if (x.first>=DPI)  x.first -= DPI;
  while (x.second-x.first>=DPI)  x.second -= DPI;
  if (eq(x.second,x.first))  return 0.;
  normalize(x);
  return x.second-x.first;
}

int main()  {
  prd o,g1,g2,a[3],x;
  double s,s1,s2,s3;
  int i,p;
  cin >> o.first >> o.second;
  for (i=0; i<3; ++i)  {
    cin >> g1.first >> g1.second >> g2.first >> g2.second;
    a[i].first = atan2(g1.second-o.second,g1.first-o.first);
    a[i].second = atan2(g2.second-o.second,g2.first-o.first);
    if (a[i].first<0.)  a[i].first += DPI;
    if (a[i].second<0.)  a[i].second += DPI;
    normalize(a[i]);
  }
  s1 = xsect(a[1],a[2],x);
  s2 = xsect(a[2],a[0],x);
  s3 = xsect(a[0],a[1],x);
  if (s1<0 || s2<0 || s3<0)  p = 100;
  else  {
    s = a[0].second-a[0].first + a[1].second-a[1].first + a[2].second-a[2].first - (s1+s2+s3);
    if (s1>0. && s2>0. && s3>0.)  s += xsect(x,a[2],x);
    p = (int)(.5+s*100./DPI);
  }
  cout << p << endl;
  return 0;
}
