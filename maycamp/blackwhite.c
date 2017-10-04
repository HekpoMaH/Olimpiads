#include<iostream>
using namespace std;
int main()
{
  int a,a1,b,b1,c,c1;
  cin>>a>>a1;
  cin>>b>>b1;
  cin>>c>>c1;
  int sum=0;
  if(a1==0)sum+=a;
  if(b1==0)sum+=b;
  if(c1==0)sum+=c;
  cout<<sum<<endl;
  return 0;
}
