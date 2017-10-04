#include<iostream>
using namespace std;
int s,u,c;
int gcd(int a,int b)
{
  int r;
  while(b!=0)
  {
    r=a%b;a=b;b=r;
  }
  return 0;
}
void evkl(int a,int b,int &x1,int &x2,int &d)
{
  int x2,y2;
  x1=1;x2=0;y1=0;y2=1;
  while(a!=b)
  {
    if(a>b){a-=b;x1-=x2;y1-=y2;}
    if(a<b){b-=a;x2-=x1;y2-=y1;}
  }
  d=b;
}
void diof(int x0,int y0,int &k,int x[],int y[],int s,int u,int c)
{
  k=0;int i,xx,yy;
  for(i=-s;i<=s;i++)
  {
    xx=x0-c*i;
    yy=y0+u*i;
    if(yy>=0&&x>=0){x[k]=xx;y[k]=yy;k++;}
  }
}
int main()
{
  int a,b,d,x[100],y[100],xx,yy,p,i,k,l=0,x0,y0,