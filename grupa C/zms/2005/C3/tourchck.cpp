#include <stdio.h>
#include <stdlib.h>
//#include <value.h>
#define MAXINT 2000000000

void main()
{
   FILE *in,*ou;
   int s,f,k;
   int N,M,X,Y,b,e,mind;
   int a[101][101],V[101];
   int den[101],tree[101],used[101],i,j,l;

   
   if((ou=fopen("tour.out","r"))== NULL) 
   {
	   printf("NO OUTPUT!\n");exit(0);
   }
   in=fopen("tour.inp","r");

   fscanf(in,"%d %d %d %d",&N,&M,&X,&Y);
   for(i=1;i<=N;i++)
   {
      used[i]=0;
      a[i][0]=0;
      den[i]=MAXINT;
      tree[i]=X;
      fscanf(in,"%d",V+i);
   }
   for(i=1;i<=M;i++)
   {
      fscanf(in,"%d %d",&b,&e);
      a[b][++a[b][0]]=e;
      a[e][++a[e][0]]=b;
   }

   //Dijkstra
   //initial vertexisation
   used[X]=1;den[X]=0;tree[X]=-1;
   for(i=1;i<=a[X][0];i++)
      den[a[X][i]]=abs(V[X]-V[a[X][i]]);

   //the rest
   for(l=2;l<=N;l++)
   {  // find min denivelation
      mind=MAXINT;b=-1;
      for(i=1;i<=N;i++)
         if(used[i]==0&&den[i]<mind){mind=den[i];b=i;}
      if(b==Y) break;
      used[b]=1;
      //relaxation
      for(i=1;i<=a[b][0];i++)
      {
          e=a[b][i];
          if(den[e]>den[b]+abs(V[b]-V[e]))
          {den[e]=den[b]+abs(V[b]-V[e]);tree[e]=b;}
      }
   }
/*for(i=1;i<=N;i++)
{
   for(j=1;j<=a[i][0];j++) printf("%d ",tree[i]);
   printf("\n");
}

   i=-1;j=Y;
   do{
      printf("%d\n",j);
      used[++i]=j;
      j=tree[j];
   } while(j!=-1);


   for(j=i;j>=0;j--)
     printf("%d ",used[j]);
   printf("\n");
*/
   fscanf(ou,"%d",&i);
   if(i!=X)
   {
	   printf("WRONG START!\n");exit(0);
   }
   s=0;
   while(fscanf(ou,"%d",&j)!= EOF)
   {
      f=0;
	  for(k=1;k<=a[i][0];k++) 
		  if(a[i][k]==j){f=1;break;}
	  if(f==0)
      {
	   printf("NO EDGE! %d %d\n",i,j);exit(0);
	  }
      s+=abs(V[i]-V[j]);
      i=j;  
   }
   if(j!=Y)
   {
	   printf("WRONG END!\n");exit(0);
   }
   if(s!=den[Y])
   {
	   printf("Your:%d My:%d!\n",s,den[Y]);exit(0);
   }
    printf("OK!!!");

}

