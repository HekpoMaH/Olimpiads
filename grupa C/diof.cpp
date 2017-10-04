#include<iostream>
using namespace std;
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
void evklid(int a,int b,int &x1,int &y1,int &d)
{
  int q,t,r,x2,y2;
  x1=1;y1=0;x2=0;y2=1;
  while(b!=0)
  {
    q=a/b;
    r=a%b;
    a=b;b=r;
    t=x2;
    x2=x1-q*x2;
    x1=t;
    t=y2;
    y2=y1-q*y2;
    y1=t;
  }
  d=a;
}
int main()
{
  int a,b,c,x1,y1,d;
  cin>>a>>b>>c;
  d=nod(a,b);
  if(c%d!=0){cout<<"impossible"<<endl;return 0;}
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
