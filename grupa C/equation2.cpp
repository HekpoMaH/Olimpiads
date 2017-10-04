#include<iostream>
using namespace std;
int a,b,c,d,e,k[5],dela[21000],cur,br,f;
void izhod(int iz)
{
  if(iz<0)cout<<"(x+"<<-iz<<")";
  if(iz>0)cout<<"(x"<<-iz<<")";
  return;
}
bool horner(int &a,int &b,int &c,int &d,int &e,int x,int &curr)
{
  int a1[7];
  a1[0]=a;a1[1]=b;a1[2]=c;a1[3]=d;a1[4]=e;
  int sum=0,b1[5];
  for(int i=0;i<curr;i++)
  {
    sum=sum*x+a1[i];
    b1[i]=sum;
  }
  for(int i=0;i<curr;i++)a1[i]=b1[i];
  if(sum==0)
  {
    a=b1[0];b=b1[1];c=b1[2];d=b1[3];e=b1[4];
    izhod(x);
    curr--;
    return 1;
  }
  return 0;
}
int main()
{
  a=1;
  cin>>b>>c>>d>>e;
  cur=5;
  for(int i=1;i<=abs(e);i++)
  {
    if(e%i==0)
    {
      dela[br]=i;
      br++;
      dela[br]=-i;
      br++;
    }
  }
  for(int i=0;i<br;i++)
  {
    do
    {
      f=horner(a,b,c,d,e,dela[i],cur);
    }while(f!=0);
  }
  int k[6],lz=9;
  k[0]=a;k[1]=b;k[2]=c;k[3]=d;k[4]=e;
  br=0;
  for(int i=0;i<5;i++)
  {
    if(k[i]!=0)lz=i;
  }
  if(lz!=9)
  {
    cout<<"(";
    for(int i=0;i<=lz;i++)
    {
      if(k[i]!=0)
      {
        if(i==lz)
        {
          if(k[i]<0)cout<<k[i]<<")"<<endl;
          if(k[i]>0)cout<<"+"<<k[i]<<")"<<endl;
        }
        else
        {
          if(k[i]>0)cout<<"+"<<k[i]<<"x^"<<lz-i;
          if(k[i]<0)cout<<k[i]<<"x^"<<lz-i;
        }
      }
    }
  }
  return 0;
}
