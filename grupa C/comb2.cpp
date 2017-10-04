#include<iostream>
using namespace std;
int n,k,a[100],m[100];
int comb(int s,int k,int after)
{
  if(s>=k)
  {
    for(int i=0;i<s;i++)cout<<m[i]<<" ";
    cout<<endl;
  }
  else
  {
    for(int i=after+1;i<n;i++)
    {
      m[s]=a[i];
      comb(s+1,k,i);
    }
  }
}
int main()
{
  cin>>n>>k;
  for(int i=0;i<n;i++)cin>>a[i];
  comb(0,k,-1);
}
