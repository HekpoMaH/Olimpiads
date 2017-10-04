#include <iostream>
using namespace std;
int main()
{
  long long int h,a,c,n,m,i,b,br;
  cin>>m>>n;
  if((c/m)&&(c/n))c=1;
  b=((a*m)+(a*n));
  do
  {
  if(b/m==c&&b/n==c)a*=2;
  }
  while(a==a*2);
  cout<<a<<endl;







return 0;
}