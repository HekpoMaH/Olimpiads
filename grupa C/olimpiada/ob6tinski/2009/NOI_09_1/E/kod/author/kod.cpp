#include<iostream>
using namespace std;

int main()
{
  long n;
  int a,b,c,d,e,f,p,s,s1,s2;
   cin>>n;
   a=n/100000;
   b=n/10000%10;
   c=n/1000%10;
   d=n/100%10;
   e=n/10%10;
   f=n%10;
  p=a%2+b%2+c%2+d%2+e%2+f%2;
   s1=a*100+c*10+e;
  s2=e*100+c*10+a;
  if(s1>s2) s=s1-s2;
  else s=s2-s1;
  cout<<p<<s<<endl;


  return 0;     
}
