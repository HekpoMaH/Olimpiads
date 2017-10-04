#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long long n,used[1001],br,i;
struct point
{
  double x,y;
};
point a[1001],b[1001];
double dist(point a, point b)
{
  return sqrt((a.y-b.y)*(a.y-b.y)+(a.x-b.x)*(a.x-b.x));
}
bool crossing(point a, point b, point c, point d)
{
  double a1=a.y-b.y;
  double b1=b.x-a.x;
  double c1=a.x*b.y-b.x*a.y;
  double a2=c.y-d.y;
  double b2=d.x-c.x;
  double c2=c.x*d.y-d.x*c.y;
  double k=a1*b2-a2*b1;
  double k1=-c1*b2+c2*b1;
  double k2=a1*-c2+a2*c1;
  if(a1*b2==a2*b1&&b1*c2!=c1*b2) return false;
  else if(a1*b2==a2*b1&&b1*c2!=c1*b2) return true;
  point p;
  p.x=(double)k1/k;
  p.y=(double)k2/k;
  //if(dist(p,a)+dist(p,b)==dist(a,b)) {cout<<1<<endl; return true;}
  //if(dist(p,c)+dist(p,d)==dist(c,d)) {cout<<2<<endl; return true;}
  if((p.x>=min(a.x,b.x)&&p.x<=max(a.x,b.x))&&(p.y>=min(a.y,b.y)&&p.y<=max(a.y,b.y))&&(p.x>=min(c.x,d.x)&&p.x<=max(c.x,d.x))&&(p.y>=min(c.y,d.y)&&p.y<=max(c.y,d.y))) return true;
  return false;
}
void wave(point p1, point p2)
{
  for(long long i=1; i<=n-1; i++)
  {
    if(used[i]==0&&crossing(p1,p2,a[i],b[i])) {used[i]=1; br++; wave(a[i],b[i]);}
  }
}
int main()
{
  i=1;
  while(scanf("%lf%lf%lf%lf",&a[i].x,&a[i].y,&b[i].x,&b[i].y)!=-1)
  {
    i++;
  }
  n=i-1;
  for(i=1; i<=n-1; i++)
  {
    if(used[i]==0&&crossing(a[n],b[n],a[i],b[i])) {used[i]=1; br++; wave(a[i],b[i]);}
  }
  printf("%lld\n",n-br-1);
  return 0;
}
