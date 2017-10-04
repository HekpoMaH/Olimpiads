#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define x first
#define y second
const int nmax=509;
const int vmax=1009;

const int rmax=6*1e5+9;
const int inf=1e9;
struct rib{
   int to,fl,prv;
   rib(){}
   rib(int _to, int _fl,int _prv){
      to=_to;
      fl=_fl;
      prv=_prv;
   }
};
int n,m,k;
pii sh[nmax];
pii kosh[nmax];
int dis[nmax][nmax];
int d[rmax],dlen;
int source,sink;
int idx[vmax],cpy[vmax];
int lvl[vmax];
rib g[rmax];
int sz;
inline int dist(pii a,pii b){
   return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
inline void init(){
   cin>>n>>m>>k;
   for(int i=1;i<=n;i++){
      cin>>sh[i].x>>sh[i].y;
   }
   for(int i=1;i<=m;i++){
      cin>>kosh[i].x>>kosh[i].y;
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         dis[i][j]=dist(sh[i],kosh[j]);
         d[++dlen]=dis[i][j];
      }
   }
   sort(d+1,d+dlen+1);
   source=0;
   sink=n+m+1;
}
inline void add(int a,int b,int c){
   g[sz]=rib(b,c,idx[a]);
   idx[a]=sz++;
   g[sz]=rib(a,0,idx[b]);
   idx[b]=sz++;
}
inline void build(int x){
   memset(idx,-1,sizeof(idx));
   sz=2;
   for(int i=1;i<=n;i++){
      add(source,i,1);
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         if(dis[i][j]<=x){
            add(i,n+j,1);
         }
      }
   }
   for(int i=1;i<=m;i++){
      add(i+n,sink,k);
   }
}
inline bool bfs(){
   queue<int> q;
   memset(lvl,-1,sizeof(lvl));
   q.push(sink);
   lvl[sink]=0;
   while(!q.empty()){
      int tmp=q.front();
      q.pop();
      //cout<<tmp<<"\n";
   //cout.flush();
      if(tmp==source)return true;
      for(int i=idx[tmp];i!=-1;i=g[i].prv){
         //cout<<"i="<<i<<"\n";
   //cout.flush();
         if(lvl[g[i].to]==-1&&g[i^1].fl){
            lvl[g[i].to]=lvl[tmp]+1;
            q.push(g[i].to);
         }
      }
   }
   return lvl[source]!=-1;
}
inline int dfs(int cur,int flow){
   if(cur==sink)
      return flow;
   for(int &i=cpy[cur];i!=-1;i=g[i].prv){
      if(lvl[cur]-1==lvl[g[i].to]&&g[i].fl){
         int flo=dfs(g[i].to,min(flow,g[i].fl));
         if(flo){
            g[i].fl-=flo;
            g[i^1].fl+=flo;
            return flo;
         }
      }
   }
   lvl[cur]=-47;
   return 0;
}
inline int dinitz(){
   int maxflow=0,curflow;
   while(bfs()){
      memcpy(cpy,idx,sizeof(idx));
      while((curflow = dfs(source,inf)))
         maxflow+=curflow;
   }
   return maxflow;
}
inline void solve(){
   int le=0,ri=dlen+1,mid;
   while(le+1<ri){
      mid=(le+ri)/2;
      build(d[mid]);
      cout.flush();
      if(dinitz()>=n){
         ri=mid;
      }
      else le=mid;
   }
   cout<<setiosflags(ios::fixed)<<setprecision(6)<<sqrt(d[ri])<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   init();
   solve();
}
