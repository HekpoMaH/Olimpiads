/*
TASK:trip
LANG:C++
*/

#include <stdio.h>
#define MAXN 1002

int g[MAXN][MAXN],n[MAXN][MAXN], v[MAXN];
int N,M,K;

main()
{
   int i,j,k,max,x,y;
   scanf("%d %d %d",&N,&M,&K);
   for(i=1;i<=N;i++)
   {
      for(j=1;j<=N;j++) {g[i][j]=10000;n[i][j]=0;}
      g[i][i]=0;v[i]=1;
   }   
   for(i=1;i<=M;i++)
   {
      scanf("%d %d",&j,&k);
      g[j][k]=g[k][j]=1;
   }
   for(i=1;i<=K;i++)
   {
      scanf("%d",&j);
      v[j]=0;                 
   }
   for(i=1;i<=N;i++)
      for(j=1;j<=N;j++)
      {
         if(i==j)n[i][i]=v[i];
         else n[i][j]=n[j][i]=v[i]+v[j];                 
      }
   int br=0;
   for(k=1;k<=N;k++)
      for(i=1;i<=N;i++)   
        for(j=1;j<=N;j++)
        {
           br++;
           if(g[i][k]+g[k][j]<g[i][j]||(g[i][k]+g[k][j]==g[i][j]&&n[i][k]+n[k][j]>n[i][j]))
           {g[i][j]=g[i][k]+g[k][j];n[i][j]=n[i][k]+n[k][j]-v[k];}                 
        } 
/*for(i=1;i<=N;i++)
{   for(j=1;j<=N;j++)
       printf("%d ",g[i][j]);
    printf("\n");
}
for(i=1;i<=N;i++)
{   for(j=1;j<=N;j++)
       printf("%d ",n[i][j]);
    printf("\n");
} */               
                
   max=0;
   for(i=1;i<=N-1;i++)
      for(j=i+1;j<=N;j++)
         if(n[i][j]>max){max=n[i][j];x=i;y=j;}
//   printf("%d %d %d\n",max, x, y); 
   printf("%d\n%d\n",max,br);        
   return 0;      
}


