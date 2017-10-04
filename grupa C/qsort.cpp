#include<iostream>
using namespace std;
int n,a[100];
void qsort(int l,int r)
{
  int i=l,j=r,x=a[l];
  while(i<=j)
  {
    while(a[i]<x)i++;
    while(a[j]>x)j--;
    if(i<=j)
    {
      swap(a[i],a[j]);
      i++;j--;
    }
  }
  if(l<j)qsort(l,j);
  if(i<r)qsort(i,r);
}
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  qsort(1,n);
  for(int i=1;i<=n;i++)cout<<a[i]<<" ";
  cout<<endl;
  return 0;
}
