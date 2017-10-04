#include<iostream>
using namespace std;
int dn6[1445];
int main()
{
  int m1,m2,m3;
  int a,b,c,d,a2,b2,c2,d2;
  cin>>a>>b>>c>>d;a2=a;b2=b;c2=c;d2=d;
  cin>>m1>>m2>>m3;

  for(int i=1;i<=1440;i++)
  {
    if(a2==0&&b2==0){a2=a;b2=b;}
    if(c2==0&&d2==0){c2=c;d2=d;}
    if(a2>0&&c2>0)dn6[i]=2;
    if(a2>0&&c2==0)dn6[i]=1;
    if(a2==0&&c2>0)dn6[i]=1;
    if(a2==0&&c2==0)dn6[i]=0;
    if(a2==0&&b2>0)b2--;
    if(c2==0&&d2>0)d2--;
    if(a2>0)a2--;
    if(c2>0)c2--;

  }
  if(dn6[m1]==2)cout<<"both"<<endl;
  if(dn6[m1]==1)cout<<"one"<<endl;
  if(dn6[m1]==0)cout<<"none"<<endl;
  if(dn6[m2]==2)cout<<"both"<<endl;
  if(dn6[m2]==1)cout<<"one"<<endl;
  if(dn6[m2]==0)cout<<"none"<<endl;
  if(dn6[m3]==2)cout<<"both"<<endl;
  if(dn6[m3]==1)cout<<"one"<<endl;
  if(dn6[m3]==0)cout<<"none"<<endl;
  return 0;
}
