#include<iostream>
using namespace std;
unsigned long long mem[209];//1 1 2 3 5 8
int n;
unsigned long long fib(long long a)
{
  if(mem[a]!=0)return mem[a];
  mem[a]=fib(a-1)+fib(a-2);
  return mem[a];
}
int main()
{
  mem[0]=1;
  mem[1]=1;
  cin>>n;
  cout<<fib(n)<<endl;
  return 0;
}
