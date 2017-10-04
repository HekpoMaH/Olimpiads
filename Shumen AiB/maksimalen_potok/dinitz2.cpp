#include<bits/stdc++.h>
using namespace std;
const int nmax=6009,mmax=70009,inf=1e9;
int n,m;
struct edge{
   int to,nxt,cap;
};
edge buf[mmax];
int vec[nmax],num=2,source,sink;
int lvl[nmax];
void addedge(int from,int to,int cap){
   buf[num].to=to;
   buf[num].cap=cap;
   buf[num].nxt=vec[from];
   vec[from]=num;
   num++;
}
bool bfs(){
   memset(lvl,-1,sizeof(lvl));
   queue<int> q;
   q.push(sink);
   lvl[sink]=0;
   while(!q.empty()){
      int cur=q.front();
      q.pop();
      for(int i=vec[cur];i>0;i=buf[i].nxt){
         if(lvl[buf[i].to]==-1&&buf[i^1].cap){
            lvl[buf[i].to]=lvl[cur]+1;
            q.push(buf[i].to);
         }
      }
   }
   return lvl[source]!=-1;
}
int dfs(int node,int flow){
   if(node==sink)return flow;
   for(int i=vec[node];i>0;i=buf[i].nxt){
      if(lvl[node]==lvl[buf[i].to]+1&&buf[i].cap){
         int f;
         if((f=dfs(buf[i].to,min(flow,buf[i].cap)))>0){
            buf[i].cap-=f;
            buf[i^1].cap+=f;
            return f;
         }
      }
   }
   lvl[node]=-5;
   return -1;
}
void dinitz(){
   long long flow=0;
   while(bfs()){
      long long f;
      while((f=dfs(source,inf))>0){
         flow+=f;
      }
   }
   cout<<flow<<"\n";
}
void read(){
   cin>>n>>m;
   for(int i=1;i<=m;i++){
      int x,y,z;
      cin>>x>>y>>z;
      addedge(x,y,z);
      addedge(y,x,0);
      addedge(y,x,z);
      addedge(x,y,0);
   }
   source=1;sink=n;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   dinitz();
}
