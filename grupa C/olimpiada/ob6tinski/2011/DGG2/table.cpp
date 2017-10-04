#include<iostream>
using namespace std;
int a;
long long n,m,k,sum,br;
int main()
{
  cin>>n>>m>>k;
  for(long i=0;i<n;i++)
  {
    for(long j=0;j<m;j++)
    {
      cin>>a;br++;
      if(br%k==0)sum+=a;
    }
  }
  cout<<sum<<endl;
  return 0;
}
