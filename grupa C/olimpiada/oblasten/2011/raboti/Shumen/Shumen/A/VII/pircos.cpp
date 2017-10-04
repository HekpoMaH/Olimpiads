#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

long long a[129];
struct hlp
{
   long long aa,bb;
};

bool cmp(hlp as, hlp bs)
{
   if(as.bb==bs.bb)
   return as.aa>bs.aa;
   return as.bb>as.aa;
}

hlp ppp[8];

long long n,p,i,j,pr;
long long k;

int main()
{
   scanf("%lld",&n);
   for(i=1;i<=n;i++)
   {
      scanf("%lld",&k);
      for(j=1;j<=64;j++)
      {
         if((k/(1<<j))%2)
         {
            a[j]=a[j]^k;
         }
         else
         {
            a[j+64]^=k;
         }
      }
   }
   int ff=2;
   ppp[1].bb=0;
   ppp[2].bb=0;
   ppp[3].bb=0;
   ppp[4].bb=0;
   int krk=0;
   for(i=1;i<=128;i++)
   {
      krk=0;
      for(j=1;j<=4;j++)
      {
         if(a[i]==ppp[j].aa)
         {
            ppp[j].bb++;
            krk=1;
         }
      }
         if(krk==0)
         {
            ppp[ff].aa=a[i];
            ppp[ff].bb=1;
            ff++;
         }
   }
   sort(ppp+1,ppp+5,cmp);
   printf("%lld ",ppp[4].aa);
   printf("%lld\n",ppp[3].aa);

}
