#include<fstream.h>
#include<string.h>
ifstream in("freq.inp");
ofstream out("freq.out");

void main()
{int br=0,n,k=0,j,s,h;
char l,a[255],b[255],c[255],d[255],e[255];
in>>n;
   if(n==1)
    { in>>a;
   s=strlen (a);
   for(int i=0;i<s-1;i++)
    for(int j=i;j<s;j++)
     if(a[j]>a[j-1])
     {h=a[j];a[j]=a[j-1];
     a[j-1]=h;}

    for( i=1;i<s;i++)
      {if(a[i-1]==a[i])
      br++;
      else br=3;
      if(br>k)k=br;
       l=a[i];}
       }
       out<<l<<' '<<k<<endl;

     }







