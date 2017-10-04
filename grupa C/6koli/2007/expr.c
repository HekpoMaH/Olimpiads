#include<iostream>
#include<string>
using namespace std;
string n,m,c;
int k,d;
int main()
{
  cin>>n;
  cin>>d;
  cin>>m;
  cin>>k;
  int p,t,o;
  int nl=n.size();
  int ml=m.size();
  p=0;t=0;
  for(int i=nl-1;i>=0;i--)
  {
    o=n[i]-'0';
    p=o*d+t;
    n[i]=p+'0';
  }
  p=0;t=0;
  for(int i=ml-1;i>=0;i--)
  {
    o=m[i]-'0';
    p=o*k+t;
    m[i]=p+'0';
  }
  int j=0,i=0,f=0,e=0,r=0;
  int indx=0;
  if(nl>ml) f=nl-1;

else f=ml-1;

  i=nl-1;j=ml-1;
  p=0;t=0;
  //cout<<f<<" "<<i<<" "<<j<<endl;
  while(f>=0)
  {

    if(i<0)e=0;else e=n[i]-'0';
    if(j<0)r=0;else r=m[j]-'0';
    t+=e+r;
    if(t>9) {c[indx]=t%10+'0';t/=10;}
    else  {c[indx]=t+'0';t=0;}
    indx++;i--;j--;f--;
  }//cout<<c;
  if(t){c[f]=t+'0';cout<<c[f];}
for(i=indx-1;i>=0;i--)cout<<c[i];
cout<<endl;
  //cout<<m<<endl;
  return 0;
}
