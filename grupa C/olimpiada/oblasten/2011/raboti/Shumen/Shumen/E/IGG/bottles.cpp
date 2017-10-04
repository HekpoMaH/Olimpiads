#include<iostream>
using namespace std;
int main()
{
  long long int m,n,i=1,x,d;
  cin>>m>>n;
  do
  {
    x=m*i+n*i;
    if(x%m==0&&x%n==0)d=i;
    else
    i++;
  }
  while(d!=i);
  cout<<i*2<<endl;
return 0;
}
