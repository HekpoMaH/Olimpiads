#include<iostream>
using namespace std;
int a,b,m,nd;
int nod(int x,int y)
{
  int r;
  while(y!=0)
  {
    r=x%y;
    x=y;
    y=r;
  }
  return x;
}
void evklid(int a,int b,int &x1,int &y1,int &d)
{
  int q,t,x2,y2,r;
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
int main()
{
  cin>>a>>b>>m;
  nd=nod(a,m);
  int x1,y1,d,x,y;
  if(b%nd!=0)cout<<"NR"<<endl;
  if(b%nd==0)
  {
    evklid(a,m,nd,x1,y1,d);
    x=(b+y1)%m;
