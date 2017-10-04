#include<iostream>
using namespace std;
int a;
long long n,m,k,sum;
int main()
{
  cin>>n>>m>>k;
  for(long i=0;i<n;i++)
  {
    for(long j=0;j<m;j++)
    {
      cin>>a;
      if(((i+1)*(j+1))%k==0)sum+=a;
    }
  }
  cout<<sum<<endl;
  return 0;
}
