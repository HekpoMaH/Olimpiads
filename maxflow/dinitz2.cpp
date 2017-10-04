#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long lli;
const int nmax=509;
const int mmax=10009;
const int inf=1e9;
struct edge{
   int to;
   lli rd;
   int nxt;
   edge(){}
   edge(int _to,lli _rd,int _nxt){
      to=_to;
      rd=_rd;
      nxt=_nxt;
   }
};
edge e[2*mmax];
int head[nmax];
int lvl[nmax];
int ptr[nmax];
int br=2;
int n,m;
vector<int> path;
void addedge(int from,int to,int rd){
   e[br]=edge(to,rd,head[from]);
   head[from]=br;
   br++;
}
void read(){
   memset(head,-1,sizeof(head));
   cin>>n>>m;
   for(int i=1;i<=m;i++){
      int x,y,z;
      cin>>x>>y>>z;
      addedge(x,y,z);
      addedge(y,x,0);
   }
}
bool bfs(){
   queue<int> q;
   memset(lvl,-1,sizeof(lvl));
   lvl[n]=1;
   q.push(n);
   while(!q.empty()){
      int curr=q.front();
      q.pop();
      for(int i=head[curr];i!=-1;i=e[i].nxt){
         int nxtv=e[i].to;
         if(lvl[nxtv]==-1&&e[i^1].rd!=0){
            lvl[nxtv]=lvl[curr]+1;
            q.push(nxtv);
         }
      }
   }
   return lvl[1]!=-1;
}
lli dfs(int v){
   if(v==n)return inf;
   for(int i=ptr[v];i!=-1;i=ptr[v]=e[i].nxt){
      int nxtv=e[i].to;
      if(lvl[nxtv]+1==lvl[v]&&e[i].rd){
         path.pb(i);
         if(lli tmp=dfs(nxtv)){
            return min(e[i].rd,tmp);
         }
         path.pop_back();
      }
   }
   return 0;
}
void update(int fl){
   for(int i=0;i<(int)path.size();i++){
      e[path[i]].rd-=fl;
      e[path[i]^1].rd+=fl;
   }
}
lli dinitz(){
   lli flow=0;
   while(bfs()){
      copy(head+1,head+n+1,ptr+1);
      lli crflow=0;
      while((path.clear(), crflow=dfs(1))){
         flow+=crflow;
         update(crflow);
      }
   }
   return flow;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   cout<<dinitz()<<"\n";
}
