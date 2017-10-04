#include<iostream>
using namespace std;
int x1,y1,x2,y2;
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
  cin>>x1>>y1>>x2>>y2;
  int d=abs(x1-x2);
  int c=abs(y1-y2);
  cout<<nod(d,c)+1<<endl;
  return 0;
}
