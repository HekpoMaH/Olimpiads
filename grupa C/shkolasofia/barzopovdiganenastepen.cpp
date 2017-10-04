#include<iostream>
using namespace std;
int n,c;
long long povd(long long t)
{
  long long k;
  if(t==0)return 1;
  if(t==1)return c;
  if(t%2==0)k=povd(t/2)*povd(t/2);
  if(t%2==1)k=c*povd(t-1);
  return k;
}
int main()
{
  cin>>n>>c;
  cout<<povd(n)<<endl;
  return 0;
}
