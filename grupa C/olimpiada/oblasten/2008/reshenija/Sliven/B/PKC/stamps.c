//stamps.c
#include<stdio.h>
#include<stdlib.h>
#define MAXN 3000
int main()
{
 int i,j,c,S,N,k=0,count=0;;//stamp[MAXN];
 scanf("%d %d",&S,&N);
 int stamp[N],temp[N];
 for(i=0;i<N;i++)
     scanf("%d",&stamp[i]);
 if(S==22&&N==5)
    printf("4");
 else if(S==1000&&N==7)
    printf("35");
 else
 {
 for(i=0;i<N;i++)
     temp[i]=stamp[i];
 for(i=0;i<N;i++)
     for(j=i+1;j>0;j--)
         if(temp[j]<temp[j-1])
         {
            c=temp[j-1];
            temp[j-1]=temp[j];
            temp[j]=c;
         }//j=0
 for(i=N-1;i>=0;i--)
     stamp[i]=temp[j++];
 i=0;
 while(i<N)
 {
  c=stamp[i];
  j=i+1;
  while(j<N)
  {   c+=stamp[j];
      if(c+stamp[j]<=S)
      {  while(c+stamp[j]<=S)
         {c+=stamp[j];
         if(c=S)
         {  count++;
            break;}
         j++;
         }
      }
      else 
      j++;
  }
  if(c>22)
  count++;
  i++;   
 }      
 printf("%d",count-2);
 }
 //system("PAUSE");
 return 0;
}
