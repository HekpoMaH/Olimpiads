#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define pb push_back
vector<lli> mono;
map<lli,lli> used;
map<lli,lli> from;
lli n;
void solve(){
   used[n]=1;
   queue<lli> q;
   q.push(n);
   while(!q.empty()){
      lli curr=q.front();
      if(curr==0)break;
      q.pop();
      for(int i=0;i<(int)mono.size();i++){
         if(curr-mono[i]<0)continue;
         if(curr>mono[i]*100)continue;
         if(used.find(curr-mono[i])==used.end()){
            used[curr-mono[i]]=used[curr]+1;
            from[curr-mono[i]]=curr;
            q.push(curr-mono[i]);
            if(curr==mono[i])break;
         }
      }
   }
   cout<<used[0]-1<<"\n";
   //exit(0);
   lli curr=0;
   vector<lli> ans;
   while(curr!=n){
      ans.pb(from[curr]-curr);
      curr=from[curr];
   }
   for(int i=0;i<(int)ans.size();i++){
      cout<<ans[i]<<" ";
   }
   cout<<"\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=9;i++){
      lli sum=i;
      for(int j=1;j<=11;j++){
         mono.pb(sum);
         sum=sum*10LL+i;
      }
   }
   sort(mono.begin(),mono.end());
   reverse(mono.begin(),mono.end());
   solve();
}
