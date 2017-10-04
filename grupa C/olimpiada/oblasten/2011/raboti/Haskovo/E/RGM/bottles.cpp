#include <iostream>
using namespace std;
int main ()
{
int m,n,s,sum=0,br;
cin>>m>>n;
s=m+n;
while (1)
{
  sum=sum+s;
  if(sum%m==0 && sum%n==0) {break;}
}
br=(sum/s)*2;
cout<<br<<endl;
  return 0;
}