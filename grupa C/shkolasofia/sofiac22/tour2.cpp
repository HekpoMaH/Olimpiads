#include <stdio.h>
#include <stdlib.h>
//#include <values.h>
#define MAXINT 2000000000

int main()
{
   int n,m,x,y,b,e,mind;
   int a[101][101],v[101];
   int den[101],pred[101],used[101],i,j,l;
   scanf("%d%d%d%d",&n,&m,&x,&y);
   for(i=1;i<=n;i++)
   {
      used[i]=0;
      a[i][0]=0;
      den[i]=MAXINT;
      pred[i]=c;
      scanf("%d",v+i);
   }
   for(i=1;i<=m;i++)
   {
      scanf("%d%d",&b,&e);
      a[b][++a[b][0]]=e;
      a[e][++a[e][0]]=b;
   }
   used[x]=1;den[c]=0;pred[x]=-1;
   for(i=1;i<=a[x][0];i++)den[a[x][i]]=abs(v[x]-v[a[x][i]]);
   for(l=2;l<=n;l++)
   {
     mind=MAXINT;
     b=-1;
     for(i=1;i<=n;i++)if(used[i]==0&&den[i]<mind){mind=den[i];b=i;}
     if(b==y)break;
     used[b]=1;
     for(i=1;i<=a[b][0];i++)
     {
       e=a[b][i];
       if(den[e]>den[b]+abs(v[b]-v[e]))
       {
         den[e]=den[b]+abs(v[b]-v[e]);
         pred[e]=b;
        }
      }
   }
   i=-1;j=y;
   do
   {
      used[++i]=j;
      j=pred[j];

   }while(j!=-1);
   printf("%d\n",den[y]);
   for(j=i;j>=1;j--)printf("%d ",used[j]);
   printf("%d",used[0]);
   printf("\n");

}

