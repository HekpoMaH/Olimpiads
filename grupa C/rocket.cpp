#include<iostream>
using namespace std;
int m[100],f[100],n,l=1,d;
int bs(int l,int mk)
{
  int left=1,right=l,c,x=0;
  while(left<=right)
  {
    c=(right+left)/2;
    //cout<<"c="<<c<<endl;
    if(f[c]>mk)right=c-1;
    if(f[c]<mk)left=c+1;
    if(f[c]<=mk&&(mk<f[c+1]))x=c;
  }
  if(x==0)return c;return x;
}

int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)cin>>m[i];
  f[1]=m[1];
  for(int i=1;i<n;i++)
  {
    if(m[i+1]>=f[l])
    {
      l++;
      f[l]=m[i+1];
    }
    else
    {
      d=bs(l,m[i+1]);
      if(f[d]<=m[i+1]&&m[i+1]<f[d+1])f[d+1]=m[i+1];
    }
  }
  cout<<l<<endl;
  for(int i=1;i<=l;i++)cout<<f[i]<<" ";
  cout<<endl;
  return 0;
}
/*
10
1500
3000
1700
2000
2900
4500
1000
1200
4500
9000
*/
