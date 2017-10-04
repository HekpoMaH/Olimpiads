//Heavy Light Decomposition
//1553 timus
#include<bits/stdc++.h>

using namespace std;
#define pb push_back
const int nmax=1e5+9;
const int tmax=1e5+9;
int n;
map<int,int> lazy[tmax];
map<int,int> mx[tmax];
bool used[nmax];
int lca[nmax][32];
struct nodeIntervalno{
   int tt,ll,rr,id;
   nodeIntervalno(){}
   nodeIntervalno(int T,int L,int R,int X){
      tt=T;ll=L,rr=R,id=X;
      lazy_update();
   }
   nodeIntervalno left(){
      return nodeIntervalno(tt,ll,(ll+rr)/2,id*2);
   }
   nodeIntervalno right(){
      return nodeIntervalno(tt,(ll+rr)/2+1,rr,id*2+1);
   }
   void lazy_update(){
      if(lazy[tt][id]==-1)return;
      if(ll!=rr){
         lazy[tt][id*2]+=lazy[tt][id];
         lazy[tt][id*2+1]+=lazy[tt][id];
      }
      mx[tt][id]+=lazy[tt][id];
      lazy[tt][id]=-1;
   }
   void assign_range(int t,int l,int r,int x){
      //cout<<t<<" "<<l<<" "<<r<<" "<<x<<"\n";
      //cout.flush();
      if(ll>r||l>rr)return;
      if(l<=ll&&rr<=r){
         lazy[tt][id]=x;
         lazy_update();
         return;
      }
      left().assign_range(t,l,r,x);
      right().assign_range(t,l,r,x);
      mx[tt][id]=max(mx[tt][id*2],mx[tt][id*2+1]);
   }
   int max_range(int t,int l,int r){
      if(ll>r||l>rr)return -1;
      if(l<=ll&&rr<=r)return mx[tt][id];
      int mx1=left().max_range(tt,l,r);
      int mx2=right().max_range(tt,l,r);
      return max(mx1,mx2);
   }
};
int blocksz;
struct nodeTree{
   vector<int> to;
   vector<bool> heavy;
   int par;
   bool parHeavy;
   int blockPar;
   int s;
   int block;
   int numInBlock;
   bool izlizaHeavy;
   int lvl;
};

nodeTree g[nmax];
nodeIntervalno rootIntervalno[tmax];
int szes[nmax];
void dfs(int node,int pare,int lev){
   g[node].s=1;
   g[node].par=pare;
   g[node].lvl=lev;
   used[node]=1;
   for(int i=0;i<g[node].to.size();i++){
      if(used[g[node].to[i]]==0){
         dfs(g[node].to[i],node,lev+1);
         g[node].s+=g[g[node].to[i]].s;
      }
   }
   //(v,c)
   //s[c]>=s[v]/2
   //s[v]<=2*s[c]
   for(int i=0;i<g[node].to.size();i++){
      if(g[node].to[i]!=pare&&g[node].s<=2*g[g[node].to[i]].s){
         g[node].heavy[i]=true;
         g[node].izlizaHeavy=true;
         g[g[node].to[i]].parHeavy=true;
      }
   }
}
int debu=0;
void decompose(int node,int bNum){
   int num=0;
   int node2=node;
   int bPar;
   do{
      //cout<<node<<"=node nxt="<<nxt<<" phv"<<g[node].parHeavy<<"\n";
      g[node].block=bNum;
      g[node].numInBlock=++num;
      szes[g[node].block]=max(szes[g[node].block],num);
      bPar=node;
      if(g[node].parHeavy==0)break;
      node=g[node].par;
   }while(1);
   node=node2;
   do{
      //cout<<node<<"=node nxt="<<nxt<<" phv"<<g[node].parHeavy<<"\n";
      g[node].blockPar=bPar;
      if(g[node].parHeavy==0)break;
      node=g[node].par;
      //cout<<node<<"\n";
      //if(debu==10)exit(0);
   }while(1);
}
void prepr(){
   memset(lca,-1,sizeof(lca));
   for(int i=1;i<=n;i++){
      lca[i][0]=g[i].par;
   }
   for(int j=1;1<<j<=n;j++){
      for(int i=1;i<=n;i++){
         if(lca[i][j-1]!=-1){
            lca[i][j]=lca[lca[i][j-1]][j-1];
         }
      }
   }
}
int getLCA(int p,int q){
   if(g[p].lvl<g[q].lvl){
      swap(p,q);
   }
   int lg;
   for(lg=1;1<<lg <=g[p].lvl;lg++);
   lg--;
   for(int i=lg;i>=0;i--){
      if(g[p].lvl-(1<<i)>=g[q].lvl)p=lca[p][i];
   }
   if(p==q)return p;
   for(int i=lg;i>=0;i--){
      if(lca[p][i]!=-1&&lca[p][i]!=lca[q][i]){
         p=lca[p][i];
         q=lca[q][i];
      }
   }
   return g[p].par;
}
int calc(int &p,int &q){
   int mx=0;
   cout<<"query is "<<p<<" "<<q<<"\n";
   while(g[p].block!=g[q].block){
      int posInTree=g[p].numInBlock;
      int lastPos=g[g[p].blockPar].numInBlock;
      cout<<p<<" "<<g[p].blockPar<<" "<<posInTree<<" "<<lastPos<<"\n";
      mx=max(mx,rootIntervalno[g[p].block].max_range(g[p].block,posInTree,lastPos));
      p=g[g[p].blockPar].par;
   }
   cout<<p<<" "<<g[p].blockPar<<" "<<g[p].numInBlock<<" "<<g[q].numInBlock<<"\n";
   mx=max(mx,rootIntervalno[g[p].block].max_range(g[p].block,g[p].numInBlock,g[q].numInBlock));
   cout<<"mx="<<mx<<"\n";
   return mx;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   //for(int i=1;i<tmax;i++)rootIntervalno[i]=nodeIntervalno(i,1,n,1);
   for(int i=1;i<n;i++){
      int a,b;
      cin>>a>>b;
      if(a>b)swap(a,b);
      g[a].to.pb(b);
      g[a].heavy.pb(0);
      g[b].to.pb(a);
      g[b].heavy.pb(0);
      //g[b].par=a;
   }
   g[1].par=-1;
   g[1].parHeavy=false;
   dfs(1,-1,1);
   //for(int i=1;i<=n;i++){
   //   for(int j=0;j<g[i].to.size();j++){
   //      if(g[i].heavy[j]){
   //         cout<<i<<"-----heavy-----"<<g[i].to[j]<<"\n";
   //      }
   //   }
   //}
   for(int i=1;i<=n;i++){
      //cout<<i<<" "<<g[i].par<<"\n";
      if(g[i].izlizaHeavy==0){
         //cout<<"starti "<<i<<" "<<blocksz+1<<"\n";
         decompose(i,++blocksz);
      }
   }
   prepr();
   //for(int i=1;i<=n;i++){
   //   cout<<"vertex: "<<i<<" -> "<<g[i].block<<" "<<g[i].numInBlock<<" "<<g[i].blockPar<<"\n";
   //}
   for(int i=1;i<=blocksz;i++)rootIntervalno[i]=nodeIntervalno(i,1,szes[i],1);
   int qnum;
   cin>>qnum;
   for(int i=1;i<=qnum;i++){
      char ch;
      int a,b;
      cin>>ch>>a>>b;
      if(ch=='I'){
         int posInTree=g[a].numInBlock;
         int lastPos=g[g[a].blockPar].numInBlock;
         rootIntervalno[g[a].block].assign_range(g[a].block,posInTree,posInTree,b);
         //cout<<a<<" "<<g[a].block<<" "<<posInTree<<" "<<lastPos<<"\n";
         continue;
      }
      if(g[a].lvl>g[b].lvl)swap(a,b);
      int l=getLCA(a,b);
      int mx=0;
      if(a!=l&&b!=l){
         mx=max(mx,calc(a,l));
         mx=max(mx,calc(b,l));
         int posInTree=g[l].numInBlock;
      }
      else {
         mx=0;
         int lasb=b;
         mx=max(mx,calc(b,l));
         int posInTree=g[l].numInBlock;
         //cout<<b<<" "<<g[l].block<<" "<<g[b].numInBlock<<" "<<posInTree<<"\n";
      }
      cout<<mx<<"\n";
   }
}
//3 3 3 2 5
//0 0 0 0 0