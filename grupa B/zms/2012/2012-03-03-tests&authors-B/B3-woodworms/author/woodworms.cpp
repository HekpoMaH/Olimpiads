#include <iostream>
#include <cstdio>
using namespace std;
const int nmax=300;
double a[nmax],b[nmax],c[nmax];
int d[nmax],n ;

void init()
{cin>>n;
for(int i=1;i<=n;i++)
cin>>a[i]>>b[i];

 for(int i=1;i<=n;i++)
 {c[i]=a[i]/b[i];
    d[i]=i;}
}

 void sortirane()
 {
     int i,j,k;
     for(i=1;i<=n;i++)
     {
         k=i;
         for(j=i+1;j<=n;j++)
         if (c[j]>c[k]) k=j;
    c[0]=c[k];
    c[k]=c[i];
    c[i]=c[0];
    d[0]=d[k];
    d[k]=d[i];
    d[i]=d[0];
     }
 }


void time()
{
    int uk1, uk2;
    double t1,t2,t3,t4;
    double t;
    uk1=1;
    uk2=n;
  t1=0;t2=0;
  while (uk1!=uk2)
  {
   t3=t1+a[d[uk1]];
    t4=t2+b[d[uk2]];
    if (t3<t4)
    {uk1++; t1=t3;}
    else
    {uk2--; t2=t4;}
  }
  if (t1>t2)
  {
     t=(t1-t2)/b[d[uk1]];
     t2=t1;
  }
  else
  {
    t=(t2-t1)/a[d[uk1]];
    t1=t2;
  }
  t1=t1+(1-t)/(1/a[d[uk1]]+1/b[d[uk1]]);
  printf("%0.3f\n",t1);
}

int main()
{
    init();
    sortirane();
    time();
}
