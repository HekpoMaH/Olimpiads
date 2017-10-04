#include<iostream>
using namespace std;
int main()
{
  long n,maxk;
  cin>>n>>maxk;
  int a[n],k[maxk],br=-1;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<maxk;i++)
  {
    sort(a,a+n);
    br++;k[br]=a[n-1];
    a[n-1]=0;
  }
  sort(k,k+maxk);
  for(int i=0;i<maxk;i++)cout<<k[i]<<endl;
  return 0;
}
