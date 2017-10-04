#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
long long a,b,c,d,zs;
char znak;
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
  cin>>a>>b>>znak>>c>>d;int c4=0;
  if(znak=='+')
  {zs=nod(a,b);
  a/=zs;b/=zs;zs=nod(c,d);
  c/=zs;d/=zs;
  int zn=b*d/nod(b,d),ch;
  a*=zn/b;
  c*=zn/d;
  ch=a+c;
  if(ch%zn==0)cout<<ch/zn<<endl;
  else{if(ch>zn){c4=ch/zn;ch%=zn;}zs=nod(ch,zn);ch/=zs;zn/=zs;
  if(c4>0){cout<<c4<<" ";}cout<<ch<<"/"<<zn<<endl;}
  }
  if(znak=='-')
  {
  zs=nod(a,b);
  a/=zs;b/=zs;zs=nod(c,d);
  c/=zs;d/=zs;
  int zn=b*d/nod(b,d),ch,c4;
  a*=zn/b;
  c*=zn/d;
  ch=a-c;//cout<<a<<" "<<b<<" "<<ch<<endl;
  if(ch%zn==0)cout<<ch/zn<<endl;
  else{if(ch>zn){c4=ch/zn;ch%=zn;}zs=nod(ch,zn);ch/=zs;zn/=zs;
  if(c4>0){cout<<c4<<" ";}cout<<ch<<"/"<<zn<<endl;}

  }
  if(znak=='*')
  {
  zs=nod(a,b);
  a/=zs;b/=zs;zs=nod(c,d);
  c/=zs;d/=zs;
  int zn=b*d,ch=a*c;
  if(ch%zn==0)cout<<ch/zn<<endl;
  else{if(ch>zn){c4=ch/zn;ch%=zn;}zs=nod(ch,zn);ch/=zs;zn/=zs;
  if(c4>0){cout<<c4<<" ";}cout<<ch<<"/"<<zn<<endl;}

  }
  if(znak=='/')
  {
  zs=nod(a,b);
  a/=zs;b/=zs;zs=nod(c,d);
  c/=zs;d/=zs;
  int zn=b*c,ch=a*d;//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
  if(ch%zn==0)cout<<ch/zn<<endl;
  else{if(ch>zn){c4=ch/zn;ch%=zn;}zs=nod(ch,zn);ch/=zs;zn/=zs;
  if(c4>0){cout<<c4<<" ";}cout<<ch<<"/"<<zn<<endl;}

  }
  return 0;
}
