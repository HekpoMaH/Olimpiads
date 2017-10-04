// Reshenie s razbivane na patishta i "skokove"
// Slojnost v srednia sluchay O(Q.lg N)
#include <stdio.h>
#define MAXN 20001

int nei[2*MAXN], start[MAXN][2];
int N, used[MAXN], q[MAXN], p[MAXN];
int paths[MAXN][4], conect[MAXN][3],brp,pstart,diam;


int BFS(int r)
{
   int i,x,y,max=0,maxv=r,b,e;
   for(i=1;i<=N;i++) used[i]= -1;
   q[0]=r;b=e=0; used[r]=0; p[r]=0;
   while(b<=e)
   {  x=q[b++];
      for(i=start[x][1];i<start[x+1][1];i++)
      {  y=nei[i];    
         if(used[y]== -1)
         { used[y]=used[x]+1;p[y]=x;q[++e]=y;
           if(used[y]>max) {max=used[y];maxv=y;}
         }                                   
      }           
   }
   return maxv;      
}

void build_paths(int to)
{
   int x,y,from,c=0;
   brp++;paths[brp][1]=to; x=to;
   while(used[x]!= -1) { x=p[x];c++; }
   from=x;x=to;paths[brp][2]=c;
   paths[brp][3]=pstart;
   y=pstart+c;pstart=y+1;
      nei[y--]=x;
   while(used[x]!= -1)
   {  conect[x][0]=brp;conect[x][1]=from;
      conect[x][2]=c--; used[x]= -1;
      x=p[x]; nei[y--]=x;
   }
   paths[brp][0]=from;
}

int findd(int v,int d)
{
    int p,con,lenf,lent;
    if(d>diam) return 0;
    while(conect[v][0]!=0&&d>conect[v][2]) 
    {  d-=conect[v][2];v=conect[v][1]; }
    if(conect[v][0]!=0||conect[v][0]==0&&d<=conect[v][2])
    { p=paths[conect[v][0]][3];return nei[p+conect[v][2]-d];}   
    else 
       if(conect[v][2]+d<=paths[0][2]) return nei[conect[v][2]+d];
       else return 0;
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
    b=BFS(1); e=BFS(b); diam=used[e];
// postroyavane na patishta    
    brp=0;
    paths[brp][0]=b;used[b]=-1;
    conect[b][0]=brp;conect[b][1]=b;conect[b][2]=0;
    paths[brp][1]=e; paths[brp][2]=used[e];
    paths[brp][3]=0;
    x=e;y=paths[brp][2];pstart=y+1;nei[y--]=x;
    while(used[x]!= -1)
    {  conect[x][0]=brp;conect[x][1]=b;
       conect[x][2]=used[x]; used[x]= -1;
       x=p[x];nei[y--]=x;
    }
    for(i=1;i<=N;i++)
       if(used[i] != -1) build_paths(i);  
// zayavki
   scanf("%d",&Q);
    for(i=1;i<=Q;i++) 
    {  scanf("%d %d\n",&b,&x);
      e=findd(b,x); printf("%d\n",e);
    }
    return 0;  
}
