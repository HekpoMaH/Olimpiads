#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char w[1001][256];
char used[1001];
char p[300000];
int N,K;
main()
{

   FILE	*inp,*out,*err;
   int i,j=0,l,m,sgn;
   inp=fopen("genom.inp","r");
   out=fopen("genom.out","r");
   err=fopen("genom.err","w");
   fscanf(inp,"%d",&N);
   for(i=1;i<=N;i++)
   {
     fscanf(inp,"%s",&w[i]);
     used[i]=0; 
   }
   for(i=1;i<=N;i++)
   {
	   if(fscanf(out,"%d",&K)== -1)
	 {printf("Not all words used\n");exit(0);}	 
     if(K>0) sgn=1;else sgn=-1;
	 K=(K>0?K:-K);
	 if(used[K]==0) used[K]=1;
	 else {printf("Second use of a word\n");exit(0);}
	 l=strlen(w[K]);
	 if(sgn==1) {m=0;while(m<l) p[j++]=w[K][m++]; }
	 else {m=l-1;while(m>=0) p[j++]=w[K][m--]; }
   }
   p[j]=0;
   for(l=0,j--;l<j;l++,j--)
	   if(p[l]!=p[j])
		   {printf("Not a palindrom\n");exit(0);}
   printf("OK!!!\n");

}
