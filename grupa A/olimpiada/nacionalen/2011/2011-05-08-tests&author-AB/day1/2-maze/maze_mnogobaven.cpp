// Reshenie s Floyd i tabulirane na 1 vrah za vsyako razstoyanie
// Slojnost O(N^3 + Q)
#include <stdio.h>
#define MAXN 1001
#define INF 2000000000
unsigned N, g[MAXN][MAXN],d[MAXN][MAXN];

int main()
{
    int i,j,k,b,e,x,y,Q;
    
    scanf("%d",&N);
    for(i=1;i<=N;i++)
       for(j=1;j<=N;j++)
           if(i==j) g[i][j]=0; else g[i][j]=INF;
    for(b=1;b<=N;b++)
    {  scanf("%d",&i);
       for(j=1;j<=i;j++)
       { scanf("%d",&e);g[b][e]=g[e][b]=1; }                    
    }
    for(k=1;k<=N;k++)
       for(i=1;i<=N;i++)
          for(j=1;j<=N;j++)
             if(g[i][k]+g[k][j]<g[i][j]) g[i][j]=g[i][k]+g[k][j]; 
/*
for(i=1;i<=N;i++)
{   for(j=1;j<=N;j++) printf("%d ",g[i][j]);
    printf("\n");
}    
*/                
    for(i=1;i<=N;i++)
    {  d[i][0]=0; 
       for(j=1;j<=N;j++)
       {  d[i][g[i][j]]=j;
          if(g[i][j]>d[i][0]) d[i][0]=g[i][j];
       }
    }
/*
for(i=1;i<=N;i++)
{   printf("%d: ",i);
    for(j=1;j<=d[i][0];j++) printf("%d ",d[i][j]);
    printf("\n");
} 
*/       
    scanf("%d",&Q);
    for(i=1;i<=Q;i++) 
    {  scanf("%d %d\n",&b,&x);
       if(d[b][0]<x) printf("0\n");     
       else printf("%d\n",b,x,d[b][x]);
    }
   
    return 0;  
}
