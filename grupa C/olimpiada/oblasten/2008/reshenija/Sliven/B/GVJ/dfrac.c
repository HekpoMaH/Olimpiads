#include <stdio.h>
#include <stdlib.h>
#define MAX 51
int main(int argc, char *argv[])
{
long int s[MAX];
long int a,b,k,p,i=0,tmp,ind=0,ind2=0,init1=0;
while(init1<52){
s[init1]=0;
init1++;
}
scanf("%d %d",&a,&b);
scanf("%d %d",&k,&p);
 //case non-ending fraction
 while(a%b != 0){
         a=a*10;
         tmp=a/b;
         a=a-(tmp*b);
         i++;
            if(i >= k){
                 s[ind]=tmp;
                 ind++;
            }
   if(i>=p+k-1){break;}
   }
 //case ending fraction
    if(a%b==0){
   ind=p-ind;
   }
   //PRINTING RESULT
       while(ind2<ind){
      printf("%d",s[ind2]);
      ind2++;                 
      }
      printf("\n");
  //system("PAUSE");	
  return 0;
}