#include<iostream>
using namespace std;
int xr,n,a;
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>a;
    xr^=a;
  }
  cout<<xr<<endl;
  return 0;
}
