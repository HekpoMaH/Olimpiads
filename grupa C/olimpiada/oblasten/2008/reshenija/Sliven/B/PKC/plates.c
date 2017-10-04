//plates.c
#include<stdio.h>
#include<stdlib.h>
int main()
{
 int i,j,k,l,m,n,count=0,prov=0;
 scanf("%d %d",&m,&n);
 int plate[m][n];
 int sum[m];
 for(i=0;i<m;i++)
     for(j=0;j<n;j++)
         {scanf("%d",&plate[i][j]);
          sum[i]=0;}
 for(k=0;k<m;k++)
     for(i=0;i<n;i++)
         for(j=i+1;j>0;j--)
             if(plate[k][j]<plate[k][j-1])
             {  l=plate[k][j-1];
                plate[k][j-1]=plate[k][j];
                plate[k][j]=l;
             }
 for(i=0;i<m;i++)
     for(j=0;j<n;j++)
         sum[i]+=plate[i][j];
 for(i=0;i<m;i++)
     for(j=i+1;j>0;j--)
             if(plate[j][0]<plate[j-1][0])
             {  l=plate[j-1][0];
                plate[j-1][0]=plate[j][0];
                plate[j][0]=l;
                l=plate[j-1][1];
                plate[j-1][1]=plate[j][1];
                plate[j][1]=l;
             }
 for(i=0;i<m-1;i++)
 {
  if(sum[i]==sum[i+1])
  {
   for(j=0;j<n;j++)
       if(plate[i][j]==plate[i+1][j])
          prov++;
   if(prov==n)
      count++;
  }
  else
  count++;    
 }
 printf("%d\n",count);               
 //system("PAUSE");
 return 0;
}
