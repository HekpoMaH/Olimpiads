#include<iostream>
using namespace std;
int cifri[10];
long long a,b,a1,b1,l,br;
int main()
{
  cin>>a>>b;
  for(long long i=a;i<=b;i++)
  {
    for(int j=0;j<10;j++)cifri[j]=0;
    a1=i;
    while(a1>0)
    {
      b1=a1%10;
      cifri[b1]++;
      a1/=10;
    }
    l=0;
    for(int j=0;j<10;j++)if(cifri[j]>=2){l=1;break;}
    if(l==0)br++;
  }
  cout<<br<<endl;
  return 0;
}
