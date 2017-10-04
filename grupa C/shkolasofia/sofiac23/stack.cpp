#include<iostream>
using namespace std;
int f[92],n;
int main()
{
  cin>>n;
  f[1]=1;
  f[2]=1;
  for(int i=3;i<=n;i++)f[i]=f[i-1]+f[i-2];
  cout<<f[n-1]+f[n]<<endl;
  return 0;
}
