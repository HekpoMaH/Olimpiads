/*
Led to the river
Midsummer I wave
A 'V' of black swans
On with hope to the grave

And through red September
When skies fire-paved
I begged you appear
Like a thorn for the holy ones

Cold was my soul
Untold was the pain
I faced, when you left me
A rose in the rain

So I swore to the razor
That never, enchained
Would your dark nails of faith
Be pushed through my veins again

Bared on your tomb
I am a prayer for your loneliness
And would you ever soon
Come above unto me?

For once upon a time
From the binds of your loneliness
I could always find
The right slot for your sacred key

Six feet deep is the incision
In my heart that barless prison
Discolors all with tunnel vision
Sunsetter, nymphetamine

Sick and weak from my condition
This lust, this vampiric addiction
To her alone in full submission
None better, nymphetamine

Wracked with your charm, I'm circled like prey
Back in the forest where whispers persuade
More sugar trails, more white lady laid
Than pillars of salt

 */
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int nmax=(2.5*1e5)+9;
const int inf=1e9;
int n;
int active[nmax];
int used[nmax];
vector<pair<int,int> > edges[nmax];
vector<pair<int,int> >intaresni[nmax];
int level[nmax];
int lca[nmax][33];
int parent[nmax];
int br[nmax];
void dfszainteresni(int par,int node){
   if(used[node]==1)br[node]++;
   for(int i=0;i<(int)edges[node].size();i++){
      if(edges[node][i].fi==par)continue;
      dfszainteresni(node,edges[node][i].fi);
      br[node]+=br[edges[node][i].fi];
   }
}
void dfsprep(int par,int levl,int node){
   parent[node]=par;
   level[node]=levl;
   for(int i=0;i<(int)edges[node].size();i++){
      if(edges[node][i].fi==par)continue;
      dfsprep(node,levl+1,edges[node][i].fi);
   }
}
void makelca(){
   memset(lca,-1,sizeof(lca));
   for(int i=1;i<=n;i++)lca[i][0]=parent[i];
   for(int j=0;(1<<j)<=n;j++){
      for(int i=1;i<=n;i++){
         if(lca[i][j-1]!=-1){
            lca[i][j]=lca[lca[i][j-1]][j-1];
         }
      }
   }
}
int query(int p,int q){
   int log;
   if(level[p]<level[q])swap(p,q);
   for(log=1;1<<log<=level[p];log++);
   log--;
   for(int i=log;i>=0;i--){
      if(level[p]-(1<<i)>=level[q])p=lca[p][i];
   }
   if(p==q)return p;
   for(int i=log;i>=0;i--){
      if(lca[p][i]!=-1&&lca[p][i]!=lca[q][i])
         p=lca[p][i],q=lca[q][i];
   }
   return parent[p];
}
int dfs(int at,int par){
   if(used[at]){
      return inf;
   }
   int res=0;
   for(int i=0;i<(int)intaresni[at].size();i++){
      int nxt=intaresni[at][i].fi;
      if(nxt==par)
         continue;
      int cres=dfs(nxt,at);
      if(cres>intaresni[at][i].se)
         cres=intaresni[at][i].se;
      res+=cres;
   }
   return res;
}
void compress(int par,int lastinteresting,int node,int mn){
   int nwinteresting=lastinteresting;
   //cout<<lastinteresting<<" "<<node<<" "<<mn<<" "<<used[node]<<"\n";
   //cout.flush();
   if(used[node]==1){
      nwinteresting=node;
      //cout<<"ENTERED1\n";
      if(lastinteresting!=node){
         //cout<<"ENTERED2\n";
         intaresni[lastinteresting].pb(mp(node,mn));
         intaresni[node].pb(mp(lastinteresting,mn));
      }
      mn=inf;
   }
   for(int i=0;i<(int)edges[node].size();i++){
      if(par==edges[node][i].first)continue;
      compress(node,nwinteresting,edges[node][i].first,min(mn,edges[node][i].second));
   }
}
void printintaresni(int par,int node){
   cout<<node<<"\n";
   for(int i=0;i<(int)intaresni[node].size();i++){
      int nxt=intaresni[node][i].fi;
      if(nxt==par)
         continue;
      printintaresni(node,nxt);
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<n;i++){
      int x,y,z;
      cin>>x>>y>>z;
      edges[x].pb(mp(y,z));
      edges[y].pb(mp(x,z));
   }
   dfsprep(-1,0,1);
   makelca();
   //cout<<query(8,9)<<" "<<query(6,9)<<" "<<query(7,8)<<" "<<query(5,6)<<" "<<query(3,5)<<"\n";
   //exit(0);
   int queries;
   cin>>queries;
   while(queries--){
      int root;
      cin>>root;
      int cnt;
      cin>>cnt;
      memset(used,0,sizeof(used));
      for(int i=1;i<=cnt;i++){
         cin>>active[i];
         used[active[i]]=1;
      }
      memset(br,0,sizeof(br));
      dfszainteresni(-1,root);
      for(int i=1;i<=cnt;i++){
         if(br[i]>1)used[i]=1;
      }
      used[root]=0;
      //for(int i=1;i<=n;i++)cout<<used[i];
      //cout<<"\n";
      //exit(0);
      intaresni[root].clear();
      for(int i=1;i<=cnt;i++){
         intaresni[i].clear();
      }
      compress(-1,root,root,inf);
      //assert(intaresni[root].size()>=1);
      //printintaresni(-1,root);
      for(int i=1;i<=n;i++){
         cout<<i<<"-> ";
         for(int j=0;j<(int)intaresni[i].size();j++){
            cout<<"("<<intaresni[i][j].fi<<","<<intaresni[i][j].se<<") ";
         }
         cout<<"\n";
      }
      cout<<dfs(root,-1)<<"\n";
      //exit(0);
   }
}
