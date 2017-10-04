#include<iostream>
#include<algorithm>
using namespace std;
int a[270010];
int binsearch(int levo,int desno,int sum)
{
  int sreda;
  while(levo<=desno)
  {
    sreda=(levo+desno)/2;
    if(a[sreda]<sum)
    {
      if(a[sreda+1]>=sum)return sreda;
      levo=sreda+1;
    }
    else desno=sreda-1;
  }
}
int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    a[n]=10000000;
    int k,s,d,sum,mx=1,x;
    for(int i=0;i<n-2;i++)
    {
      sum=a[i]+a[i+1];s=n-1;
      x=binsearch(i,s,sum)-i+1;
      if(x>2&&mx<x)mx=x;
    }
    cout<<mx<<endl;
    return 0;
}
