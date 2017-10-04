#include<iostream>
using namespace std;
int a,b,c,d,e,dela[21000],cur,br;
void izhod(int a)
{
  cout<<"(x";
  //cout<<a<<endl;
  if(a>0)cout<<-a;
  if(a<0)cout<<"+"<<-a;
  cout<<")";
}
bool horner(int &a,int &b,int &c,int &d,int &e,int x,int &curr)
{
  int a1[7];
  a1[0]=a;a1[1]=b;a1[2]=c;a1[3]=d;a1[4]=e;
  int sum=0,b1[5];
  for(int i=0;i<curr;i++)
  {
    sum=sum*x+a1[i];
    //cout<<"sum="<<sum<<" x="<<x<<" a1[i]="<<a1[i]<<endl;
    b1[i]=sum;
  }
  for(int i=0;i<curr;i++)a1[i]=b1[i];

  //cout<<curr<<endl;
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
  ios::sync_with_stdio(false);
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
      //cout<<dela<<" "<<-dela<<endl;
    }
  }
  int f;
  for(int i=0;i<br;i++)
  {
    //cout<<"a="<<a<<" b="<<b<<" c="<<c<<" d="<<d<<" e="<<e<<endl;
    do
    {
      f=horner(a,b,c,d,e,dela[i],cur);
    }while(f!=0);
  }
  //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
  int k[5],br=0,lz=4,l=0;
  k[0]=a;
  k[1]=b;
  k[2]=c;
  k[3]=d;
  k[4]=e;
  for(int i=0;i<5;i++)
  {
    if(k[i]!=0)
    {
      br++;
    }
    if(k[i]==0&&l==0){lz=i-1;l=1;/*cout<<lz<<endl;*/}
    if(k[i]!=0){l=0;lz=i;}
    //cout<<"lz="<<lz<<endl;
  }
  //cout<<lz<<" "<<br<<endl;
  if(br>1)
  {
    //cout<<lz<<endl;
    cout<<"(";
    for(int i=0;i<=lz;i++)
    {
      if(k[i]!=0)
      {
        //cout<<k[i]<<" "<<lz-i<<endl;
        if(i==lz)
        {
          if(k[i]<0)cout<<k[i];
          if(k[i]>0)cout<<"+"<<k[i];
        }
        else
        {if(k[i]<0)
        {
          cout<<k[i]<<"x^"<<lz-i;
        }
        if(k[i]>0)
        {
          cout<<"+"<<k[i]<<"x^"<<lz-i;
        }
        }
      }
    }
    cout<<")";
  }
  cout<<endl;
  return 0;
}
