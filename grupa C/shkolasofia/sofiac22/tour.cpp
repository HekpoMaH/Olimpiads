#include <stdio.h>
#include <stdlib.h>
//#include <values.h>
#define MAXINT 2000000000

int main()
{
   int N,M,X,Y,b,e,mind;
   int a[101][101],V[101];
   int den[101],pred[101],used[101],i,j,l;
   scanf("%d%d%d%d",&N,&M,&X,&Y);
   for(i=1;i<=N;i++)
   {
      used[i]=0;
      a[i][0]=0;
      den[i]=MAXINT;
      pred[i]=X;
      scanf("%d",V+i);
   }
   for(i=1;i<=M;i++)
   {
      scanf("%d%d",&b,&e);
      a[b][++a[b][0]]=e;
      a[e][++a[e][0]]=b;
   }
   used[X]=1;den[X]=0;pred[X]=-1;
   for(i=1;i<=a[X][0];i++)den[a[X][i]]=abs(V[X]-V[a[X][i]]);
   for(l=2;l<=N;l++)
   {
     mind=MAXINT;
     b=-1;
     for(i=1;i<=N;i++)if(used[i]==0&&den[i]<mind){mind=den[i];b=i;}
     if(b==Y)break;
     used[b]=1;
     for(i=1;i<=a[b][0];i++)
     {
       e=a[b][i];
       if(den[e]>den[b]+abs(V[b]-V[e]))
       {
         den[e]=den[b]+abs(V[b]-V[e]);
         pred[e]=b;
        }
      }
   }
   i=-1;j=Y;
   do
   {
      used[++i]=j;
      j=pred[j];

   }while(j!=-1);
   printf("%d\n",den[Y]);
   for(j=i;j>=1;j--)printf("%d ",used[j]);
   printf("%d",used[0]);
   printf("\n");

}

