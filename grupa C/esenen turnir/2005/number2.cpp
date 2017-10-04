#include<iostream>
using namespace std;
int n,d1,d2,d3,a[22],m;
bool ok(int a,int b)
{
  if(a==0)return false;
  int x=10*a+b;
  if(x%d1==0)return true;
  if(x%d2==0)return true;
  if(x%d3==0)return true;
  return false;
}
void gen(int k)
{
  for(int i=0;i<10;i++)
  {
    if(ok(a[k-1],i))
    {
      a[k]=i;
      if(k<n)gen(k+1);
      else m++;
    }
  }
}
int main()
{
  cin>>n>>d1>>d2>>d3;
  for(int i=1;i<10;i++)
  {
    a[1]=i;
    gen(2);
  }
  cout<<m<<endl;
  return 0;
}
