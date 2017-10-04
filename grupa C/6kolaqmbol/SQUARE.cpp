#include<iostream>
using namespace std;
struct point
{
  long long x,y;
};
long long orient(point a,point b,point p)
{
  return a.x*b.y+p.x*a.y+b.x*p.y-p.x*b.y-a.x*p.y-b.x*a.y;
}
point p,a,b,c,d;
long long o1,o2,o3,o4,s=1,sn,i=1,oo1,oo2,oo3,oo4,t,n;
int main()
{
  cin>>p.x>>p.y;
  while(1)
  {
    a.x=-s;a.y=-s;
    b.x=s;b.y=-s;
    c.x=s;c.y=s;
    d.x=-s;d.y=s;
    if(orient(a,b,p)>=0)o1=1;
    if(orient(b,c,p)>=0)o2=1;
    if(orient(c,d,p)>=0)o3=1;
    if(orient(d,a,p)>=0)o4=1;
    if(o1&&o2&&o3&&o4)
    {
      t=1;n=i;
      a.x=0;a.y=-s;
      b.x=s;b.y=0;
      c.x=0;c.y=s;
      d.x=-s;d.y=0;
      if(orient(a,b,p)>=0)oo1=1;
      if(orient(b,c,p)>=0)oo2=1;
      if(orient(c,d,p)>=0)oo3=1;
      if(orient(d,a,p)>=0)oo4=1;
      if(oo1&&oo2&&oo3&&oo4&&i>1){t=2;n--;}
      break;
    }
    i++;
    s*=2;
  }
  if(t==1)cout<<"K";
  if(t==2)cout<<"C";
  cout<<n<<endl;
  return 0;
}
