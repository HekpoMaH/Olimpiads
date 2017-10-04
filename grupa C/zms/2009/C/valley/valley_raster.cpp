
#include <stdio.h>
char a[1001][2001]={0};
int main()
{
    int N,beg,len,i,j,k,br;
    int left=1001,right=0;
    
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
       scanf("%d %d",&beg,&len);
       if(beg<left)left=beg;
       if(beg+len-1>right) right=beg+len-1;
       for(j=0;j<len/2;j++)
       {  a[j][beg+j]|=1;a[j][beg+len-j-1]|=2;
          for(k=beg+j+1;k<beg+len-j-1;k++)a[j][k]=7;
       }   
    }
    j=1;br=0;
    for(i=left+1;i<=right;i++)
    {
      switch(a[j][i]) {
         case 1: if(a[j][i-1]==2) br++;
                 if(a[j+1][i+1]!=0)j++;
                 break;
         case 2: if(j>0&&a[j][i+1]==0)j--;
                 break;
         case 3: br++;
                 if(a[j+1][i+1]!=0)j++;
                 break;
         case 4:
         case 7: ;
       }                                                                                
    }
    printf("%d\n",br);        
    return 0;   
}
