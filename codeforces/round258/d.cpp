#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
pair<ll,ll> solve(){
   ll ansev,ansodd;
   ansev=ansodd=0;
   int cntev[2],cntodd[2];
   memset(cntev,0,sizeof(cntev));
   memset(cntodd,0,sizeof(cntodd));
   for(int i=0;i<s.size();i++){
      ansodd++;
      int id=s[i]-'a';
      if(i%2==0){
         ansodd+=cntev[id];
         ansev+=cntodd[id];
         cntev[id]++;
      }
      else{
         ansodd+=cntodd[id];
         ansev+=cntev[id];
         cntodd[id]++;
      }
   }
   return make_pair(ansev,ansodd);
}
int main(){
   cin>>s;
   pair<ll,ll> ans=solve();
   cout<<ans.first<<" "<<ans.second<<"\n";
}
