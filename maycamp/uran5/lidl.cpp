#include<iostream>
using namespace std;
long n,k,m;
long kasi[100][1000000],sumk[101],brp,mn,ts;
int main()
{
  cin>>n>>k>>m;
  for(long long i=0;i<n;i++)
  {
    brp=(i+1)%k;
    if(brp==0)brp=k;
    mn=999999999;
    for(int j=0;j<m;j++)
    {
      if(sumk[j]<mn){mn=sumk[j];ts=j;}
    }
    kasi[ts][brp-1]++;
    sumk[ts]+=brp;
  }
  for(int i=0;i<m;i++)
  {
    cout<<kasi[i][0];
    for(int j=1;j<k;j++)cout<<" "<<kasi[i][j];
    cout<<endl;
  }
  return 0;
}
