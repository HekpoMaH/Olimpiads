// Reshenie s po edno BFS na vsyaka zayavka
// Slojnost O(QN)
#include <stdio.h>
#define MAXN 20001

int nei[2*MAXN], start[MAXN][2];
int N, used[MAXN], q[MAXN];

int BFS(int r, int d)
{
   int i,x,y,b,e;
   for(i=1;i<=N;i++) used[i]= -1;
   q[0]=r;b=e=0; used[r]=0;
   while(b<=e)
   {  x=q[b++];
      for(i=start[x][1];i<start[x+1][1];i++)
      {  y=nei[i];    
         if(used[y]== -1)
         { used[y]=used[x]+1;
           if(used[y]==d) return y; 
           q[++e]=y;
         }                                   
      }           
   }
   return 0;      
}


int main()
{
    int i,j,k,b,e,x,y,Q;
    
    scanf("%d",&N);k=0;
    for(i=1;i<=N;i++)
    {  scanf("%d",&start[i][0]);
       start[i][1]=k;
       for(j=1;j<=start[i][0];j++)
       { scanf("%d",&nei[k]);k++;  }                    
    }
    start[N+1][1]=k;
    scanf("%d",&Q);
    for(i=1;i<=Q;i++) 
    {  scanf("%d %d\n",&b,&x);
       e=BFS(b,x); printf("%d\n",e);
    }
    
    return 0;  
}
