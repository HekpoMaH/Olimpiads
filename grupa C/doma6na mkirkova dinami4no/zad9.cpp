#include<iostream>
using namespace std;
int a[33],n;
int main()
{
  cin>>n;
  a[0]=1;a[1]=2;a[2]=4;
  for(int i=3;i<n;i++)a[i]=a[i-1]+a[i-2]+a[i-3];
  cout<<a[n-1]<<endl;
  return 0;
}
