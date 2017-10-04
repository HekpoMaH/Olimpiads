#define MAXN 25000
#include <stdio.h>
int t[MAXN], pal[MAXN][2];
int C[MAXN][2];

int main()
{

   int  N, i, j, k, x,y;
   scanf("%d",&N);
   for(i=1;i<=N;i++) scanf("%d",&t[i]);
   k= -1;
   for(i=1;i<=N;i++)
   {  j=1;
      while(i-j>=1 && i+j<=N)
      { if(t[i-j]!=t[i+j]) break; else j++;}
      j--;pal[++k][0]=i-j;pal[k][1]=i+j;
   }
   for(i=1;i<N;i++)
   {  j=1;
      while(i-j+1>=1 && i+j<=N)
      { if(t[i-j+1]!=t[i+j]) break; else j++;}
      j--;if(j!=0) {pal[++k][0]=i-j+1;pal[k][1]=i+j;}
   }
   C[1][0]=C[1][1]=1;
   for(i=2;i<=N;i++)
   {   C[i][0]=i;C[i][1]=i;
       for(j=0;j<=k;j++)
       {
         x=pal[j][1]-i;y=pal[j][0]+x;
         if(x>=0 && y<=i)
            if(C[i][1]>C[y-1][1]+1){C[i][1]=C[y-1][1]+1;C[i][0]=y;}
       }
   }
   printf("%d\n",C[N][1]);
   if(k=C[N][1]!=1)
   {
      j=N;k=C[N][1];
      while(k>1)
      {  t[--k]=C[j][0]-1;j=C[j][0]-1;}
      for(i=1;i<C[N][1]-1;i++) printf("%d ",t[i]);
      printf("%d\n",t[C[N][1]-1]);

   }
   return 0;
}
