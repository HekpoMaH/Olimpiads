#include<iostream>
using namespace std;
int x0,y0,x1,y1,x2,y2,x3,y3;
int a,b,c,a2,b2,c2,d,d1,d2;
int main()
{
  cin>>x0>>y0>>x1>>y1>>x2>>y2>>y3>>y3;
  a=y0-y1;
  b=x1-x0;
  c=x0*y1-x1*y0;
  a2=y2-y3;
  b2=x3-x2;
  c2=x2*y3-x3*y2;
  d=a*b2-b*a2;
  d1=(-c)*b2-b*(-c2);
  d2=a*(-c2)-(-c)*a2;
  int xp,yp;
  xp=d1/d;
  yp=d2/d;
  cout<<xp<<" "<<yp<<endl;
  return 0;
}
