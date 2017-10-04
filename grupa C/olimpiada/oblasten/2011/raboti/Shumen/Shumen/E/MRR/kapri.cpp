#include<iostream>
using namespace std;
int main ()
{
  long long int n,a,br=0,b,c=0,l=0;
  cin>>n;
  do
  {
    cin>>a;
    br++;
    b=a*a;
    do
    {
      c*=10;
      c+=b%10;
      b/=10;
      l++;
    }
    while (b);
    b=a*a;
    for (i=0;i<=l;i++)
    {
      d=b
  }
  while (br!=n);
  return 0;
}
