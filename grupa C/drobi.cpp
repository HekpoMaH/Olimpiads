#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
long long a,b,c,d;
int nod(long long a1,long long b1)
{
  int r;
  while(b1!=0)
  {
    r=a1%b1;
    a1=b1;
    b1=r;
  }
  return a1;
}
int main()
{
  cin>>a>>b>>c>>d;
  a/=nod(a,b);b/=nod(a,b);
  c/=nod(c,d);d/=nod(c,d);
  int zn=b*d/nod(b,d),ch;
  a*=zn/b;
  c*=zn/d;
  ch=a+b;
  if(ch%zn==0)cout<<ch/zn<<endl;
  else{ch/=nod(ch,zn);zn/=nod(ch,zn);
  cout<<ch<<"/"<<zn<<endl;}
  return 0;
}
