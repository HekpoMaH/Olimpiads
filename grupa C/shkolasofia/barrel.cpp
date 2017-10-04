#include<iostream>
using namespace std;
int x1,y1,d,mn=999999,xm,ym,a1,b1;
void evklid(int a,int b,int &x1,int &y1,int &d)
{
  int q,t,x2,y2,r;
  x1=1;y1=0;x2=0;y2=1;
  while(b!=0)
  {
    //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    q=a/b;
    r=a%b;
    a=b;
    b=r;
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
  int a,b,c;
  cin>>a>>b>>c;
  evklid(a,b,x1,y1,d);
  if(c%d!=0){cout<<"NO SOLUTION"<<endl;return 0;}
  a1=a;b1=b;a/=d;b/=d;c/=d;
  x1*=c;y1*=c;
  int xt,yt;
  //cout<<x1<<" "<<y1<<endl;system("pause");
  mn=abs(x1)*a+abs(y1)*b;
  xm=x1;ym=y1;
  for(int i=-c;i<=c;i++)
  {
    xt=x1-b*i;
    yt=y1+a*i;
    //cout<<xt<<" "<<yt<<" "<<a*xt+b*yt<<endl;system("pause");
    if(a*abs(xt)+b*abs(yt)<=mn)
    {
      //cout<<mn<<" "<<a*xt+b*yt<<endl;
      mn=a*abs(xt)+b*abs(yt);
      xm=xt;
      ym=yt;
    }
  }
  if(mn==999999)cout<<"NO SOLUTION"<<endl;
  else
  {
    cout<<abs(xm)+abs(ym)<<endl;
    cout<<abs(xm)*a1+abs(ym)*b1<<endl;
    if(xm>0)for(int i=0;i<xm;i++)cout<<"+1"<<endl;
    if(ym>0)for(int i=0;i<ym;i++)cout<<"+2"<<endl;
    if(xm<0)for(int i=0;i<abs(xm);i++)cout<<"-1"<<endl;
    if(ym<0)for(int i=0;i<abs(ym);i++)cout<<"-2"<<endl;
  }
  return 0;
}
