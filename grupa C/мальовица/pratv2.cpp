#include<iostream>
using namespace std;
long long n,p[10000],mx,a,b,mem[10040];
int cutrod(int l)
{
  if(l==0)return 0;
  if(mem[l]!=-1)return mem[l];
  long long res=0;
  for(int i=1;i<=l;i++)res=max(res,p[i]+cutrod(l-i));
  mem[l]=res;
  return res;
}
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)cin>>p[i];
  for(int r=0;r<=10000;r++)mem[r]=-1;
  cout<<cutrod(n)<<endl;
  return 0;
}
