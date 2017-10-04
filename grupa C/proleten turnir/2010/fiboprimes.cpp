#include<iostream>
#define MAX 100000000
using namespace std;
unsigned long long fib[228],n,br,d[MAX];
int isprime(long long n)
{
  if(n<2)return 0;
  for(long long i=2;i*i<=n;i++)
  {
    //cout<<i*i<<endl;
    if(n%i==0)return 0;
  }
  return 1;
}
int eval(long long n)
{
  if(n<2)return 0;//cout<<"d="<<d[n]<<endl;
  if(n<MAX&&d[n]!=0)return d[n];//cout<<"n="<<n<<endl;
  int best=0,add=0;
  if(isprime(n)){best=1;add=1;}
  for(int i=0;fib[i]<=n;i++)best=max(best,add+eval(n/fib[i]));
  if(n<MAX){d[n]=best;}
  //cout<<"best="<<best<<endl;
  return best;
}
int main()
{
  cin>>n;
  fib[0]=2;fib[1]=3;br=2;
  while(fib[br-1]<=n)
  {
    fib[br++]=fib[br-1]+fib[br-2];
  }
  //cout<<fib[br-1]<<endl;
  //for(long long i=0;i<=n;i++)d[i]=-1;
  //for(int i=0;i<br;i++)cout<<fib[i]<<endl;
  //memset(d,-1, sizeof(d));
  //cout<<"n="<<n<<endl;
  cout<<eval(n)<<endl;
  return 0;
}
