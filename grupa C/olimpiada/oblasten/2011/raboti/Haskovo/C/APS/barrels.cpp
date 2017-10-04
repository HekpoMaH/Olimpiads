#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iomanip>
#include<cstring>
#include<vector>
using namespace std;
int barVm[105];
int main()
{
  long long int s,n;
  cin>>s>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>barVm[i];
  }
  sort(barVm+1,barVm+1+n);
  if(n==1)
  {
    cout<<s<<endl;
    return 0;
  }
  long long int min=s+5;
  long long int now=0;
  long long int xals=s+5;
  int bam;
  for(int i=1;i<=n;i++)
  {
    if(s/barVm[i]<xals)
    {
      xals=s/barVm[i];
      bam=i-1;
    }
  }
  long long int fuji=0;
  int l=0;
  long long int snow;
  for(int i=xals;i>=1;i++)
  {
    snow=s-xals*barVm[bam];
    fuji=0;
    now=i;
    for(int j=bam;j>=1;j--)
    {
      if((s-i*barVm[bam])%j==0)
      {
        now+=fuji;
        fuji=(s-xals)/j;
        break;
      }
    }
    if(now<min)
    {
      min=now;
    }
    else l=1;
    now=i;
    for(int j=bam;j>=1;j--)
    {
      if(snow>barVm[j])
      {
        now+=snow/barVm[j];
        snow%=barVm[j];
      }
    }
    if(now<min)
    {
      min=now;
      l=0;
    }
    if(l==1)
    {
      cout<<min<<endl;
      break;
    }
  }
  return 0;
}
