#include<iostream>
using namespace std;
int n,m[104],f[104],l=1;
int bs(int l,int mk)
{
  int left=0,right=l,c,x=0;
  while(left<=right)
  {
    c=(right+left)/2;
    if(f[c]>mk)right=c-1;
    if(f[c]<mk)left=c+1;
    if(f[c]<mk&&mk<f[c+1])x=c;
  }
  if(x==0)return c;
  return x;
}
int d;
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)cin>>m[i];
  f[1]=m[1];
  for(int k=1;k<n;k++)
  {
    if(m[k+1]>=f[l])
    {
      l++;
      f[l]=m[k+1];
    }
    else
    {
      d=bs(l,m[k+1]);
      if(f[d]<m[k+1]&&m[k+1]<f[d+1])f[d+1]=m[k+1];
    }
  }
  cout<<l<<endl;
  return 0;
}

