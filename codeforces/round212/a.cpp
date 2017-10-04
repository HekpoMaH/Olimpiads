#include<bits/stdc++.h>
using namespace std;
int px[4]={-11,2,-2};
int py[4]={-11,2,-2};
void solve(){
   string s[100];
   int n;
   n=8;
   for(int i=0;i<n;i++){
      cin>>s[i];
   }
   int p1x,p1y,p2x,p2y;
   p1x=-11;p2x=-11;
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         if(s[i][j]=='K'){
            if(p1x==-11){
               p1x=i;
               p1y=j;
            }
            else p2x=i,p2y=j;
         }
      }
   }
   if((p2x-p1x)%4==0&&(p2y-p1y)%4==0)cout<<"YES\n";
   else cout<<"NO\n";
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int t;
   cin>>t;
   string empt;
   while(t--){
      solve();
   }
}
