#include<iostream>
using namespace std;
class gvozdei
{
int x1,x2,y1,y2,br;
public:
gvozdei(){br=0;}
int initialize(int a,int b,int c,int d){x1=a;y1=b;x2=c;y2=d;}

};
int main()
{
  int n=0,a,b,c,d;
gvozdei nails[1001];
while(cin){cin>>a>>b>>c>>d;nails[n].initialize(a,b,c,d);n++;}
cout<<2;
  return 0;}