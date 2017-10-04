#include<bits/stdc++.h>
using namespace std;
void solve(){
   int f,g,k;
   string s1,s2;
   cin>>f>>g>>k;
   cin>>s1>>s2;
   int p1=0,p2=0;
   if(s1[0]!=s2[0]){
      cout<<"No\n";
      return;
   }
   while(p1<s1.size()-k+1){
      if(s1[p1]==s2[p2]){
         p2++;
         if(p2==s2.size()){
            cout<<"Yes\n";
            return;
         }
         p1+=k;
      }
      else p1++;
   }
   cout<<"No\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int t;
   cin>>t;
   while(t--){
      solve();
   }
}
//lifechrisherorealindeedsweet
