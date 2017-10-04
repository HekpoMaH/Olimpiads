#include<iostream>
using namespace std;
int n,a[1024][1024],dpr[1024][1024],dpd[1024][1024],s,e,k,sol; 
int main()
{
 scanf("%d%d",&n,&k);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   {
     scanf("%d",&a[i][j]);      
   }
 for(int i=1;i<=n;i++)
 {
   dpr[i][1]=a[i][1];
   dpd[1][i]=a[1][i];
   for(int j=2;j<=k+1;j++)
   {
    dpr[i][1]+=a[i][j];       
    dpd[1][i]+=a[j][i];
   }
 } 

 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   {
    if(i!=1) dpd[i][j]+=dpd[i-1][j]-a[i-1][j];       
     if(i!=1 && i+k<=1000) dpd[i][j]+=a[i+k][j];
    if(j!=1) dpr[i][j]+=dpr[i][j-1]-a[i][j-1];
     if(j!=1 && j+k<=1000) dpr[i][j]+=a[i][j+k];
    if(dpr[i][j]+dpd[i][j]-a[i][j]>sol) {sol=dpr[i][j]+dpd[i][j]-a[i][j];s=i;e=j;}
   }/*
 for(int i=1;i<=n;i++)
 { for(int j=1;j<=n;j++)
   {
    printf("%d ",dpr[i][j]);
   } 
  printf("\n");
}*/
 printf("%d %d\n",s,e);
 return 0;    
}
