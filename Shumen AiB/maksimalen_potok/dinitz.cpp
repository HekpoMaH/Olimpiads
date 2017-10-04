#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
const int nmax=509;
const int mmax=1e4+9;
const int inf=1e9;
#define pb push_back
struct edge{
   int to,nxt;
   int fl;
   edge(){};
   edge(int _to,int _nxt,int _fl){
      to=_to;
      nxt=_nxt;
      fl=_fl;
   }
};
int head[nmax];//za vr i nai gornoto rebro
int head2[nmax];
int lvl[nmax];
edge e[2*mmax];

int ebr;
void add(int from,int to,int fl){
   e[ebr]=edge(to,head[from],fl);
   head[from]=ebr++;
   e[ebr]=edge(from,head[to],0);
   head[to]=ebr++;
}
int n,m;
void input(){
   cin>>n>>m;
   for(int i=1;i<=m;i++){
      int a,b,c;
      cin>>a>>b>>c;
      add(a,b,c);
   }
}
bool bfs(){
   queue<int> q;
   memset(lvl,-1,sizeof(lvl));
   q.push(n);
   lvl[n]=0;
   while(!q.empty()){
      int curr=q.front();
      //cerr<<curr<<"\n";
      q.pop();
      for(int i=head[curr];i!=-1;i=e[i].nxt){
         //cerr<<" "<<e[i].to<<"\n";
         int nxt=e[i].to;
         if(lvl[nxt]==-1&&e[i^1].fl){
            lvl[nxt]=lvl[curr]+1;
            //cerr<<nxt<<"->"<<lvl[nxt]<<"\n";
            q.push(nxt);
         }
      }
   }
   //cerr<<lvl[1]<<"\n";
   return lvl[1]!=-1;
}
vector<int> path;
lli dfs(int node){
   if(node==n)return inf;
   for(int i=head2[node];i!=-1;i=head2[node]=e[i].nxt){
      int nxt=e[i].to;
      if(lvl[nxt]+1==lvl[node]&&e[i].fl){
         path.pb(i);
         lli flw=dfs(nxt);
         if(flw!=0){
            return min(flw,(lli)e[i].fl);
         }
         path.pop_back();
      }
   }
   return 0;
}
void update(vector<int> p,int flw){
   for(int i=0;i<(int)p.size();i++){
      e[p[i]].fl-=flw;
      e[p[i]^1].fl+=flw;
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   memset(head,-1,sizeof(head));
   input();
   int flw;
   lli ansfl=0;
   while(bfs()){
      for(int i=1;i<=n;i++)head2[i]=head[i];
      while(path.clear(),flw=dfs(1)){
         update(path,flw);
         ansfl+=flw;
      }
   }
   cout<<ansfl<<"\n";
}
