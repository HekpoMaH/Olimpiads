#include<iostream>
using namespace std;
int n,m[10],xr;
int main()
{
  cin>>n;int a;
  for(int i=0;i<n;i++)cin>>m[i];
  for(int i=0;i<n;i++)xr^=m[i];
  if(xr==0)cout<<"lose"<<endl;
  if(xr>0)for(int i=0;i<n;i++)
  {
    a=0;
    a=xr^m[i];
    if(a<=m[i])
    {
      m[i]=a;
      break;
    }
  }
  if(xr>0)for(int i=0;i<n;i++)cout<<m[i]<<" ";
  if(xr>0)cout<<endl;
  return 0;
}
