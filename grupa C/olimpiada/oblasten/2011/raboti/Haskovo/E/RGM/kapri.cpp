#include <iostream>
using namespace std;
int main ()
{
long long int k,copy,cop,sum;
int n,l=0,c,d=1,ch=0,br=0;
cin>>n;
for (int i=1; i<=n; i++)
{
  cin>>k;
  copy=k;
  cop=k;
  while (copy!=0)
  {
    l++;
    copy=copy/10;
  }

  k=k*k;

    while (l!=0)
    {
    l--;
    c=k%10;
    ch=ch+(c*d);
    d=d*10;
    k=k/10;
    }

  sum=ch+k;
  if (sum==cop) {br++;}
  d=1;
  ch=0;
}
cout<<br<<endl;
  return 0;
}