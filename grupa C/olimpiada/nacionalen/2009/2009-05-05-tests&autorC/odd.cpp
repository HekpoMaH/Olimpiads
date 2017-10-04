/*
TASK: odd
LANG: C++
*/
#include<cstdio>

int main()
{
  long long int n,a,b;
  scanf("%lld",&n);
  scanf("%lld",&a);
  for(int i=2;i<=n;i++)
  {
    scanf("%lld",&b);
    a ^= b;
  }
  printf("%lld\n",a);
}
