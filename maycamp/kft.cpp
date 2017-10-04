#include<iostream>
using namespace std;
long long k,nk;
int main()
{
  cin>>k;
  while(k%10!=0&&k<10000)
  {
    nk=k%10;
    k+=nk;
  }
  cout<<k<<endl;
  return 0;
}
