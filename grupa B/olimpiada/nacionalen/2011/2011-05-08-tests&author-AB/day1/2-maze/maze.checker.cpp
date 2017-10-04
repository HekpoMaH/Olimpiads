#include <stdio.h>
#include <stdio.h>
#include <cassert>
#define MAXN 20001
#define LOG_MAXN 15

int nei[2*MAXN], start[MAXN][2];
int N, used[MAXN], q[MAXN], p[MAXN];
int paths[MAXN][4], conect[MAXN][3],brp,pstart,diam;

bool vis[MAXN];
int dist[MAXN];
int anc[MAXN][LOG_MAXN];


int BFS(int r, int d, int v)
{
   int i,x,y,qb,qe;
   for(i=1;i<=N;i++) used[i]= -1;
   q[0]=r;qb=qe=0; used[r]=0; p[r]=0;
   while(qb<=qe)
   {  x=q[qb++];
      for(i=start[x][1];i<start[x+1][1];i++)
      {  y=nei[i];
         if(used[y]== -1)
         { if(y==v)
             if(d==used[x]+1) return 1; else return 0;
             used[y]=used[x]+1;p[y]=x;q[++qe]=y;
         }
      }
   }
}

int dfs(int at, int parent, int cdist) {
    vis[at] = true;
    dist[at] = cdist;
    anc[at][0] = parent;
    for (int p = 1; p < LOG_MAXN; ++p) {
        if (anc[at][p - 1] != -1)
            anc[at][p] = anc[anc[at][p - 1]][p - 1];
        else
            anc[at][p] = -1;
    }
    // dfs algorithm
    for (int i = start[at][1]; i < start[at + 1][1]; ++i) {
        int nxt = nei[i];
        if (!vis[nxt]) {
           vis[nxt] = true;
           dfs(nxt, at, cdist + 1);
        }
    }
}

int findLca(int p, int q) {
    if (dist[p] > dist[q])
        return findLca(q, p);
    int diff = dist[q] - dist[p];
    assert(diff >= 0);
    for (int pow = LOG_MAXN - 1; pow >= 0; --pow)
        if ((diff & (1 << pow)) != 0 && anc[q][pow] != -1) {
            q = anc[q][pow];
        }
    if (p == q)
        return p;
    for (int pow = LOG_MAXN - 1; pow >= 0; --pow)
        if (anc[p][pow] != anc[q][pow] && anc[p][pow] != -1 && anc[q][pow] != -1) {
            p = anc[p][pow];
            q = anc[q][pow];
        }
    assert(p != q);
    return anc[p][0];
}

int getDist(int p, int q) {
    int lca = findLca(p, q);
    return dist[p] + dist[q] - dist[lca] * 2;
}

void preprocess() {
    int root = 1;
    dfs(root, -1, 0);
}

int main(int argc, char *argv[])
{
    int i,j,k,b,e,x,y,Q;

   FILE *in; FILE *ou; FILE *au;
//   if (argc != 4)
//   {  printf("checker input_file competitor_answer author_answer");
 //     return 1;
  // }
   in=fopen(argv[1],"r");
   au=fopen(argv[3],"r");
   if((ou=fopen(argv[2],"r"))==NULL)
   {printf("No output file!\n"); fclose(in);return 1;}

    fscanf(in,"%d",&N);k=0;
    for(i=1;i<=N;i++)
    {  fscanf(in,"%d",&start[i][0]);
       start[i][1]=k;
       for(j=1;j<=start[i][0];j++)
       { fscanf(in,"%d",&nei[k]);k++;  }
    }
    start[N+1][1]=k;

    preprocess();

    fscanf(in,"%d",&Q);
    for(i=1;i<=Q;i++)
    {  fscanf(in,"%d %d",&b,&x);
       fscanf(au,"%d",&y);
       if(fscanf(ou,"%d",&e) == -1)
       {  printf("0\n");
           printf("Unexpected end of output!\n");
          fclose(in);fclose(ou); return 1;}
        //printf("b = %d, e = %d, x = %d\n", b, e, x);

        if (y == 0 && e != 0) {
            printf("0\n");
            printf("Wrong output!\n");
            fclose(in);
            fclose(ou);
            return 1;
        }
        if (y != 0) {
            //assert((!BFS(b, x, e)) == (getDist(b, e) != x));
            if (e < 0 || e > N || getDist(b, e) != x) {
                printf("0\n");
                printf("Wrong output!\n");
                fclose(in);
                fclose(ou);
                return 1;
            }
        }
        /*
       if(y==0&&e!=0)
       {  printf("Wrong output!\n");
          fclose(in);fclose(ou); return 1;}
        if (y != 0) {
          if (getDist(b, e) != x) {
                printf("b = %d, e = %d, x = %d\n", b, e, x);
                printf("distance between %d and %d -> %d instead of %d\n",
                    b, e, getDist(b, e), x);
            }
            if (e != 0)
              assert((!BFS(b,x,e)) == (getDist(b, e) != x));
//       if(!BFS(b,x,e))
//       {  printf("Wrong output!\n");
//          fclose(in);fclose(ou); return 1;}
        if (getDist(b, e) != x) {
            printf("Wrong output!\n");
            fclose(in);
            fclose(ou);
            return 1;
        }*/
    }
    printf("5\n");
    printf("Accepted!\n");
    return 0;
}
