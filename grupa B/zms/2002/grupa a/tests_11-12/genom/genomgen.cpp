#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char w[1001][256];
long used[1001];
char u[1001];
char p[500000];
long N,K=150000,L=155;
void main()
{

   FILE	*inp;
   srand( (unsigned)time( NULL ) );
   long i,j,k,l,m;
   inp=fopen("genom.inp","w");
   for(i=1;i<=K/2;i++)
   {
     j=rand()%4;
	 switch (j){
	 case 0: p[i]='A';
		     break;
     case 1: p[i]='C';
		     break;
     case 2: p[i]='G';
		     break;
     case 3: p[i]='T';
		     break;
     }
	}
   if(K%2==1) j=rand()%4;
   switch (j){
	 case 0: p[K/2+1]='A';
		     break;
     case 1: p[K/2+1]='C';
		     break;
     case 2: p[K/2+1]='G';
		     break;
     case 3: p[K/2+1]='T';
		     break;

   }
   for(i=1;i<=K/2;i++)
      p[K/2+K%2+i]=p[K/2-i+1];
   for(j=1;j<=i;j++) u[i]=0;
   i=1;used[1]=1;
   do 
   {
	   i++;
	   used[i]=used[i-1]+rand()%L+100;
   } while(used[i]<K);
   i--;
   fprintf(inp,"%d\n",i);
   for(j=1;j<=i;j++)
   {   
	   m=rand()%3;
	   if(m!=0)
	   {
         do m=rand()%i+1; while(u[m]==1);
	     u[m]=1;l=0;
		 for(k=used[j];k<used[j+1];k++)
		     w[m][l++]=p[k];
		 w[m][l]=0;
       }
	   else
	   {
         do m=rand()%i+1; while(u[m]==1);
	     u[m]=1;l=0;
		 for(k=used[j+1]-1;k>=used[j];k--)
		     w[m][l++]=p[k];
		 w[m][l]=0;
       }
   }
   for(k=1;k<i;k++)
     fprintf(inp,"%s\n",w[k]);
   fprintf(inp,"%s",w[i]);
    
}
