#include<iostream>
#include<algorithm>
using namespace std;
struct rg
{
  int maxi;
  int nr;
  int ur,ul;
};
long n,a[1000];
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  int left=0,right=n-1,maxel,l,ur1,ul1;
  rg mx[15];
  mx[0].ur=0;mx[0].ul=1;
  mx[1].ur=1;mx[0].ul=0;
  mx[2].ur=0;mx[0].ul=2;
  mx[3].ur=2;mx[0].ul=0;
  mx[4].ur=1;mx[0].ul=1;
  mx[5].ur=0;mx[0].ul=3;
  mx[6].ur=3;mx[0].ul=0;
  mx[7].ur=1;mx[0].ul=2;
  mx[8].ur=2;mx[0].ul=1;
  long long sum=0;
  while(left<=right)
  {
    mx[2].maxi=a[left]*a[left+1];mx[2].nr=2;
    mx[3].maxi=a[right]*a[right-1];mx[3].nr=2;
    mx[4].maxi=a[right]*a[left];mx[4].nr=2;
    mx[5].maxi=a[left]*a[left+1]*a[left+2];mx[5].nr=3;
    mx[6].maxi=a[right]*a[right-1]*a[right-2];mx[6].nr=3;
    mx[7].maxi=a[left]*a[left+1]*a[right];mx[7].nr=3;
    mx[8].maxi=a[left]*a[right-1]*a[right-2];mx[8].nr=3;
    mx[0].maxi=a[left];mx[0].nr=0;
    mx[1].maxi=a[right];mx[1].nr=0;
    ur1=0;ul1=0;
    for(int i=0;i<8;i++)
    {
      l=1;
      for(int j=0;j<8;j++)
      {
        if(mx[i].maxi<mx[j].maxi)
        {
          l=0;
          break;
        }
      }
      if(l==1)
      {
        if(mx[i].nr<=right-left)
        {
          maxel=mx[i].maxi;
          ur1=mx[i].ur;ul1=mx[i].ul;
        }
      }
    }
    sum+=maxel;
    right+=ur1;left+=ul1;
  }
  cout<<sum<<endl;
  return 0;
}
