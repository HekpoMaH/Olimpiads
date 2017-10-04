#include <stdio.h>
#include <stdlib.h>
#define max_s 5001
#define max_n 3000
int min_num_stm[max_s];
int stm[max_n];
int i,n,s,j;
#define min(a,b) (a<b?a:b)

int main()
{
    scanf("%d%d",&s,&n);
    for(i=0;i<n;i++)
    {
      scanf("%d",&stm[i]);
      if(stm[i]==1)
      {
        n--;
        i--;
      }
    }
    min_num_stm[1]=1;
    min_num_stm[0]=0;
    for(i=2;i<=s;i++)
    {
      min_num_stm[i]=min_num_stm[i-1]+1;
      for(j=0;j<n;j++)
        if(stm[j]<=i)
           min_num_stm[i]=min(min_num_stm[i],min_num_stm[i-stm[j]]+1);   
    }
    printf("%d\n",min_num_stm[s]);
    //system("pause");
    return 0;
}
