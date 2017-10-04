#include<iostream>
using namespace std;
int a,b,c;
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
void evklid(int a,int b,int &x1,int &y1)
{
  int x2,y2;
  x1=1;
  x2=0;
  y1=0;
  y2=1;
  while(a!=b)
  {
    if(a>b)
    {
      a-=b;x1-=x2;y1-=y2;
    }
    if(a<b)
    {
      b-=a;x2-=x1;y2-=y1;
    }
  }
}
int main()
{
  int na,kr;
  cin>>a>>b>>c>>na>>kr;
  int nd=nod(a,b);
  if(c%nd!=0)cout<<"nqma re6enie"<<endl;
  else
  {
    int a1=a/nd,b1=b/nd,c1=c/nd;
    int x,y,xk,yk;
    evklid(a1,b1,x,y);
    x*=c1;y*=c1;
    cout<<x<<" "<<y<<endl;
    for(int i=na;i<=kr;i++)
    {
      xk=x+b1*i;
      yk=y-a1*i;
      cout<<xk<<" "<<yk<<endl;
    }
  }
  return 0;
}
