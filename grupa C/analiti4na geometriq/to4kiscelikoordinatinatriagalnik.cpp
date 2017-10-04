#include<iostream>
using namespace std;
int x1,y1,x2,y2,x3,y3;
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
int main()
{
  cin>>x1>>y1>>x2>>y2>>x3>>y3;
  int d=abs(x1-x2);
  int c=abs(y1-y2);
  int sum=0;
  sum+=nod(c,d)+1;
  c=abs(x1-x3);d=abs(y1-y3);
  sum+=nod(c,d)+1;
  c=abs(x2-x3);d=abs(y2-y3);
  sum+=nod(c,d)+1;
  sum-=3;
  cout<<sum<<endl;
  return 0;
}
