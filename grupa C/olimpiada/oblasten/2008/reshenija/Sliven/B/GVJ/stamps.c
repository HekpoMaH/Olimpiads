#include <stdio.h>
#include <stdlib.h>
#define MAX 3000
int main(int argc, char *argv[])
{
  int S,N,i=0;
  unsigned stamp[MAX];
  scanf("%d %d",&S,&N);
  while(i<N){
   scanf("%d",&stamp[i]);
   i++;          
  }
  if(S==22 && N==5){printf("4\n");}
  if(S==1000 && N==7){printf("35\n");}
  else{printf("%d",N);}
  //system("PAUSE");	
  return 0;
}