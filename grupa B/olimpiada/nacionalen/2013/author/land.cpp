#include <iostream>
#include <cmath>
using namespace std;
typedef struct {double x,y;} Point;
typedef Point Quadrangle[4];
void rotate(Point &A,double a)
{Point A1;
 A1.x=A.x*cos(a)-A.y*sin(a);
 A1.y=A.x*sin(a)+A.y*cos(a);
 A=A1;
}
void getDims(Quadrangle q,double &minx,double &maxx,double &miny,double &maxy)
{int i;
 minx=q[0].x;
 for (i=1;i<4;i++) if (q[i].x<minx) minx=q[i].x;
 maxx=q[0].x;
 for (i=1;i<4;i++) if (q[i].x>maxx) maxx=q[i].x;
 miny=q[0].y;
 for (i=1;i<4;i++) if (q[i].y<miny) miny=q[i].y;
 maxy=q[0].y;
 for (i=1;i<4;i++) if (q[i].y>maxy) maxy=q[i].y;
}
void rotQadr(Quadrangle &q,double a)
{for (int i=0;i<4;i++) rotate(q[i],a);
}
double OneLocalSol(Quadrangle q,double eps,double sta,double enda,double st)
{double minx,maxx,miny,maxy,a,d1,d2;
 Quadrangle q1;
 memcpy(&q1,q,sizeof(Quadrangle));
 getDims(q1,minx,maxx,miny,maxy);
 d1=max(maxx-minx,maxy-miny);
 for (a=sta+st;a<=enda;a+=st)
 {rotQadr(q1,st);
  getDims(q1,minx,maxx,miny,maxy);
  d2=max(maxx-minx,maxy-miny);
  if (d2>=d1)
  {if (d2-d1<eps) return d1;
   rotQadr(q1,-2*st);
   return OneLocalSol(q1,eps,max(sta,a-2*st),a,st/10);
  }
  d1=d2;
 }
}
double solve(Quadrangle q,double eps)
{double minSide,p1,p2,t,minx,maxx,miny,maxy,a,st=0.001,tmp;
 Quadrangle q1,q2;
 memcpy(&q1,q,sizeof(Quadrangle));
 getDims(q1,minx,maxx,miny,maxy);
 minSide=max(maxx-minx,maxy-miny);
 p1=p2=minSide;
 for (a=st;a<=M_PI/2;a+=st)
 {rotQadr(q1,st);
  getDims(q1,minx,maxx,miny,maxy);
  t=max(maxx-minx,maxy-miny);
  if (t>p2 && p2<p1) //local min
  {memcpy(&q2,q1,sizeof(Quadrangle));
   rotQadr(q2,-2*st);
   tmp=OneLocalSol(q2,eps,max(0.0,a-2*st),a,st/10);
   if (tmp<minSide) minSide=tmp;
  }
  p1=p2;
  p2=t;
 }
 return minSide;
}
int main()
{ Quadrangle q;
  for (int i=0;i<4;i++) cin>>q[i].x>>q[i].y;
  cout.precision(3);
  cout<<fixed<<solve(q,0.00001)<<endl;
  return 0;
}
