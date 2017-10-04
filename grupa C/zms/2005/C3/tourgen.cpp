#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define V 90
#define E 2000

void main()
{
   FILE *ou;
   int i,j,k,g[101][101];
   srand( (unsigned)time( NULL ) );
   ou=fopen("tour.in8","w");
   i=rand()%V+1;j=rand()%V+1;
   if(i==j) j=(i+V/2)%V+1;
   fprintf(ou,"%d %d %d %d\n",V,E,i,j);
   for(i=1;i<=100;i++)
	   for(j=1;j<=100;j++)
		   g[i][j]=0;
   for(i=1;i<=V;i++) fprintf(ou,"%d\n",500+rand()%2500);
   for(i=1;i<=V-1;i++)
   {
      fprintf(ou,"%d %d\n",i,i+1,rand()%100+1);
	  g[i][i+1]=g[i+1][i]=1;
   }
   fprintf(ou,"%d 1\n",V);
   g[1][V]=g[V][1]=1;
   j=V;
   while(j<E)
   {
      i=rand()%V+1;k=rand()%V+1;
	  if(i==k) k=(i+V/2)%V+1;
	  if(g[i][k]==0)
	  {
		  g[i][k]=g[k][i]=1;
	      fprintf(ou,"%d %d\n",i,k,rand()%100+1);
		  j++;
	  }
   }
 }
