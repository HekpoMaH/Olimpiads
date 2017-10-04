/*
TASK:tri
LANG:C++
*/
#include <stdio.h>
#define MAXN 2000
#define MAXM 20000
#define MAXSUM 6000
int N,M,H[MAXM][2],G[MAXN][MAXN]={0};

int main()
{
   int i,j,u,v,S;
   scanf("%d %d",&N,&M);
   for(i=1;i<=M;i++)
   {  scanf("%d %d",&H[i][0],&H[i][1]);
      G[H[i][0]][H[i][1]]=1;
      G[H[i][1]][H[i][0]]=1;
   }
   S= MAXSUM;
   for(i=1;i<=M;i++)
   {   j=1;u=H[i][0];v= H[i][1];
       while(j<=N&&G[u][j]*G[v][j]==0)j++;
       if(j<=N&&u+v+j<S)
          S=u+v+j;
   }
   if(S== MAXSUM) printf("0\n");
   else printf("%d\n",S);
}
