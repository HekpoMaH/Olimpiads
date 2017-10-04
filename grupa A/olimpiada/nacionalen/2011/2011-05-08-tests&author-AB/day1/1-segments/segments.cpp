#include<iostream>
using namespace std;

int n;
struct p {int x; int y;} c[200], d[200];


int ccw(p p0, p p1, p p2)
{
int dx1=p1.x-p0.x;
int dy1=p1.y-p0.y;
int dx2=p2.x-p0.x;
int dy2=p2.y-p0.y;
return dx1*dy2-dy1*dx2;
}

bool check(p a, p b, p c, p d)
{
  int e1 = ccw(a,b,c);
  int e2 = ccw(a,b,d);
  if(e1==0) return true;
  if(e2==0) return true;
  if(((e1<0)&&(e2>0))||((e1>0)&&(e2<0))) return true;
  return false;
}

int numsec(p a, p b)
{
  int num=0;
  if((a.x==b.x)&&(a.y=b.y)) return num;

  for(int k=1;k<=n;k++)
   if(check(a,b,c[k],d[k])) num++;
  return num;
}


int main()
{
  cin >> n;
  for(int i=1;i<=n;i++) cin >> c[i].x >> c[i].y >> d[i].x >> d[i].y;
  
  int r=0;
  for(int i=1;i<=n;i++)
  for(int j=i+1;j<=n;j++)
  {
    int num;
    num=numsec(c[i],c[j]);
    if(r<num) r=num;
    num=numsec(c[i],d[j]);
    if(r<num) r=num;
    num=numsec(d[i],c[j]);
    if(r<num) r=num;
    num=numsec(d[i],d[j]);
    if(r<num) r=num;
//    num=numsec(c[i],d[i]);
//    if(r<num) r=num;
//    num=numsec(c[j],d[j]);
//    if(r<num) r=num;
    
    
  }
  
  if(r==0)
  { r=1;
    if(n>1) r=2;
  }
  
  cout << r << endl;

}

