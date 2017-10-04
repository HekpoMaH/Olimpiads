#include<iostream>
using namespace std;
int main()
{ int a,i,s=0;
  cin>>a;
  for(i=1;i<=a;i++)
  s=s+i;
  int d=s/7;
  int p=s%7;
  if (d%2==0) {d--; p=p+7;}
  cout<<d<<" "<<p<<endl;
}
  
