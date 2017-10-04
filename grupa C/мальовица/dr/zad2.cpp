#include<iostream>
using namespace std;
int st1,st2,a[100],b[100],st3,c[100],g,h,br,r,t;
int main()
{
  cin>>st1;
  for(int i=0;i<=st1;i++)cin>>a[i];
  r=st1;
  t=st2;
  cin>>st2;
  for(int i=0;i<=st2;i++)cin>>b[i];
  while(0<=r||0<=t)
  {
    if(r>=0){g=a[r];r--;}
    else g=0;
    if(t>=0){h=b[t];t--;}
    else h=0;
    //cout<<g<<" "<<h<<endl;
    c[br]=g-h;
    br++;
  }
  for(int i=br-1;i>=0;i--)cout<<c[i]<<" ";
  cout<<endl;
  return 0;
}
