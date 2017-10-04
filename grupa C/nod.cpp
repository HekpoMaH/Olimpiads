#include<iostream>
using namespace std;
int nod(int a,int b)
{
  int r;
  while(b!=0)
  {
    r=a%b;
    a=b;
    b=r;
  }
  return a;
}
int main()
{
  int a,b;
  cin>>a>>b;
  cout<<nod(a,b)<<endl;
  return 0;
}
