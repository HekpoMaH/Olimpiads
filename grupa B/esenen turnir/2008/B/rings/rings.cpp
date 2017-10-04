#include <stdio.h>
#define MAXN 1001
typedef struct
{  int N,M;
   int T[MAXN+1][MAXN+1]; } LN_Graph;
typedef struct
{  int e[MAXN+1],begin,end; }int_Queue;
LN_Graph G; int TA[MAXN],TB[MAXN]; int A,B; 
/* Обхождане в ширина за намиране в D
   разстоянието от r да всеки връх  */
int BFS(int* D,int r)
{  int x,y,i;  int_Queue Q;
   for(i=1;i<=G.N;i++) D[i]=-1;
   Q.begin=0;Q.end=-1; 
   Q.e[++Q.end]=r;D[r]=0;
   while(!(Q.begin>Q.end))
   {  x=Q.e[Q.begin++];
      for(i=1;i<=G.T[x][0];i++)
      {  y=G.T[x][i];
         if(D[y]== -1)
         {  D[y]=D[x]+1;Q.e[++Q.end]=y; }
      }
    }
}
/* Въвеждане на граф в представяне
   със списъци на съседите   */
void input_LN()
{  int i,v,w;
   scanf("%d %d",&G.N,&G.M);
   for(i=1;i<=G.N;i++) G.T[i][0]=0;
   for(i=1;i<=G.M;i++)
   {  scanf("%d %d", &v,&w);
      G.T[v][++G.T[v][0]]=w;
      G.T[w][++G.T[w][0]]=v;
   }
}
int main()
{
    int i,j,pend=0;
    input_LN();
    for(j=1;j<=2;j++)
    {  scanf("%d %d",&A,&B);
       BFS(TA,A); BFS(TB,B);    
       for(i=1;i<=G.N;i++)
         if(TA[i]+TB[i]!= TA[B]) pend++;
       if(j==1) {printf("%d ",pend); pend=0;}
       else printf("%d\n",pend);
    }   
}
