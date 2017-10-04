#include<iostream>
using namespace std;
int p,br;
int main()
{
  cin>>p;
  for(int i=1;3*i<=p;i++)for(int j=i;i+2*j<=p;j++)if(i+j>p-i-j)br++;
  cout<<br<<endl;
  return 0;
}
