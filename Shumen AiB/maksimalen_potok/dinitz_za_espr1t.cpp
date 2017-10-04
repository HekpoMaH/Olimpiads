#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
const int nmax=509;
const int mmax=1e4+9;
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
   cerr<<lvl[1]<<"\n";
   return lvl[1]!=-1;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   memset(head,-1,sizeof(head));
   input();
   //bfs();
   //cout<<bfs()<<"\n";
   cout<<bfs()<<"\n";
   cout<<lvl[1]<<"\n";
   //for(int i=head[6];i!=-1;i=e[i].nxt){
   //   cout<<6<<" "<<e[i].to<<" "<<e[i].fl<<"\n";
   //}

}
