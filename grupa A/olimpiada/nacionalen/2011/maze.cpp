#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int inf=1e9;
const int lgn=15;
const int nmax=20009;
int n;
vector<int> fo[nmax];
int maxd[nmax],depth[nmax];
int go_down[nmax][lgn+1],go_up[nmax][lgn+1];
int md1[nmax],md2[nmax];

void dfs(int vr,int par){
   if(par!=-1)fo[vr].erase(find(fo[vr].begin(),fo[vr].end(),par));
   if(par!=-1)depth[vr]=depth[par]+1;
   go_up[vr][0]=par;
   for(int i=1;i<=lgn;i++){
      int to=go_up[vr][i-1];
      if(to==-1)break;
      go_up[vr][i]=go_up[to][i-1];
   }
   int md11=-1,md22=-1;
   for(int i=0;i<(int)fo[vr].size();i++){
      int to=fo[vr][i];
      dfs(to,vr);
      if(md22==-1||maxd[to]>maxd[md22]){
         md22=to;
         if(md11==-1||maxd[md11]<maxd[md22]){
            swap(md11,md22);
         }
      }
   }
   md1[vr]=md11;
   md2[vr]=md22;
   if(md11!=-1){
      maxd[vr]=1+maxd[md11];
   }
   go_down[vr][0]=md11;
   for(int i=1;i<=lgn;i++){
      int to=go_down[vr][i-1];
      if(to==-1)break;
      go_down[vr][i]=go_down[to][i-1];
   }
}
int lpv[nmax],lpl[nmax],lpgo[nmax];
void dfs1(int vr,int bestv,int bestl,int razkl){
   lpv[vr]=vr;
   lpl[vr]=maxd[vr],lpgo[vr]=md1[vr];
   if(bestl+depth[vr]+1>lpl[vr]){
      lpl[vr]=bestl+depth[vr]+1;
      lpv[vr]=bestv;
      lpgo[vr]=razkl;
   }
   for(int i=0;i<fo[vr].size();i++){
      int to=fo[vr][i],use;
      if(to==md1[vr])use=md2[vr];
      else use=md1[vr];
      if(use!=-1){
         if(bestl<maxd[use]-depth[vr])dfs1(to,vr,maxd[use]-depth[vr],use);
         else dfs1(to,bestv,bestl,razkl);
      }
      else{
         if(bestl<-depth[vr])dfs1(to,vr,-depth[vr],-1);
         else dfs1(to,bestv,bestl,razkl);
      }
   }
}
int climb_up(int vr,int how){
   int lg=lgn;
   while(how>0){
      if(how<(1<<lg)){
         lg--;
         continue;
      }
      else{
         how-=(1<<lg);
         vr=go_up[vr][lg];
      }
   }
   return vr;
}
int climb_down(int vr,int how){
   int lg=lgn;
   while(how>0){
      if(how<(1<<lg)){
         lg--;
         continue;
      }
      else{
         how-=(1<<lg);
         vr=go_down[vr][lg];
      }
   }
   return vr;
}
int querry(int vr,int d){
   if(lpl[vr]<d)return 0;
   int root=lpv[vr];
   if(depth[vr]-depth[root]>=d)return climb_up(vr,d)+1;
   d-=(1+depth[vr]-depth[root]);
   return climb_down(lpgo[vr],d)+1;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      int q;
      cin>>q;
      while(q--){
         int l;
         cin>>l;
         fo[i].pb(l);
      }
   }
   dfs(0,-1);
   dfs1(0,-1,-inf,-1);
   int qq;
   cin>>qq;
   while(qq--){
      int v,d;
      cin>>v>>d;
      cout<<querry(v,d)<<"\n";
   }
}
