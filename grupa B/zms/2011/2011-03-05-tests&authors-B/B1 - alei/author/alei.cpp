/**
  TASK: ALEI
  AUTHOR: K. MANEV
*/  

#include <stdio.h>
#define MAXN 150001
int main()
{
    int i,j,k,c;
    int M,N, degree[MAXN];
    
    scanf("%d %d",&N,&M);
    for(i=1;i<=N;i++) degree[i]=0;
    for(i=1;i<=M;i++)
    {
       scanf("%d %d",&j,&k);
       degree[j]++;
       degree[k]++;                 
    }   
    c=0;
    for(i=1;i<=N;i++) c+=degree[i]/2 -1;
    printf("%d\n",c+1);
}
