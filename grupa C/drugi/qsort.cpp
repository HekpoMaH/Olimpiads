#include<iostream>
using namespace std;
int n,a[106];
void quicksort(int l,int r)
{
  int i=l,j=r,x;
  x=a[l];
  while(i<=j)
  {
    while(a[i]<x){i++;}
    while(a[j]>x)j--;
    if(i<=j)
    {
      swap(a[i],a[j]);
      j--;i++;
    }
  }
  if(l<j) quicksort(l,j);
  if(i<r) quicksort(i,r);
}
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  quicksort(1,n);
  for(int i=1;i<=n;i++)cout<<a[i]<<" ";
  cout<<endl;
  return 0;
}
