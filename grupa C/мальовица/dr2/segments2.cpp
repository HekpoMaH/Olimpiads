#include<iostream>
using namespace std;
long long a[200000000];
long long r,t,c,n,mn=100000000,mx=-999999999,mxc=-9999999,sum;
int main()
{
  cin>>n;
  for(long long i=0;i<n;i++)
  {
    cin>>r>>t>>c;
    if(r+100000000<mn)mn=r+100000000;
    if(t+100000000>mx)mx=t+100000000;
    for(long long j=r+100000000;j<t+100000000;j++)
    {
      a[j]+=c;
    }
  }
  //for(int i=mn;i<=mx;i++)cout<<a[i]<<" ";
  //cout<<endl;
  //cout<<mn<<" "<<mx<<endl;
  for(long long i=mn;i<=mx;i++)
  {
    sum=0;
    for(long long j=i;j<=mx;j++)
    {
      sum+=a[j];cout<<mxc<<" "<<j-100000000<<endl;
      if(sum>mxc){mxc=sum;}
    }
  }
  cout<<mxc<<endl;
  return 0;
}
