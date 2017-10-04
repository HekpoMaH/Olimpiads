#include<iostream>
using namespace std;
int a,k,ts;
int main()
{
  cin>>a>>k;
  for(int i=0;i<k;i++)
  {
    ts+=a;
    ts/=2;
  }
  cout<<ts<<endl;
  return 0;
}
