#include <stdio.h>
#define MAXN 500000
int N,map[MAXN];
int main(int argc, char * argv[])
{
   int r,pr=0,eof,set,s,ps=-1,t,pt=1;
   int i,j,x,y,cnt=0;char c;
  // if (argc != 4)
  // {
   //   printf("0\nWrong number of arguments!\n");
    //  return 1;
  // }
   FILE * inp = fopen(argv[1],"r");
   FILE * out = fopen(argv[2],"r");
   FILE * ans = fopen(argv[3],"r");

   if (out==NULL)
   {   printf("0\nCannot open output file\n");
        return 1;
   }
   if (inp==NULL)
    {   printf("0\nCannot open input file\n");
        return 1;
    }
    fscanf(inp,"%d",&N);set=0;
    for(i=1;i<=N;i++) map[i]=-1000000000;
    while (eof=fscanf(ans,"%d %d %d",&r,&s,&t)!= 0)
    {  //printf("%d %d %d",r,s,t);
       cnt++;
       if(pt*s==t*ps) map[r]=set;
       else map[r]=++set;
       pr=r;pt=t;ps=s;
    }
//   for(i=1;i<=N;i++) printf("%d\n",map[i]);

    set=0;pr=0;ps=-1;pt=1;
    while (eof=fscanf(out,"%d",&r)!= 0)
    {
//printf("pr=%d r=%d mappr=%d mapr=%d\n",pr,r,map[pr],map[r]);
       if(map[r]==-1000000000)
       {   printf("0\n Elimination of winner\n");
           return 1;
       }

       if(map[r]<0)
       {   printf("0\n Repeted elimination\n");
           return 1;
       }
       if(map[r]<-map[pr])
       {   printf("0\n Wrong order\n");
           return 1;
       }
       pr=r;map[r]=-map[r];cnt--;
    }
       if(cnt!=0)
       {   printf("0\n Wrong number eliminated\n");
           return 1;
       }

     printf("5\nAccepted\n");
     return 0;

}
