#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
#define mp make_pair
const lli inf=-1e18;
const int nmax=1e5+9;
int n;
lli a[nmax],t[nmax],d[nmax];
lli dp[nmax];
set<pair<int,int> >pos[6];
set<pair<lli,lli> >best[6];
set<pair<int,int> >::iterator it;
set<pair<lli,lli> >::iterator itbest;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=0;i<n;i++){
      cin>>a[i]>>t[i]>>d[i];
   }
   dp[0]=(lli)a[0];
   pos[t[0]].insert(mp(d[0],0));
   best[t[0]].insert(mp(-dp[0],0));
   int k;
   for(int i=1;i<n;i++){
      dp[i]=inf;
      for(int j=1;j<=5;j++){
         while(!pos[j].empty()){
            it=pos[j].begin();
            if(it->first<i){
               k=it->second;
               pos[j].erase(it);
               best[j].erase(make_pair(-(dp[k]+(lli)k*t[k]),k));
            }
            else break;
         }
      }
      for(int j=1;j<=5;j++){
         if(!best[j].empty()){
            itbest=best[j].begin();
            dp[i]=max(dp[i],-(itbest->first)+(lli)a[i]-(lli)i*j);
         }
      }
      pos[t[i]].insert(mp(i+d[i],i));
      best[t[i]].insert(mp(-(dp[i]+(lli)i*t[i]),i));
   }
   cout<<dp[n-1]<<"\n";
}
