#include<iostream>
#include<string>
using namespace std;
int h1,m1,h2,m2,l;
string a,b;
int main()
{
  cin>>a;
  cin>>b;
  l=0;
  for(int i=0;i<a.size();i++)
  {
    if(l==0&&a[i]!=':')h1=h1*10+a[i]-'0';
    if(l==1)m1=m1*10+a[i]-'0';
    if(a[i]==':')l=1;
  }
  //cout<<h1<<" "<<m1<<endl;
  l=0;
  for(int i=0;i<b.size();i++)
  {
    if(l==0&&b[i]!=':')h2=h2*10+b[i]-'0';
    if(l==1)m2=m2*10+b[i]-'0';
    if(b[i]==':')l=1;
  }//cout<<m2<<" "<<h2<<endl;
  m1+=h1*60;
  m2+=h2*60;
  if(m1>m2)m2+=24*60;
  int m,h;
  m=abs(m1-m2);
  h=m/60;
  m%=60;if(h<10)cout<<0;
  cout<<h<<":";//<<m<<endl;
  if(m<10)cout<<"0";
  cout<<m<<endl;
  return 0;
}
