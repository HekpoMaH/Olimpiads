#include<iostream>
using namespace std;
int l,n,ras,sp[13],snast,vnast,mx=-999,ns,tnast,vs;
int main()
{
  cin>>l>>n;
  for(int i=0;i<n;i++)cin>>sp[i];
  sp[n]=sp[0];
  ras=l/n;
  for(int i=0;i<n;i++)
  {
    snast=sp[i]-sp[i+1];
    if(snast>mx){mx=snast;ns=i+1;vs=sp[i];}
  }
  if(mx<=0)cout<<"NO WINNER"<<endl;
  else
  {
    tnast=ras/mx;
    snast=tnast*vs;
    cout<<ns<<" "<<tnast<<" "<<snast<<endl;
  }
  return 0;
}
