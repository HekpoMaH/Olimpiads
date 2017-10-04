//dfrac.c
#include<stdio.h>
#include<stdlib.h>

int main()
{
 double rslt;
 int i,j=0,m,a,b;
 long k,p;
 scanf("%d %d",&a,&b);
 scanf("%d %d",&k,&p);
 rslt=a;
 rslt/=b;
 for(i=0;i<k-1;i++)
    rslt*=10;
 m=(int)rslt;
 while(m>0)
 {
  m--;
  j++;
 }
 rslt-=j;
 j=1;
 for(i=k;i<p+k;i++)
     rslt*=10;
 printf("%0.f",rslt);
 p-=p+k;
 k-=p+k;
 while(p>0)
 {
          rslt=a;
          rslt/=b;
          for(i=0;i<16;i++)
              rslt*=10;
          printf("%0.f",rslt);
          p-=p;
          k-=p;
          if(p<=16||k<=16)
          break;
 }
 //system("PAUSE");
 return 0;
}
