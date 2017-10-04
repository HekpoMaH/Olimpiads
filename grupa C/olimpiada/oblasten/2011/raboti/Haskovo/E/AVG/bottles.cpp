#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
  long long int n,m,kol=0,br=0;
  cin>>m>>n;
  while(kol<m*n)
  {
    kol=kol+n+m;
    br++;
  }
  cout<<br*2<<endl;
  return 0;
}
