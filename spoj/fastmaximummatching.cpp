#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9,mmax=4e5+9,inf=1e9;
int n1,n2,m;
struct edge{
   int to,nxt,cap;
};
edge buf[mmax];
int br;
int vec[nmax],num=2,cur[nmax],source,sink;
int lvl[nmax];
int path[nmax],pathlen;
void addedge(int from,int to,int cap){
   buf[num].to=to;
   buf[num].cap=cap;
   buf[num].nxt=vec[from];
   vec[from]=num;
   num++;
}
void read(){
   cin>>n1>>n2>>m;
   for(int i=1;i<=m;i++){
      int x,y,z;
      cin>>x>>y;
      addedge(x,n1+y,1);
      addedge(n1+y,x,0);
   }
   source=n1+n2+2;sink=n1+n2+1;
   for(int i=1;i<=n1;i++){
      addedge(source,i,1);
      addedge(i,source,0);
   }
   for(int i=1;i<=n2;i++){
      addedge(n1+i,sink,1);
      addedge(sink,n1+i,0);
   }
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
         //cout<<"("<<cur<<","<<buf[i].nxt<<","<<buf[i^1].cap<<") ";
         if(lvl[buf[i].to]==-1&&buf[i^1].cap){
            lvl[buf[i].to]=lvl[cur]+1;
            q.push(buf[i].to);
         }
      }
   }
   return lvl[source]!=-1;
}
int dfs(int node){
   //cout<<"node="<<node<<"\n";
   br++;
   //if(br==6)exit(0);
   if(node==sink)return inf;
   for(int i=cur[node];i>0;i=cur[node]=buf[i].nxt){
      //cout<<buf[i].to<<" "<<buf[i].cap<<" "<<lvl[node]<<" "<<lvl[buf[node].to]<<"\n";
      cout.flush();
      if(lvl[buf[i].to]==lvl[node]-1&&buf[i].cap>0){
         path[pathlen++]=i;
         int tmp;
         if((tmp=dfs(buf[i].to))>0){
            return min(tmp,buf[i].cap);
         }
         pathlen--;
      }
   }
   //cout<<"returned 0\n";
   return 0;
}
void updategraph(int fl){
   //cout<<"pahlen="<<pathlen<<"\n";
   //exit(0);
   for(int i=0;i<pathlen;i++){
      buf[path[i]].cap-=fl;
      buf[path[i]^1].cap+=fl;
   }
}
void dinitz(){
   int flow=0;
   //for(int i=vec[7];i>0;i=buf[i].nxt){
   //   cout<<buf[i].to<<" "<<buf[i].cap<<"\n";
   //}
   //exit(0);
   while(bfs()){
      copy(vec+1,vec+n1+n2+3,cur+1);
      int ff;
      while(pathlen=0,ff=dfs(source)>0){
         flow+=ff;
         //cout<<"found"<<"\n";
         cout.flush();
         updategraph(ff);
      }
      //cout<<lvl[source]<<"<-\n";
   }
   cout<<flow<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   dinitz();
}
