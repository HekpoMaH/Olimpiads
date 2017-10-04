#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long br,i,n,min1,a[10001],b[10001],c[10001];
char dp[8001][8001];
void copyarray()
{
  for(long long i=1; i<=br-1; i++)
  {
    c[i]=b[i];
  }
  return ;
}
bool palind(long long k, long long p)
{
  if(dp[k][p]>0) return dp[k][p]-1;
  for(long long i=k; i<=(k+p)/2; i++)
  {
    if(a[i]!=a[p-(i-k)]) return false;
  }
  return true;
}
void rec(long long k)
{
  if(k==n+1) {if(br-1<min1) {min1=br-1; copyarray();} return ;}
  if(br>min1) return;
  for(long long i=k; i<=n; i++)
  {
    if(palind(k,i)) {br++; b[br]=i; rec(i+1); br--;}
  }
  return ;
}
int main()
{
  scanf("%lld",&n);
  min1=10001;
  for(i=1; i<=n; i++)
  {
    scanf("%lld",&a[i]);
  }
  rec(1);
  printf("%lld\n",min1+1);
  if(min1>0)
  {
    for(i=1; i<=min1-1; i++)
    {
      printf("%lld ",c[i]);
    }
    printf("%lld\n",c[min1]);
  }
  return 0;
}
