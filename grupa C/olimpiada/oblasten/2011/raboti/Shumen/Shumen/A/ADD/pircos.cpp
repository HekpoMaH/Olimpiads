#include<cstdio>
using namespace std;
int n;
long long t,m;
bool a[100010],l;
int main()
{
 int i;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  scanf("%lld",&t);
  if(t<=100010)
  {
   if(a[t])a[t]=0;
   else a[t]=1;
   if(t>m)m=t;
  }
 }
 for(i=1;i<=m;i++)
  if(a[i])
   if(l)
   {
	printf("%d\n",i);
	break;
   }
   else
   {
    l=1;
    printf("%d ",i);
   }
 return 0;
}
