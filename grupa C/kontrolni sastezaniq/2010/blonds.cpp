#include<iostream>
using namespace std;
double d[1024][1024];
long long n,m;
double rec(long long n,long long m)
{
  if(n==0)return 0;
  if(m==0)return n;
  if(d[n][m]>0.0)return d[n][m];
  d[n][m]=0;
  d[n][m]+=(double)m/(double)(n+m)*rec(n-1,m)+1.0;
  d[n][m]+=(double)n/(double)(n+m)*rec(n,m-1)+1.0;
  return d[n][m];
}
int main()
{
  cin>>n>>m;
  cout<<rec(n,m)<<endl;
  return 0;
}
