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
double xx[nmax],yy[nmax];
double s,v;
void read(){
   //n1-jivotni
   //n2-dupki
   for(int i=1;i<=n1;i++){
      cin>>xx[i]>>yy[i];
   }
   for(int i=1;i<=n2;i++){
      double xxx,yyy;
      cin>>xxx>>yyy;
      for(int j=1;j<=n1;j++){
         double dist=(double)(xxx-xx[j])*(double)(xxx-xx[j])+(double)(yyy-yy[j])*(double)(yyy-yy[j]);
         if(sqrt(dist)<=s*v){
            addedge(j,n1+i,1);
            addedge(n1+i,j,0);
         }
      }
   }
   source=n1+n2+2;sink=n1+n2+3;
   for(int i=1;i<=n1;i++){
      addedge(source,i,1);
      addedge(i,source,0);
   }
   for(int i=1;i<=n2;i++){
      addedge(n1+i,sink,1);
      addedge(sink,n1+i,0);
   }
}
int bfs()
{
    int i,j,sz;
    static int q[509];
    memset(lvl,-1,sizeof(lvl));
    q[sz=0]=sink;
    lvl[sink]=0;
    for(i=0;i<=sz;i++)
    {
        for(j=vec[q[i]];j>0;j=buf[j].nxt)
        {
            if(lvl[buf[j].to]==-1&&buf[j^1].cap)
            {
                lvl[buf[j].to]=lvl[q[i]]+1;
                q[++sz]=buf[j].to;
            }
        }
    }
    return lvl[source]!=-1;
}
int dfs(int x,int flow)
{
    //cout<<x<<" flow= "<<flow<<" "<<vec[x]<<" "<<nxt[vec[x]]<<endl;
    //exit(0);
    if(x==sink){return flow;}
    int i;
    //cout<<"i="<<vec[x]<<endl;
    for(i=vec[x];i>0;i=buf[i].nxt)
    {
        if(buf[i].cap&&lvl[buf[i].to]+1==lvl[x])
        {
            //cout<<"going to "<<to[i]<<" with capacity "<<cap[i]<<" and the flow is "<<min(flow,cap[i])<<endl;
            //exit(0);
            int y=dfs(buf[i].to,min(flow,buf[i].cap));
            if(y!=-1)
            {
                //cout<<"Y here ="<<y<<endl;
                buf[i].cap-=y;
                buf[i^1].cap+=y;
                return y;
            }
        }
        
    }
    //cout<<"returned\n";
    lvl[x]=-5;
    return -1;
}
long long dinitz()
{
    long long maxflow=0,floww;
    while(bfs())
    {
        floww=dfs(source,(1<<30));
        while( floww!=-1)assert(floww==1),maxflow+=floww,floww=dfs(source,(1<<30));

        //for(int i=1;i<=n;i++)if(lvl[i]==-5){cout<<"EEE"<<endl;exit(0);}
    }
    return maxflow;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   while(cin>>n1>>n2>>s>>v){
      memset(vec,0,sizeof(vec));
      num=2;
      read();
      cout<<(n1-dinitz())<<"\n";
   }
}
