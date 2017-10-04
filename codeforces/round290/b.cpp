#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long lli;
const int nmax=309;
lli a[nmax];
lli b[nmax];
lli n;
lli nod(lli x,lli y){
   return y==0 ? x : nod(y,x%y);
}
priority_queue<lli> q;
map<lli,lli> dp;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;

   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   for(int i=1;i<=n;i++){
      cin>>b[i];
      q.push(a[i]);
      dp[a[i]]=b[i];
   }
   while(!q.empty()){
      lli cur=q.top();
      q.pop();
      //cout<<cur<<"\n";
      for(int i=1;i<=n;i++){
         lli nc=nod(cur,a[i]);
         //cout<<nc<<" "<<dp[nc]<<" "<<dp[cur]+b[i]<<"\n";
         if(dp[nc]==0||dp[nc]>dp[cur]+b[i]){
            dp[nc]=dp[cur]+b[i];
            q.push(nc);
         }
      }
   }
   if(dp[1]==0)cout<<-1<<"\n";
   else cout<<dp[1]<<"\n";
}
