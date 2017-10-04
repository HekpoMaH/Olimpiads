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
  int x2,y2,q,r,t;
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
  return;
}
int main()
{
  int a,b,c,x1,y1,d,na,kr,xk,yk,a1,b1;
  cin>>a>>b>>c>>na>>kr;a1=a;b1=b;
  d=nod(a,b);
  if(c%d!=0){cout<<"Impossible"<<endl;return 0;}
  a/=d;b/=d;c/=d;
  evklid(a,b,x1,y1,d);
  x1*=c;y1*=c;
  for(int i=na;i<=kr;i++)
  {
    xk=x1+b1*i;
    yk=y1-a1*i;
    cout<<xk<<" "<<yk<<endl;
  }
  return 0;
}
