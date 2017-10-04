#include<bits/stdc++.h>
#define pb push_back
using namespace std;
struct marsh{
   int n1,n2,profit;
   marsh(){}
   marsh(int _n1,int _n2,int _profit){
      n1=_n1;
      n2=_n2;
      profit=_profit;
   }
};
struct events{
   int l1,l2,r1,r2;
   int profit;
   events(){}
   events(int _l1,int _r1,int _l2,int _r2,int _profit){
      l1=_l1;
      r1=_r1;
      l2=_l2;
      r2=_r2;
      profit=_profit;
   }
};
const int nmax=5*1e5+9;
marsh paths[nmax];
int n,m;
int leafn=0;
vector<int> g[nmax];
vector<int> child[nmax];
void read(){
   cin>>n;
   int a,b,c;
   for(int i=1;i<n;i++){
      cin>>a>>b;
      g[a].pb(b);
      g[b].pb(a);
   }
   for(int i=1;i<=n;i++){
      sort(g[i].begin(),g[i].end());
   }
   cin>>m;
   for(int i=1;i<=m;i++){
      cin>>a>>b>>c;
      paths[i]=marsh(a,b,c);
   }
}
pair<int,int> leaf[nmax];
int revl[nmax];
int used[nmax];
void enum_leafs(int node){
   used[node]=1;
   if(g[node].size()==1&&used[g[node][0]]==1){
      leaf[node].first=leaf[node].second=++leafn;
      revl[leafn]=node;
      return;
   }
   int mn=n+1,mx=-1;
   for(int i=0;i<g[node].size();i++){
      if(used[g[node][i]]==0){
         enum_leafs(g[node][i]);
         mn=min(mn,leaf[g[node][i]].first);
         mx=max(mx,leaf[g[node][i]].second);
         child[node].pb(g[node][i]);
      }
   }
   leaf[node].first=mn;
   leaf[node].second=mx;
}
vector<events> eve,eve2;

int findK(int B,int A){
   int l=-1,r=child[B].size();
   int mid;
   while(l+1<r){
      mid=(l+r)/2;
      int cur=child[B][mid];
      if(leaf[child[B][mid]].first<=leaf[A].first&&leaf[A].second<=leaf[child[B][mid]].second){
         return cur;
      }
      if(leaf[cur].first>leaf[A].first)r=mid;
      else if(leaf[cur].second<leaf[A].second)l=mid;
   }
   return r;
}
void make_rects(){
   int A,B;
   for(int i=1;i<=m;i++){
      A=paths[i].n1,B=paths[i].n2;
      int La=leaf[A].first,Ra=leaf[A].second;
      int Lb=leaf[B].first,Rb=leaf[B].second;
      //cout<<"La="<<La<<" Ra="<<Ra<<" Lb="<<Lb<<" Rb="<<Rb<<"\n";
      //cout<<"diffB="<<Rb-Lb+1<<" diffA="<<Ra-La+1<<"\n";
      if(Rb-Lb+1<Ra-La+1){
         swap(A,B);
         La=leaf[A].first,Ra=leaf[A].second;
         Lb=leaf[B].first,Rb=leaf[B].second;
      }
      if(!(leaf[B].first<=leaf[A].first&&leaf[A].second<=leaf[B].second)){
         /*
          * La~Ra X Lb-Rb
          */
         if(La<Lb){
            eve.pb(events(La,Lb,La,Rb,paths[i].profit));
            eve2.pb(events(Ra,Lb,Ra,Rb,-paths[i].profit));
         }
         else{
            eve.pb(events(Lb,La,Lb,Ra,paths[i].profit));
            eve2.pb(events(Rb,La,Rb,Ra,-paths[i].profit));
         }
      }
      else{
         int K=findK(B,A);
         /*
          * La~Ra X 1~Lk-1
          * La~Ra X Rk+1~leafn
          */
         int Lk=leaf[K].first,Rk=leaf[K].second;
         //cout<<"A="<<A<<" B="<<B<<" K="<<K<<"\n";
         //cout<<"La="<<La<<" Ra="<<Ra<<" Lb="<<Lb<<" Rb="<<Rb<<"\n";
         //cout<<"Lk="<<Lk<<" Rk="<<Rk<<" La="<<La<<" Ra="<<Ra<<"\n";
         //cout.flush();
         //assert(Lk<=La&&Ra<=Rk);
         int LLa,LLb,RRa,RRb;
         if(Lk-1>=1){
            LLa=La,LLb=1,RRb=Lk-1;
            RRa=Ra;
            if(LLa<LLb){
               eve.pb(events(LLa,LLb,LLa,RRb,paths[i].profit));
               eve2.pb(events(RRa,LLb,RRa,RRb,-paths[i].profit));
            }
            else{
               eve.pb(events(LLb,LLa,LLb,RRa,paths[i].profit));
               eve2.pb(events(RRb,LLa,RRb,RRa,-paths[i].profit));
            }
         }
         if(Rk+1<=leafn){
            LLa=La,LLb=Rk+1,RRb=leafn,RRa=Ra;
            if(LLa<LLb){
               eve.pb(events(LLa,LLb,LLa,RRb,paths[i].profit));
               eve2.pb(events(RRa,LLb,RRa,RRb,-paths[i].profit));
            }
            else{
               eve.pb(events(LLb,LLa,LLb,RRa,paths[i].profit));
               eve2.pb(events(RRb,LLa,RRb,RRa,-paths[i].profit));
            }
         }
      }
   }
}
int lazy[nmax*5],mx[nmax*5],idx[nmax*5];
struct node{
   int ll,rr,id;
   node(int L,int R,int X){
      ll=L;
      rr=R;
      id=X;
      lazy_update();
   }
   node left(){
      return node(ll,(ll+rr)/2,id*2);
   }
   node right(){
      return node((ll+rr)/2+1,rr,id*2+1);
   }
   void lazy_update(){
      assert(id<=nmax*5);
      if(lazy[id]==0)return;
      mx[id]+=lazy[id];
      if(ll!=rr){
         lazy[id*2]+=lazy[id];
         lazy[id*2+1]+=lazy[id];
      }
      lazy[id]=0;
   }
   void assign_range(int l,int r,int x){
      assert(id<=nmax*5);
      lazy_update();
      if(ll>r||l>rr)return;
      if(ll==rr){
         idx[id]=ll;
      }
      if(l<=ll&&rr<=r){
         lazy[id]+=x;
         lazy_update();
         return;
      }
      left().assign_range(l,r,x);
      right().assign_range(l,r,x);
      if(mx[id*2]>mx[id*2+1]){
         mx[id]=mx[id*2];
         idx[id]=idx[id*2];
      }
      else{
         mx[id]=mx[id*2+1];
         idx[id]=idx[id*2+1];
      }
   }
   int max_range(int l,int r){
      assert(id<=nmax*5);
      if(ll>r||l>rr)return -1e9;
      lazy_update();
      if(l<=ll&&rr<=r){
         return mx[id];
      }
      int mx1=left().max_range(l,r);
      int mx2=right().max_range(l,r);
      return max(mx1,mx2);
      //think this is clear enough
   }
};
bool cmp(events f,events s){
   if(f.l1<s.l1)return true;
   return false;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   for(int i=1;i<=n;i++){
      if(g[i].size()>1){
         enum_leafs(i);
         break;
      }
   }
   //cout<<"enumed\n";
   //for(int i=1;i<=n;i++){
   //   cout<<i<<"-> "<<leaf[i].first<<" ~ "<<leaf[i].second<<"\n" ; 
   //}
   make_rects();
   //cout<<"REKT\n";
   sort(eve.begin(),eve.end(),cmp);
   sort(eve2.begin(),eve2.end(),cmp);
   //cout<<eve.size()<<"\n";
   //for(int i=0;i<eve.size();i++){
   //   cout<<"l1="<<eve[i].l1<<" r1="<<eve[i].r1<<" l2="<<eve[i].l2<<" r2="<<eve[i].r2<<" profit="<<eve[i].profit<<"\n";
   //}
   //cout<<eve2.size()<<"\n";
   //for(int i=0;i<eve2.size();i++){
   //   cout<<"l1="<<eve2[i].l1<<" r1="<<eve2[i].r1<<" l2="<<eve2[i].l2<<" r2="<<eve2[i].r2<<" profit="<<eve2[i].profit<<"\n";
   //}
   node root(1,leafn,1);
   for(int i=1;i<=leafn;i++)root.assign_range(i,i,0);
   int uk1=0,uk2=0;
   int v,st;
   int ansmx=0,ans1,ans2;
   for(int i=1;i<=leafn;i++){
      while(uk1<eve.size()&&eve[uk1].l1==i){
         root.assign_range(eve[uk1].r1,eve[uk1].r2,eve[uk1].profit);
         uk1++;
      }
      v=idx[1];
      st=root.max_range(1,leafn);
      //cout<<i<<"->"<<st<<" "<<v<<"\n";
      if(ansmx<st){
         ansmx=st;
         ans1=i;
         ans2=v;
      }
      while(uk2<eve2.size()&&eve2[uk2].l1==i){
         root.assign_range(eve2[uk2].r1,eve2[uk2].r2,eve2[uk2].profit);
         uk2++;
      }
   }
   cout<<revl[ans1]<<" "<<revl[ans2]<<" "<<ansmx<<"\n";
}
