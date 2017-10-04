#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long s,n,i,j,min1,f[1000001];
int main()
{
  scanf("%lld%lld",&s,&n);
  for(i=1; i<=n; i++) f[i]=1;
  for(i=n+1; i<=s; i++)
  {
    min1=f[i-1]+1;
    for(j=2; j<=n; j++)
    {
      min1=min(min1,f[i-j]+1);
      if(i%j==0) min1=min(min1,f[i/j]+1);
    }
    f[i]=min1;
  }
  printf("%lld\n",f[s]);
  return 0;
}
