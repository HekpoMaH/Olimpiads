#include<iostream>
using namespace std;
int main ()
{
  long long int n,m,b=1;
  cin>>m>>n;
  do
  {
    if (((b*m+b*n)%m==0)&&((b*m+b*n)%n==0))
    {
      cout<<b*2<<endl;
      break;
    }
    b++;
  }
  while (1);
  return 0;
}
