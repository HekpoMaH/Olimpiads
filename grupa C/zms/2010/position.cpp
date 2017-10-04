#include<iostream>
using namespace std;
long long n=1,p,r=10,cd=1,k;
int main()
{
  cin>>k;
  do
  {
    while(n*n<r&&p<k)
    {
      n++;
      p+=cd;
    }//cout<<r<<endl;
    r*=10;
    cd++;
  }while(p<k);
  long long m;
  m=(n-1)*(n-1);
  while(p-k>0)
  {
    m/=10;
    p--;
  }
  cout<<m%10<<endl;
  return 0;
}
