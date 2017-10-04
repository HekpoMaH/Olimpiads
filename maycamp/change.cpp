#include<iostream>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int a[8],b[8];
int main()
{
  long n,n1,l=0,h;
  int br=-1,z,o=-1;
  cin>>n;n1=n;
  while(n1>0)
  {
    br++;
    a[br]=n1%10;
    n1/=10;
  }
  for(int i=0;i<br;i++)
  {
    if(a[i]>a[i+1]){l=1;h=a[i];a[i]=a[i+1];a[i+1]=h;z=i;break;}
  }if(l==0)cout<<0<<endl;
  else {for(int i=z;i>=0;i--){o++;b[o]=a[i];} sort(b,b+o+1); for(int i=br;i>z;i--)cout<<a[i];for(int i=0;i<=o;i++)cout<<b[i];
  cout<<endl;}
  return 0;
}
//132