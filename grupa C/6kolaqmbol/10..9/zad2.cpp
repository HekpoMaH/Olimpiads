#include<iostream>
using namespace std;
struct point
{
  int x,y;
};
int orient(point a,point b,point p)
{
  return a.x*b.y+p.x*a.y+b.x*p.y-p.x*b.y-a.x*p.y-b.x*a.y;
}
point a,b,c,p;
int ax,bx,cx,o1,o2,o3;
int main()
{
  cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>p.x>>p.y;
  if(orient(a,b,p))o1=1;
  if(orient(b,c,p))o2=1;
  if(orient(c,a,p))o3=1;
  if(o1==o2&&o2==o3)cout<<(double)abs(orient(a,b,c)/2);
  else cout<<0<<endl;
  return 0;
}
