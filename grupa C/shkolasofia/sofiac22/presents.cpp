#include<iostream>
using namespace std;
long long n,f[10004];
long long rec(long long s)
{
  int x=0;
  if(s==1)return 0;
  if(s==2)return 1;
  if(f[s]!=0)return f[s];
  x=((s-1)*rec(s-1)+(s-1)*rec(s-2))%1000000000;
  f[s]=x;
  return f[s];
}
int main()
{
  cin>>n;
  f[1]=0;
  f[2]=1;
  cout<<rec(n)<<endl;
  return 0;
}
