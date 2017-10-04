#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+9;
#define pb push_back
int n;
int blocksz;
map<int,int> lazy[nmax];
map<int,int> mx[nmax];
int lca[nmax][32];
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
struct nodeIntervalno{
   int tt,ll,rr,id;
   nodeIntervalno(){}
   nodeIntervalno(int _tt,int _ll,int _rr,int _id){
      tt=_tt;ll=_ll;rr=_rr;id=_id;
      lazy_update();
   }
   nodeIntervalno left(){
      return nodeIntervalno(tt,ll,(ll+rr)/2,id*2);
   }
   nodeIntervalno right(){
      return nodeIntervalno(tt,(ll+rr)/2+1,rr,id*2+1);
   }
   void lazy_update(){
      if(lazy[tt][id]==-1){
         return;
      }
      if(ll!=rr){
         lazy[tt][id*2]+=lazy[tt][id];
         lazy[tt][id*2+1]+=lazy[tt][id];
      }
      mx[tt][id]+=lazy[tt][id];
      lazy[tt][id]=-1;
   }
   void assign_range(int t,int l,int r,int x){
      if(l>rr||ll>r){
         return;
      }
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
      if(l>rr||ll>r){
         return -1;
      }
      if(l<=ll&&rr<=r){
         return mx[tt][id];
      }
      int mx1=left().max_range(t,l,r);
      int mx2=right().max_range(t,l,r);
      return max(mx1,mx2);
   }
};
nodeTree g[nmax];
nodeIntervalno rootIntervalno[nmax];
bool used[nmax];
int szes[nmax];
void read(){
   cin>>n;
   for(int i=1;i<n;i++){
      int a,b;
      cin>>a>>b;
      g[a].to.pb(b);
      g[b].to.pb(a);
      g[a].heavy.pb(0);
      g[b].heavy.pb(0);
   }
   g[1].par=-1;
   g[1].parHeavy=false;
}
void dfs(int node,int pare,int lev){
   used[node]=1;
   g[node].s=1;
   g[node].par=pare;
   g[node].lvl=lev;
   for(int i=0;i<(int)g[node].to.size();i++){
      if(!used[g[node].to[i]]){
         dfs(g[node].to[i],node,lev+1);
         g[node].s+=g[g[node].to[i]].s;
      }
   }
   for(int i=0;i<(int)g[node].to.size();i++){
      if(g[node].to[i]!=g[node].par&&2*g[g[node].to[i]].s>=g[node].s){
         g[node].heavy[i]=true;
         g[node].izlizaHeavy=true;
         g[g[node].to[i]].parHeavy=true;
      }
   }
}
void decompose(int node,int bNum){
   int num=0;
   int node2=node;
   int bPar;
   while(1){
      g[node].block=bNum;
      g[node].numInBlock=++num;
      szes[g[node].block]=max(szes[g[node].block],num);
      bPar=node;
      if(g[node].parHeavy==0)break;
      node=g[node].par;
   }
   node=node2;
   while(1){
      g[node].blockPar=bPar;
      if(g[node].parHeavy==0)break;
      node=g[node].par;
   }
}
void precompute(){
   for(int i=1;i<=n;i++){
      lca[i][0]=g[i].par;
   }
   for(int j=1;1<<j <=n;j++){
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
   for(lg=1;(1<<lg)<=n;lg++);
   lg--;
   for(int i=lg;i>=0;i--){
      if(g[p].lvl-(1<<i)>=g[q].lvl)p=lca[p][i];
   }
   if(p==q)return p;
   for(int i=lg;i>=0;i--){
      if(lca[p][i]!=lca[q][i]&&lca[p][i]!=-1){
         p=lca[p][i];
         q=lca[q][i];
      }
   }
   return g[p].par;
}
int calc(int &p,int &q){
   int mx=0;
   while(g[p].block!=g[q].block){
      int posInTree=g[p].numInBlock;
      int lastPos=g[g[p].blockPar].numInBlock;
      mx=max(mx,rootIntervalno[g[p].block].max_range(g[p].block,posInTree,lastPos));
      p=g[g[p].blockPar].par;
   }
   mx=max(mx,rootIntervalno[g[p].block].max_range(g[p].block,g[p].numInBlock,g[q].numInBlock));
   return mx;

}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   dfs(1,-1,1);
   for(int i=1;i<=n;i++){
      if(!g[i].izlizaHeavy){
         decompose(i,++blocksz);
      }
   }
   precompute();
   for(int i=1;i<=blocksz;i++){
      rootIntervalno[i]=nodeIntervalno(i,1,szes[i],1);
   }
   int qnum;
   cin>>qnum;
   for(int i=1;i<=qnum;i++){
      char ch;
      int a,b;
      cin>>ch>>a>>b;
      if(ch=='I'){
         int posInTree=g[a].numInBlock;
         int lastPos=g[g[a].blockPar].numInBlock;
         rootIntervalno[g[a].block].assign_range(g[a].block,posInTree,lastPos,b);
         continue;
      }
      if(g[a].lvl>g[b].lvl)swap(a,b);
      int mx=0;
      int l=getLCA(a,b);
      if(a!=l&&b!=l){
         mx=max(mx,calc(a,l));
         mx=max(mx,calc(b,l));
      }
      else{
         mx=max(mx,calc(b,l));
      }
      cout<<mx<<"\n";
   }
}
