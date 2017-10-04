#include <stdio.h>

unsigned grayc(int i)
{
   unsigned gray[256] =
   {1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,5,
    1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,6,
    1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,5,
    1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,7,
    1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,5,
    1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,6,
    1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,5,
    1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,8,
    1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,5,
    1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,6,
    1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,5,
    1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,7,
    1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,5,
    1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,6,
    1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,5,
  1  ,2,1,3,1,2,1,4,1,2,1,3,1,2,1,9};

   unsigned x,y=i%256;
   if(y!=255) return gray[y];
   x=0; while(i>0&&i%256==255) {i/=256;x++;}
   return x*8+gray[i%256];
}

int main()
{
   int N,K;
   // could be extended to N
   int invert[21]={0,1,3,7,15,31,63,127,255,511,1023,
                   2047,4095,8191,16383,32767,65535,
                   131071,262143,524287,1048575};
   unsigned prev,curr,next;  //three consecutive
   scanf("%d %d",&N,&K);
   printf("%d\n",invert[N]); //coincidence
   prev=K;                   // start planet
   for(int i=0;i<invert[N]-2;i=i+2)
   {
      curr=prev^invert[N];   // invert all N bits
      next=prev^invert[grayc(i/2)]; // bits defined from Gray
      if(curr>prev) printf("%d ",curr-prev);
      else printf("-%d ",prev-curr);
      if(next>curr) printf("%d ",next-curr);
      else printf("-%d ",curr-next);
      prev=next;
   }
   //last step - only first
   curr=prev^invert[N];
   if(curr>prev) printf("%d\n",curr-prev);
   else printf("-%d\n",prev-curr);
   return 0;
}
