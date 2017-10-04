#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct edge{
   int a,b,t;
};
int m,n,k,parent[1009],ans;
vector<edge> ed,tr;
edge wtf;
bool cmp(edge on,edge tw){
   if(on.t>tw.t)return true;
   return false;
}
bool find(int x,int y){
   while(x!=parent[x])x=parent[x];
   while(y!=parent[y])y=parent[y];
   return x==y;
}
void uni(int x,int y){
   int par=x,wt;
   while(par!=parent[par])par=parent[par];
   while(y!=parent[y]){
      wt=parent[y];
      parent[y]=par;
      y=wt;
   }
   parent[y]=par;
}
int main(){
   cin>>n>>m;
   int x,y,z,i;
   for(i=1;i<=n;i++)parent[i]=i;
   for(i=1;i<=m;i++){
      cin>>x>>y>>z;
      wtf.a=x;wtf.b=y;wtf.t=z;
      ed.push_back(wtf);
   }
   cin>>k;
   sort(ed.begin(),ed.end(),cmp);
   for(i=1;i<=m;i++){
      if(find(ed[i-1].a,ed[i-1].b)==false){
         tr.push_back(ed[i-1]);
         uni(ed[i-1].a,ed[i-1].b);
      }
   }
   for(i=0;i<tr.size();i++){
      if(tr[i].t<k)ans++;
   }
   cout<<ans<<endl;
}
