 #include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> vi;
int V, E, S, T;
vector<vi> AdjList;

//

const int Max_XY=251;
const int Max_h_plus=31;
int H[Max_XY][Max_XY], W[Max_XY][Max_XY];
int M,N,H_max,k,x1,y1,x2,y2;

//

void input()
{   
  scanf("%d %d %d %d", &M, &N, &k, &H_max); 
  for(int j=1;j<=M;j++)
  for(int i=1;i<=N;i++) 
   scanf("%d %d", &H[i][j], &W[i][j]);
  scanf("%d %d", &x1, &y1);
  scanf("%d %d", &x2, &y2);
}

int vt(int i, int j, int h){return (M*N)*h+((j-1)*N+i-1);}
int ht(int v) {return v/(M*N);}
int it(int v) {int r=v%(M*N);  return 1+r%N;}
int jt(int v) {int r=v%(M*N);  return 1+r/N;}

void make(int v, int i, int j, int h)
{
  if(i<1) return;
  if(i>N) return;
  if(j<1) return;
  if(j>M) return;
  
  int w=vt(i,j,h);
  if(w==T)  AdjList[v].push_back(w);
  else
  {
    if(h<=H[i][j]) return;
    if(h>H[i][j]+H_max) return;
    AdjList[v].push_back(w);
  }  
}


void to_graph()
{
  V=M*N*(Max_h_plus+H_max);
  S=vt(x1,y1,H[x1][y1]);
  T=vt(x2,y2,H[x2][y2]);
  AdjList.assign(V, vi());
  for(int v=0;v<V;v++)
   {
     int i=it(v);
     int j=jt(v);
     int h=ht(v);
     h -= k;
     h += W[i][j];
     if(h >=0)
     {
      make(v,i+1,j,h);
      make(v,i-1,j,h);
      make(v,i,j+1,h);
      make(v,i,j-1,h);
     }     
   }       
}

void bfs() 
{

  map<int, int> dist; 
  dist[S] = 0;          
  queue<int> q; 
  q.push(S);                                 

  while (!q.empty()) 
  {
    int u = q.front(); q.pop();                        
    if(u==T){ printf("%d\n",dist[u]); return; }
    for (int j = 0; j < (int)AdjList[u].size(); j++) 
    {
      int v = AdjList[u][j];                           
      if (!dist.count(v)) 
      {    
        dist[v] = dist[u] + 1;                  
        q.push(v);                              
      }
     } 
  }
  printf("crash\n");
}

main()
{
  input();
  to_graph();
  bfs();
}
