/*
TASK: boxes
LANG: C++
*/
#include <stdio.h>
#include <string.h>
#define MAXN 100001
int lBeg[MAXN],lEnd[MAXN],lists[2*MAXN][2];
int used[MAXN],queue[MAXN],qb,qe;
int main()
{
    int t,i,j,N,empty;
    for(t=1;t<=2;t++)
    {
       memset(lBeg,0,MAXN*sizeof(int));
       memset(lEnd,0,MAXN*sizeof(int));
       memset(lists,0,2*MAXN*sizeof(int));
       memset(used,0,MAXN*sizeof(int));              
       scanf("%d",&N);
       empty=1;
       for(i=1;i<=N;i++)
       {
          scanf("%d",&j);
          if (i==j) continue;
          if(lBeg[j]==0) {lBeg[j]=lEnd[j]=empty;}
          else {lists[lEnd[j]][1]=empty; lEnd[j]=empty;}
          lists[lEnd[j]][0]=i;lists[lEnd[j]][1]=0;empty++;
          if(lBeg[i]==0) {lBeg[i]=lEnd[i]=empty;}
          else {lists[lEnd[i]][1]=empty; lEnd[i]=empty;}
          lists[lEnd[i]][0]=j;lists[lEnd[i]][1]=0;empty++;   
       }
       int broken=0,x,y;
       for(i=1;i<=N;i++)
       {
          if(used[i]) continue;
          broken++;
          qb=qe=0;queue[qb]=i;used[i]=1;
          while(qb<=qe)
          {
             x=queue[qb++];j=lBeg[x];
             do 
             {
                y=lists[j][0];                     
                if(!used[y]) {used[y]=1;queue[++qe]=y;}
                j=lists[j][1];
             } while(j!=0);               
          }                 
       }
       printf("%d",broken);
       if(t==1) printf(" ");
       else printf("\n");
    }
    return 0;
}
