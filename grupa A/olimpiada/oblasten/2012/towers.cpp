#include<bits/stdc++.h>
using namespace std;
const int nmax=15009;
#define pb push_back
int used[nmax];
int n,k;
vector<int> g[nmax];
int x[nmax],h[nmax];
bool vis(int i,int j){
   if(h[i]==h[j]){
      for(int k=i+1;k<=j-1;k++)
         if(h[k]>=h[i]) return false;           
   }
   else if(h[i]<h[j]){    
      for(int k=i+1;k<=j-1;k++)
         if((h[k]-h[i])*(x[j]-x[i])>=(h[j]-h[i])*(x[k]-x[i])) return false;
   }
   else{
      for(int k=i+1;k<=j-1;k++)
         if((h[k]-h[j])*(x[j]-x[i])>=(h[j]-h[i])*(x[k]-x[j])) return false;
   }
   return true;
}
void bfs(){
   queue<int> q;
   q.push(1);
   used[1]=1;
   while(!q.empty()){
      int curr=q.front();
      q.pop();
      for(int i=0;i<g[curr].size();i++){
         int nw=g[curr][i];
         if(used[nw]==0){
            used[nw]=used[curr]+1;
            q.push(nw);
         }
      }
   }
   cout<<used[n]<<"\n";
}
int main(){
   cin>>n>>k;
   for(int i=1;i<=n;i++){
      cin>>x[i]>>h[i];
   }
   for(int i=1;i<n;i++){
      for(int j=i+1;j<=n;j++){
         if(x[j]-x[i]<=k){
            //cout<<x[j]-x[i]<<" "<<vis(i,j)<<"\n";
            if(vis(i,j)){
               g[i].pb(j);
               //cout<<"added "<<i<<" "<<j<<"\n";
            }
         }
      }
   }
   bfs();
}
