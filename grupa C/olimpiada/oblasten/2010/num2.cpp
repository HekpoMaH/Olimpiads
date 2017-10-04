#include<iostream>
using namespace std;
int a,b,br;
bool pr(int x)
{
  int num[11];
  for(int i=0;i<=11;i++)num[i]=0;
  while(x!=0)
  {
    num[x%10]++;
    if(num[x%10]==2)return false;
    x/=10;
  }
  return true;
}
int main()
{
  cin>>a>>b;
  for(int i=a;i<=b;i++)if(pr(i)==true)br++;
  cout<<br<<endl;
  return 0;
}
