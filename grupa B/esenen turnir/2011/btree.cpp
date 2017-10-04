#include<iostream>
using namespace std;
long long p,n1,n2,n3,n4,br1,br2,br3;
int solve(long long n)
{
  int a[4]={0,0,0,0};
  long long r;
  while(n!=0)
  {
    r=n%p;
    n/=p;
    if(r<3)a[r]++;
    else a[3]++;
  }
  if(a[3]>0)return 0;
  if(a[1]==1&&a[2]>0)return 1;
  if(a[1]==2&&a[2]==0)return 1;
  return 0;
}
int main()
{
    cin>>p>>n1>>n2>>n3>>n4;
    cout<<solve(n1)<<" "<<solve(n2)<<" "<<solve(n3)<<" "<<solve(n4)<<endl;
    return 0;
}
