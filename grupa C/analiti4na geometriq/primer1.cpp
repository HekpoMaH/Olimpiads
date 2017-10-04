#include<iostream>
using namespace std;
int ax,ay,bx,by,cx,cy;
bool isst(int ax,int ay,int bx,int by,int cx,int cy)
{
  int x1=bx-ax;
  int y1=by-ay;
  int x2=cx-ax;
  int y2=cy-ay;
  return x1*y2==y1*x2;
}
int main()
{
  cin>>ax>>ay>>bx>>by>>cx>>cy;
  cout<<isst(ax,ay,bx,by,cx,cy);
  return 0;
}
