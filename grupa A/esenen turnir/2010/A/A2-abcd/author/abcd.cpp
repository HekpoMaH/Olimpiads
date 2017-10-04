#include <iostream>
#include <math.h>
using namespace std;
typedef struct
{double x,y;
} Point;
double p,q,r;
double round(double d)
{return floor(10000*d+0.5)/10000;
}
double AreaX2(Point A, Point B, Point C)
{return fabs((A.x-C.x)*(B.y-A.y)-(A.x-B.x)*(C.y-A.y));
}
double minArea(double eps)
{
  Point A,D,C;
  double m,s,t=0,st=1;
  A.x=-p-0.5*q;A.y=0;
  D.x=p+0.5*q;D.y=0;
  C.x=0.5*q;C.y=sqrt(p*(p+q));
  do
  {m=AreaX2(A,D,C);
   do
   {t+=st;
    D.y=2*t;
    C.y=t+sqrt(t*t+p*(p+q));
    s=AreaX2(A,D,C);
    if (s<m) m=s;
    else break;
   }while (true);
   t=max(0.0,t-2*st);
   st/=10;
   if (st<eps) return m;
   D.y=2*t;
   C.y=t+sqrt(t*t+p*(p+q));
  }while (true);
}
int main(void)
{
  cin>>p>>q>>r;
  if (p!=r) {cout<<0<<endl; return 0;}
  cout.setf(ios::fixed,ios::floatfield);
  cout.precision(4);
  cout<<round(minArea(0.00001))<<endl;
  return 0;
}
