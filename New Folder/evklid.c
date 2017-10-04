#include<iostream>
using namespace std;
int x1,y1,d;
void evklid(int a,int b,int &x1,int &y1,int &d)
{
  int q,t,x2,y2,r;
  x1=1;y1=0;x2=0;y2=1;
  while(b!=0)
  {
    q=a/b;r=a%b;
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
  int a,b;
  cin>>a>>b;
  evklid(a,b,x1,y1,d);
  cout<<x1<<" "<<y1<<endl;
  return 0;
}
