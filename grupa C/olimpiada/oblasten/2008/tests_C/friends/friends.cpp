#include <stdio.h>
#define MAXN 2000
#define MAXD 2000
 
typedef struct
{  int N,M,directed;
   int T[MAXN+1][MAXD+1]; } LN_Graph;
typedef struct
{  int N; int P[MAXN+1]; } LP_Tree;
/* Implementation of Queue */
#define MAXQ MAXN
typedef struct
{  int e[MAXQ+1],begin,end; }int_Queue;

void empty_queue(int_Queue* q)
{  q->begin=0;q->end=-1; }
int is_empty_queue(int_Queue* q)
{  if(q->begin>q->end) return 1;
   else return 0;
}
void add_queue(int_Queue* q,int a)
{  q->e[++q->end]=a;}
int get_queue(int_Queue* q)
{  return q->e[q->begin++];}
/* Breadt First Search for Spanning Tree */
int BFS_spanning_tree(LN_Graph* G, LP_Tree* D,int r)
{  int used[MAXN+1],x,y,i;  int_Queue Q;
   int level[MAXN+1];
   for(i=1;i<=G->N;i++) {used[i]=level[i]=0; D->N=G->N;}
   empty_queue(&Q);
   add_queue(&Q,r);used[r]=1;D->P[r]=0;
   while(!is_empty_queue(&Q))
   {  x=get_queue(&Q);
      for(i=1;i<=G->T[x][0];i++)
      {  y=G->T[x][i];
         if(!used[y])
         {  used[y]=used[x]+1;D->P[y]=x; add_queue(&Q,y); }
      }
    }
    int max=0;
    for(i=1;i<=G->N;i++)
    {
       level[used[i]]++;
       if(level[used[i]]>max) max=level[used[i]];
    }
    return max;                    
}
void input_LN_nd(LN_Graph* G)
{  int i,v,w;
   scanf("%d %d",&G->N,&G->M);
   for(i=1;i<=G->N;i++) G->T[i][0]=0;
   for(i=1;i<=G->M;i++)
   {  scanf("%d %d", &v,&w);
      G->T[v][++G->T[v][0]]=w;
      G->T[w][++G->T[w][0]]=v;
   }
}
LN_Graph G; LP_Tree T;int max; 
int main()
{
    input_LN_nd(&G);
    max=BFS_spanning_tree(&G,&T,1);   
    printf("%d\n",max);
}
