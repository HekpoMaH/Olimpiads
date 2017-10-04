#include<iostream>
using namespace std;
int x0,y0,x1,y1,x2,y2;
int a,b,c;
int main()
{
  cin>>x0>>y0>>x1>>y1>>x2>>y2;
  a=y0-y1;
  b=x1-x0;
  c=x0*y1-x1*y0;
  if(a*x2+b*y2+c>0)cout<<"yes"<<endl;
  else cout<<"no"<<endl;
  return 0;
}
