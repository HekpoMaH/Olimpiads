#include<iostream>
using namespace std;
struct point
{
  int x,y;
};
point prest(point a1,point b1,point m1,point m2)
{
  int ax,bx,cx,ay,by,cy,d,d1,d2;
  point p;
  ax=a1.y-b1.y;
  bx=b1.x-a1.x;
  cx=a1.x*b1.y-b1.x*a1.y;
  ay=m1.y-m2.y;
  by=m2.x-m1.x;
  cy=m1.x*m2.y-m2.x*m1.y;
  d=ax*by-bx*ay;
  d1=(-cx)*by-bx*(-cy);
  d2=ax*(-cy)-(-cx)*ay;
  p.x=d1/d;p.y=d2/d;
  return p;
}
int nod(int a,int b)
{
  int r;
  while(b!=0)
  {
    r=a%b;
    a=b;
    b=r;
  }
  return a;
}
point a,b,c,d,m,t1,t2,m0;
int main()
{
  m0.x=0;m0.y=0;
  cin>>a.x>>a.y>>c.x>>c.y>>m.x>>m.y;
  b.x=c.x;b.y=a.y;
  d.x=a.x;d.y=c.y;
  t1=prest(m0,m,a,b);
  t2=prest(m0,m,d,c);
  //cout<<t1.x<<" "<<t1.y<<" "<<t2.x<<" "<<t2.y<<endl;
  cout<<nod(abs(t1.x-t2.x),abs(t1.y-t2.y))+1<<endl;
  return 0;
}
