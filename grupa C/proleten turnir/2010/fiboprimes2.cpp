#include<iostream>
# define MAX 100000000
using namespace std;
//long long MAX=100000000;
long long fib[228],d[MAX],n;
bool ip(long long k)
{
  bool f=false;
  for(int i=2;i*i<=n;i++)
  {
    if(n%i==0){f=true;break;}
  }
  if(f==false)return true;
  return false;
}
long long eval(long long n)
{
  if(n<2)return 0;
  if(n<MAX&&d[n]>0)return d[n];
  long long best=0,add=0;
  if(ip(n)==true){best=1;add=1;}
  for(int i=0;fib[i]<=n;i++)best=max(best,add+eval(n/fib[i]));
  if(n<MAX)d[n]=best;
  return best;
}
int main()
{
  cin>>n;
  int br=2;
  fib[0]=2;fib[1]=3;
  while(fib[br-1]<=n)fib[br++]=fib[br-1]+fib[br-2];
  cout<<eval(n)<<endl;
}
