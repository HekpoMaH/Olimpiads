#include<iostream>
#include<cmath>
using namespace std;

void evklid(long long a,long long b,long long &x1,long long &y1,long long &d)
{
  long long q,t,x2,y2,r;
  x1=1;y1=0;x2=0;y2=1;
  while(b!=0)
  {
    //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    q=a/b;
    r=a%b;
    a=b;
    b=r;
    t=x2;
    x2=x1-q*x2;
    x1=t;
    t=y2;
    y2=y1-q*y2;
    y1=t;
  }
  d=a;
}
long long nod(long long x,long long y)
{
  long long r;
  while(y!=0)
  {
    r=x%y;
    x=y;
    y=r;
  }
  return x;
}
int main()
{
  long long a,b,c;
  long long x1,y1,d;
  cin>>a>>b>>c;
  d=nod(a,b);
  if(c%d!=0){cout<<"Impossible"<<endl;return 0;}
  a/=d;b/=d;c/=d;
  evklid(a,b,x1,y1,d);
  x1*=c;y1*=c;
  long long xk,yk,br=0,i,i2;
  i=(long long)ceil(-1.0*x1/b);
  i2=(long long)floor(1.0*y1/a);
  br=i2-i+1;
  if(br==0)cout<<"Impossible"<<endl;
  else cout<<br<<endl;
  return 0;
}
