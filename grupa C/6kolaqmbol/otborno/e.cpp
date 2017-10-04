#include<cstdio>
using namespace std;
int t,n,k,a[1004];
int hb(int a)
{
  int k=0;
  for(int i=0;(1<<i)<=a;++i)
  {
    if(1<<i&a)k=i;
  }
  return k;
}
void solve()
{
  scanf("%d",&n);
  scanf("%d",&k);
  for(int i=0;i<n;i++)scanf("%d",&a[i]);
  int xr=0;
  for(int i=0;i<n;i++)xr^=a[i];
  int st1=hb(k);
  int st2=hb(xr);
  if(xr==0)
  {
    printf("0\n");
  }
  else
  {
    if(st1<st2)printf("-1\n");
    else if(xr>k)printf("2\n");
    else printf("1\n");
  }
}
int main()
{
  //ios::sync_with_stdio(false);
  scanf("%d",&t);
  for(int i=0;i<t;i++)solve();
  return 0;
}
