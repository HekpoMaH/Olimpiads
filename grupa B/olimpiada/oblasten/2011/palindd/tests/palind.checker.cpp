#include <stdio.h>
#define MAXN 10001


int main(int argc, char * argv[])
{   FILE * inp = fopen(argv[1],"r");
    FILE * out = fopen(argv[2],"r");
    FILE * sol = fopen(argv[3],"r");

    int N,M,t[MAXN],P,pal[MAXN];
    int i, j,beg,end;
    
    if (out==NULL)
    {   printf("0\nCannot open out file\n");
        return 1;
    }
    if (inp==NULL)
    {   printf("0\nCannot open input file\n");
        return 1;
    }
    if (sol==NULL)
    {   printf("0\nCannot open input file\n");
        return 1;
    }

    fscanf(inp,"%d",&N);
    for(i=1;i<=N;i++) fscanf(inp,"%d",&t[i]);
    fscanf(sol,"%d",&M);
    fscanf(out,"%d",&P);
    if(M!=P)             
    {   printf("0\nWrong number of cuts min=%d your=%d\n",M,P);
        return 0;
    }
    if(P>1)
    {
       for(i=1;i<P;i++) fscanf(out,"%d",&pal[i]);
       pal[P]=N;i=1;beg=1;
       while(i<=P)
       {
          end=pal[i];          
          for(j=0;j<=(end-beg)/2;j++)
             if(t[beg+j]!=t[end-j])
             {    
                printf("0\nWrong palindrom %d %d\n",beg,end);
                return 0;
             }
          beg=end+1;i++;      
       }
     }    
     printf("%s\nAccepted\n", argv[4]);
     return 0;
}
