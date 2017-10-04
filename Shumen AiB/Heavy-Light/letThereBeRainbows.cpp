#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6;
map<string,int> color;
#define pb push_back
struct nodeTree{
   //int idOfColor;//-1 if still not entirely colored
   int st,end;
   int lazy[9];
   int allColors[9];
   nodeTree *lef,*righ;
};
nodeTree *d[nmax];
void buildTree(int l,int r,nodeTree *root){
   //cout<<l<<" "<<r<<endl;
   root->st=l;
   root->end=r;
   for(int i=1;i<=7;i++){
      root->lazy[i]=0;
      root->allColors[i]=0;
   }
   if(l==r)return;
   if(root->lef==NULL)root->lef=new nodeTree;
   buildTree(l,(l+r)/2,root->lef);
   if(root->righ==NULL)root->righ=new nodeTree;
   buildTree((l+r)/2+1,r,root->righ);
}
void delTree(int l,int r,nodeTree *&root){
   //cout<<l<<" "<<r<<endl;
   root->st=l;
   root->end=r;
   for(int i=1;i<=7;i++){
      root->lazy[i]=0;
      root->allColors[i]=0;
   }
   if(l==r){
      delete root;
      root=NULL;
      return;
   }
   delTree(l,(l+r)/2,root->lef);
   delTree((l+r)/2+1,r,root->righ);
   delete root;
   root=NULL;
   assert(root==NULL);
}
void checkLazy(int l,int r,nodeTree *root){
   int toCol=-1;
   for(int i=1;i<=7;i++){
      if(root->lazy[i]!=0)toCol=i;
   }
   //cout<<l<<" "<<r<<" has lazy "<<toCol<<"\n";
   if(toCol!=-1){
      for(int i=1;i<=7;i++){
         root->lazy[i]=0;
         root->allColors[i]=0;
      }
      root->allColors[toCol]=(r-l+1);
      if(l!=r){
         for(int i=1;i<=7;i++){
            root->lef->lazy[i]=0;
         }
         root->lef->lazy[toCol]=1;
         for(int i=1;i<=7;i++){
            root->righ->lazy[i]=0;
         }
         root->righ->lazy[toCol]=1;
      }
   }
}
int cntCol(int l,int r,int ql,int qr,int col,nodeTree *root){
   //for(int i=1;i<=inter;i++)cout<<" ";
   //cout<<l<<" "<<r<<" "<<ql<<" "<<qr<<" "<<root->allColors[col]<<"\n";
   checkLazy(l,r,root);
   if(qr<l||r<ql)return 0;
   if(ql<=l&&r<=qr)return root->allColors[col];
   int xx,yy;
   if(l!=r){
      xx=cntCol(l,(l+r)/2,ql,qr,col,root->lef);
      yy=cntCol((l+r)/2+1,r,ql,qr,col,root->righ);
      for(int i=1;i<=7;i++){
         root->allColors[i]=root->lef->allColors[i]+root->righ->allColors[i];
      }
   }
   //for(int i=1;i<=inter;i++)cout<<" ";
   //cout<<"x"<<l<<" "<<r<<" "<<ql<<" "<<qr<<" "<<root->allColors[col]<<"\n";
   return xx+yy;
}
void updCol(int l,int r,int ql,int qr,int col,nodeTree *root){
   //cout<<l<<" "<<r<<" "<<ql<<" "<<qr<<"\n";
   checkLazy(l,r,root);
   if(qr<l||r<ql)return;
   if(ql<=l&&r<=qr){
      //cout<<"UPDATED\n";
      for(int i=1;i<=7;i++)root->allColors[i]=0;
      root->allColors[col]=r-l+1;
      if(l!=r){
         for(int i=1;i<=7;i++){
            root->lef->lazy[i]=0;
         }
         root->lef->lazy[col]=1;
         for(int i=1;i<=7;i++){
            root->righ->lazy[i]=0;
         }
         root->righ->lazy[col]=1;
      }
      return;
   }
   if(l!=r){
      updCol(l,(l+r)/2,ql,qr,col,root->lef);
      updCol((l+r)/2+1,r,ql,qr,col,root->righ);
      for(int i=1;i<=7;i++){
         root->allColors[i]=0;
      }
      for(int i=1;i<=7;i++){
         root->allColors[i]=root->lef->allColors[i]+root->righ->allColors[i];
      }
   }
}
struct nodeGraph{
   vector<int> to;
   vector<bool> heavy;
   int s;
   bool izlizaHeavy;
   bool parHeavy;
   int block;
   int numInBlock;
   int blockPar;
   int par;
   int lvl;
};
int szes[nmax];
nodeGraph g[nmax];
int n;
void dfs(int node,int par,int lvl){
   //cout<<node<<" - "<<par<<" - "<<lvl<<"\n";
   g[node].par=par;
   g[node].lvl=lvl;
   g[node].s=1;
   for(int i=0;i<(int)g[node].to.size();i++){
      if(g[node].to[i]==par)continue;
      dfs(g[node].to[i],node,lvl+1);
      g[node].s+=g[g[node].to[i]].s;
   }
   for(int i=0;i<(int)g[node].to.size();i++){
      if(g[node].to[i]==par)continue;
      //cout<<node<<" "<<g[node].to[i]<<" "<<g[node].s<<" "<<g[g[node].to[i]].s<<"\n";
      if(g[g[node].to[i]].s*2>=g[node].s){
         g[node].heavy[i]=1;
         g[node].izlizaHeavy=1;
         g[g[node].to[i]].parHeavy=1;
      }
   }
}
void decompose(int node,int block){
   int curNode=node;
   int br=0;
   int bPar=curNode;
   for(;;){
      //cout<<curNode<<" "<<g[curNode].parHeavy<<" "<<g[curNode].par<<"\n";
      g[curNode].block=block;
      g[curNode].numInBlock=++br;
      bPar=curNode;
      if(!g[curNode].parHeavy)break;
      curNode=g[curNode].par;
      //cout<<"nwnode is "<<curNode<<"\n";

   }
   //cout<<node<<" a"<<block<<" r"<<bPar<<"\n";
   //cout<<"----------------\n";
   szes[block]=br;
   for(;;){
      g[node].blockPar=bPar;
      //cout<<node<<" a"<<block<<" r"<<bPar<<"\n";
      if(!g[node].parHeavy)break;
      node=g[node].par;
   }
}
int lca[nmax][34];
void precomputeLCA(){
   memset(lca,-1,sizeof(lca));
   for(int i=0;i<n;i++){
      lca[i][0]=g[i].par;
   }
   for(int j=1;j<=33;j++){
      for(int i=0;i<n;i++){
         if(lca[i][j-1]!=-1){
            lca[i][j]=lca[lca[i][j-1]][j-1];
         }
      }
   }
}
int getLCA(int p,int q){
   if(g[p].lvl<g[q].lvl)swap(p,q);
   //p lvl > q lvl
   int debu=0;
   for(int j=33;j>=0;j--){
      int a=lca[p][j];
      //cout<<j<<" "<<p<<" "<<a<<"\n";
      if(a!=-1&&g[a].lvl>=g[q].lvl){
         p=a;
         a=lca[p][j];
      }
   }
   //cout<<p<<" "<<q<<"\n";
   //cout.flush();
   if(p==q)return p;
   for(int j=33;j>=0;j--){
      int a=lca[p][j];
      int b=lca[q][j];
      if(a!=-1&&a!=b){
         p=a;
         q=b;
      }
   }
   return g[p].par;
}
int calc(int p,int q,int idxCol){
   int br=0;
   while(g[p].block!=g[q].block){
      int bPar=g[p].blockPar;
      //cout<<"blocks-> "<<g[p].block<<" "<<g[q].block<<" bPar="<<bPar<<"\n";
      //cout<<1<<" "<<szes[g[p].block]<<" "<<g[p].numInBlock<<" "<<g[bPar].numInBlock<<" "<<idxCol<<"\n";
      //cout.flush();
      br+=cntCol(1,szes[g[p].block],g[p].numInBlock,g[bPar].numInBlock,idxCol,d[g[p].block]);
      p=g[bPar].par;
   }
   if(g[p].numInBlock<g[q].numInBlock){
      br+=cntCol(1,szes[g[p].block],g[p].numInBlock,g[q].numInBlock-1,idxCol,d[g[p].block]);
   }
   return br;
}
void updColTree(int p,int q,int idxCol){
   while(g[p].block!=g[q].block){
      int bPar=g[p].blockPar;
      updCol(1,szes[g[p].block],g[p].numInBlock,g[bPar].numInBlock,idxCol,d[g[p].block]);
      p=g[bPar].par;
   }
   if(g[p].numInBlock<g[q].numInBlock){
      updCol(1,szes[g[p].block],g[p].numInBlock,g[q].numInBlock-1,idxCol,d[g[p].block]);
   }
}
void solve(){
   cin>>n;
   for(int i=0;i<n;i++){
      g[i].to.clear();
      g[i].numInBlock=-1;
      g[i].block=-1;
      g[i].blockPar=-1;
      g[i].lvl=0;
      g[i].izlizaHeavy=g[i].parHeavy=0;
      g[i].s=0;
   }
   for(int i=1;i<n;i++){
      int a,b;
      cin>>a>>b;
      g[a].to.pb(b);
      g[b].to.pb(a);
   }
   g[1].par=-1;
   for(int i=0;i<n;i++){
      g[i].heavy.resize(g[i].to.size());
   }
   dfs(0,-1,1);
   int br=0;
   for(int i=0;i<n;i++){
      if(!g[i].izlizaHeavy)decompose(i,++br);
   }
   precomputeLCA();
   for(int i=0;i<n;i++){
      //cout<<i<<"-> ";cout<<g[i].block<<" "<<g[i].numInBlock<<" "<<g[i].blockPar<<"\n";
   }
   for(int i=1;i<=br;i++){
      d[i]=new nodeTree;
      buildTree(1,szes[i],d[i]);
   }
   //for(int i=0;i<n;i++){
   //   cout<<i<<"-> ";
   //   for(int j=0;j<(int)g[i].to.size();j++)
   //      cout<<"("<<g[i].to[j]<<","<<g[i].heavy[j]<<") ";
   //   cout<<"\n";
   //}
   int q;
   cin>>q;
   for(int i=1;i<=q;i++){
      int a,b;
      string col;
      cin>>a>>b>>col;
      assert(color[col]>=1&&color[col]<=7);
      if(g[a].lvl<g[b].lvl)swap(a,b);
      int l=getLCA(a,b);
      //cout<<"LCA is "<<l<<" a="<<a<<" b="<<b<<"\n";
      if(b==l){
         cout<<g[a].lvl-g[b].lvl-calc(a,b,color[col])<<"\n";
         updColTree(a,b,color[col]);
      }
      else{
         cout<<g[a].lvl-g[l].lvl+g[b].lvl-g[l].lvl-(calc(a,l,color[col])+calc(b,l,color[col]))<<"\n";
         updColTree(a,l,color[col]);
         updColTree(b,l,color[col]);
      }
      //cout.flush();
   }
   for(int i=1;i<=br;i++){
      delTree(1,szes[i],d[i]);
      assert(d[i]==NULL);
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   color["red"]=1;
   color["orange"]=2;
   color["yellow"]=3;
   color["green"]=4;
   color["blue"]=5;
   color["indigo"]=6;
   color["violet"]=7;
   int T;
   cin>>T;
   for(int i=1;i<=T;i++){
      cout<<"TEST "<<i<<"\n";
      cout.flush();
      solve();
   }
}
