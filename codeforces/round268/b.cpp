#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll> ls;
ll vv[100009];
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   ll n,a,b;
   cin>>n>>a>>b;
   int sw=0;
   if(b<a){
      sw=1;swap(a,b);
   }
   for(int i=0;i<n;i++){
      ll v;
      cin>>v;
      ls[v]=i+1;
   }
   for(auto v:ls){
      if(v.second>0){
         if(ls[b-v.first]>0){
            vv[v.second]=1;
            vv[ls[b-v.first]]=1;
            ls[v.first]=0;
            ls[b-v.first]=0;
         }
         else if(ls[a-v.first]>0){
            vv[v.second]=0;
            vv[ls[a-v.first]]=0;
            ls[v.first]=0;
            ls[a-v.first]=0;
         }
         else{
            cout<<"NO\n";
            return 0;
         }
      }
   }
   cout<<"YES\n";
   for(int i=1;i<=n;i++){
      if(sw)cout<<1-vv[i]<<" ";
      else cout<<vv[i]<<" ";
   }
}
