#include<bits/stdc++.h>
using namespace std;
typedef long long flow_t;
const int nmax=509;
const int mmax=2*10009;
#define pb push_back
const flow_t inf=1e15;
struct edge{
   int to;
   flow_t rd;
   int nxt;
   edge(){}
   edge(int _to,flow_t _rd,int _nxt){
      to=_to;
      rd=_rd;
      nxt=_nxt;
   }
};
int n,m;
int source,target;
int head[nmax];
edge e[mmax];
int lvl[nmax];
int ptr[nmax];
vector<int> path;
int e_len=2;
void add_edge(int from,int to,flow_t cap){
   e[e_len]=edge(to,cap,head[from]);
   head[from]=e_len++;
}
void input(){
   int from,to;
   flow_t rd;
   cin>>n>>m;
   source=1;target=n;
   memset(head,-1,sizeof(head));
   for(int i=1;i<=m;i++){
      cin>>from>>to>>rd;
      add_edge(from,to,rd);
      add_edge(to,from,0);
   }
}
bool bfs(){
   queue<int> q;
   memset(lvl,-1,sizeof(lvl));
   q.push(target);
   lvl[target]=0;
   while(!q.empty()){
      int v=q.front();
      q.pop();
      for(int i=head[v];i!=-1;i=e[i].nxt){
         if(lvl[e[i].to]==-1&&e[i^1].rd>0){
            lvl[e[i].to]=lvl[v]+1;
            q.push(e[i].to);
         }
      }
   }
   return lvl[source]!=-1;
}
flow_t dfs(int v){
   if(v==target)return inf;
   for(int i=ptr[v];i!=-1;i=ptr[v]=e[i].nxt)
      if(lvl[e[i].to]==lvl[v]-1&&e[i].rd>0){
         path.pb(i);
         if(flow_t tmp=dfs(e[i].to))
            return min(tmp,e[i].rd);
         path.pop_back();
      }
   return 0;
}
void update_graph(int fl){
   for(int i=0;i<(int)path.size();i++){
      e[path[i]].rd-=fl;
      e[path[i]^1].rd+=fl;
   }
}
flow_t dinitz(){
   flow_t maxflow=0,cflow;
   while(bfs()){
      cout.flush();
      copy(head+1,head+n+1,ptr+1);
      while(path.clear(), cflow=dfs(source)){
         maxflow+=cflow;
         update_graph(cflow);
      }
   }
   return maxflow;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   input();
   cout<<dinitz()<<"\n";
}
