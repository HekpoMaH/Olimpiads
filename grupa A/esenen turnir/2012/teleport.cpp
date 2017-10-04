#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;
//Vi, Stand for Violence
bool half(int n,int k){
   return 2*k>=(1<<n);
}
vi solve(int n,int k){
   vi ret;
   if(n==1&&k==0){
      ret.pb(1);
      return ret;
   }
   if(half(n,k)){
      ret=solve(n,(1<<n)-k-1);
      for(int i=0;i<ret.size();i++){
         ret[i]*=-1;
      }
      return ret;
   }
   vi prv=solve(n-1,k);
   int shift=1<<(n-1);
   if(half(n-1,k)){
      reverse(prv.begin(),prv.end());
      for(int i=0;i<shift-1;i++)
         prv[i]*=-1;
      ret=prv;
      ret.pb(-shift);
      for(int i=0;i<shift-1;i++){
         if(prv[i]<0)ret.pb(prv[i]-shift);
         else ret.pb(prv[i]+shift);
      }
   }
   else{
      for(int i=0;i<shift-1;i++){
         if(prv[i]<0)ret.pb(prv[i]-shift);
         else ret.pb(prv[i]+shift);
      }
      ret.pb(-shift);
      for(int i=0;i<shift-1;i++)
         ret.pb(prv[i]);
   }
   return ret;
}
int main(){
   int n,k;
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>k;
   vi ans=solve(n,k);
   cout<<ans.size()<<"\n";
   for(int i=0;i<ans.size();i++){
      cout<<ans[i]<<" ";
   }
   cout<<"\n";
}
