#include <stdio.h>
#define MAXX 1024
#define MAXY 1024

int N,bm[MAXX][MAXY], balx[MAXX],baly[MAXY];
int main(int argc, char * argv[])
{  int i,j,x,y;char c;
   //if (argc != 4)
   //{  printf("0\nWrong number of arguments!\n");return 0; }
   FILE * inp = fopen(argv[1],"r");
   FILE * out = fopen(argv[2],"r");
   if (out==NULL)
   {  printf("0\nCannot open output file\n"); return 0; }
   if (inp==NULL)
   {  printf("0\nCannot open input file\n"); return 0;  }
   fscanf(inp,"%d",&N);
   for(i=0;i<MAXX;i++)
   {  balx[i]=0; for(j=0;j<MAXY;j++) bm[i][j]=baly[j]=0; }
   for(i=0; i<N; i++)
   {  fscanf(inp,"%d %d",&x,&y); bm[x][y]++; }
   for(i=1;i<=N;i++)
   {  if(fscanf(out,"%d %d %c",&x,&y,&c)<0)
      {  printf("0\nOutput file too short\n");return 0; }
         if(x<0||x>=MAXX||y<0||y>=MAXY)
         {  printf("0\nWrong coordinate\n"); return 0;  }
         if(!bm[x][y])
         {  printf("0\nWrong point in output\n"); return 0; }
         if(c=='B') {balx[x]++;baly[y]++;}
        else if(c=='R') {balx[x]--;baly[y]--;}
        else {  printf("0\nWrong color\n"); return 0; }
        bm[x][y] --;
    }
    for(i=0;i<MAXX;i++)
       if(balx[i]<-1||balx[i]>1)
       {   printf("0\nNot balanced row %d disb=%d\n",i,balx[i]);
           return 0;
       }
    for(i=0;i<MAXY;i++)
       if(baly[i]<-1||baly[i]>1)
       {   printf("0\nNot balanced collumn %d disb=%d\n",i,baly[i]);
           return 0;
       }

    for (int i=0; i < MAXX; ++i)
        for (int j=0; j < MAXY; ++j)
            if (bm[i][j] != 0){
                printf("0\nNot all points used!\n");
                return 0;
            }

     printf("%s\nAccepted\n",argv[4]);
     return 0;
}
