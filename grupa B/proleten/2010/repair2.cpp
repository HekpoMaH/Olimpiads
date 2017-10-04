#include<bits/stdc++.h>
using namespace std;
const int maxn=1009;
int pr[maxn];
struct edge{
   int x,y,z;
};
vector<edge> e;
vector<edge> ans;
int n,m;
int u[maxn],h[maxn];
void read(){
   cin>>n>>m;
   for(int i=1;i<=n;i++){
      cin>>pr[i];
      u[i]=i;
   }
   edge ed;
   for(int i=1;i<=m;i++){
      cin>>ed.x>>ed.y>>ed.z;
      if(ed.x>ed.y)swap(ed.y,ed.x);
      ed.z=pr[ed.x]*(ed.z/2+ed.z%2)+pr[ed.y]*(ed.z/2);
      e.push_back(ed);
   }
}
bool cmp(edge f,edge s){
   return f.z<s.z;
}
bool cmp2(edge f,edge s){
   if(f.x<s.x)return true;
   if(f.x>s.x)return false;
   if(f.y<s.y)return true;
   return false;
}
int find(int v){
   int root=v,to;
   while(root!=u[root])root=u[root];
   while(root!=u[v]){
      to=u[v];
      u[v]=root;
      v=to;
   }
   return root;
}
void uni(int xroot,int yroot){
   if(h[xroot]<h[yroot])u[xroot]=yroot;
   else{
      u[yroot]=xroot;
      if(h[xroot]==h[yroot])
         h[xroot]++;
   }
}
void solve(){
   sort(e.begin(),e.end(),cmp);
   int sum=0,xroot,yroot;
   for(int i=0;i<e.size();i++){
      xroot=find(e[i].x);
      yroot=find(e[i].y);
      if(xroot!=yroot){
         ans.push_back(e[i]);
         sum+=e[i].z;
         uni(xroot,yroot);
      }
   }
   cout<<sum<<"\n";
   sort(ans.begin(),ans.end(),cmp2);
   for(int i=0;i<ans.size();i++)cout<<ans[i].x<<" "<<ans[i].y<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   read();
   solve();
}
