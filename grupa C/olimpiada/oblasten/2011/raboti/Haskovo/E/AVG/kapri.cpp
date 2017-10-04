#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
  long long int n,k,copy,copy2,copy3,br=0,kap=0,rik=0,z=0,x,ura=0;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>k;
    br=0;
    copy=k;
    while(copy!=0)
    {
      copy=copy/10;
      br++;
    }
    copy2=k*k;
    copy=copy2;
    while(z<br)
    {
      z++;
      kap=kap*10+copy%10;
      copy=copy/10;

    }
    rik=copy;
    z=0;
    copy=kap;
    kap=0;
    while(z<br)
    {
      z++;

      copy=kap*10+copy%10;
      kap=copy;
      copy=copy/10;

    }
    z=0;
    x=rik+kap;
    if(x==k)ura++;
    x=0;
  }
  cout<<ura<<endl;
  return 0;
}
