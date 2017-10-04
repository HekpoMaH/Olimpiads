// boats.cpp Георги Георгиев (Скелета)
// Задача: Най-широки лодки

#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <time.h>
#include <limits.h>
using namespace std;

const int MaxVertex=1001, MaxPairs=10001; 
int E[MaxVertex][MaxVertex], Pairs[MaxPairs][2], D[MaxVertex], Pi[MaxVertex], Depth[MaxVertex];
bool Marked[MaxVertex];
int N,M,K,w;


void input()
{   
  int u,v,w;
  scanf("%d %d %d", &N, &M, &K); 
  for(int i=1; i<=N; i++)
   for (int j=1; j<=N; j++)
    E[i][j]=0; 
  for(int i=1; i<=M; i++) 
  {
   scanf("%d %d %d", &u, &v, &w);
   E[u][v]=w;
   E[v][u]=w;
  }
  for(int i=1; i<=K; i++)
   scanf("%d %d\n",&Pairs[i][1],&Pairs[i][2]);    
}

void CreateMST(int s)
{
  int u,v,w,cnt;
  for(int i=1; i<=N; i++) 
   { D[i]=0; Pi[i]=-1; Marked[i]=false; Depth[i]=0;}
  D[s]=INT_MAX; // MaxSpaningTree !! 
  cnt=1; // колко върха са в T (в началото s е в Т)
  while (cnt<=N) {
   w=0; u=0;
   for(int i=1; i<=N; i++)
     if ((D[i]>w) && (!Marked[i])) 
       {w=D[i]; u=i;}
   Marked[u]=true;
//   if (u != s) printf("%d %d %d %d\n",u, Pi[u], D[u], Depth[u]);
   for(int v=1; v<=N; v++)
     if ((D[v]<E[u][v]) && (!Marked[v]))
       {D[v]=E[u][v]; Pi[v]=u; Depth[v]=Depth[u]+1;} 
   cnt++;
  }
// Ребрата в T са <v,Pi(v)>, а теглата им са d[v], за v \neq s
}

int WP(int u, int v)
{
  int w;
  w=INT_MAX;
  while (Depth[u]>Depth[v])
  {
   if (D[u]<w) w=D[u];
   u=Pi[u];
  }
  while (Depth[v]>Depth[u])
  {
   if (D[v]<w) w=D[v];
   v=Pi[v];
  }
  while (v!=u)
  {
   if (D[v]<w) w=D[v];
   if (D[u]<w) w=D[u];
   u=Pi[u];
   v=Pi[v];
  }
  return w;
}

void SolveP1()
{
  int w,u,v;
//  w=INT_MAX;
//  for (int v=1; v<=N; v++)
//   if ((Pi[v]>0) && (D[v]<w))
//    w=D[v];
//  printf("%d\n",w);

  for(int i=1; i<=K; i++)
  {
   u=Pairs[i][1];
   v=Pairs[i][2];
//   printf("%d %d %d\n",u,v,WP(u,v));
   printf("%d\n",WP(u,v));    
  }
}

main()
{
  input();
  CreateMST(1);
  SolveP1();
}
