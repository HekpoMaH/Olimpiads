#include<iostream>
using namespace std;
int k,a[15],fact[15]={0,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600},nm;
int main()
{
  cin>>k;
  for(int i=1;i<=k;i++)
  {
    cin>>a[i];
    nm+=fact[k-i]*(a[i]-1);
  }
  cout<<nm<<endl;
  return 0;
}
