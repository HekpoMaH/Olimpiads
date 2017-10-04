#include<bits/stdc++.h>
using namespace std;
const int maxn=100009;
unordered_map<string,bool> m;
string text;
string dict;
int n;
int last[maxn];
int main(){
   cin>>text;
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>dict;
      m[dict]=true;
   }
   memset(last,0,sizeof(last));
   for(int i=0;i<text.size();i++){
      for(int k=1;k<=20;k++){
         if(i-k+1<0)continue;
         if(m[text.substr(i-k+1,k)]==true){
            if(i-k==-1){
               last[i]=i-k;
               continue;
            }
            if(last[i-k]!=0){
               last[i]=i-k;
            }
         }
      }
   }
   string ans="";
   int cp=text.size()-1,lin=last[cp];
   while(cp!=-1){
      if(lin==cp){
         ans+=" ";
         lin=last[cp];
      }
      ans+=text[cp];
      cp--;
   }
   reverse(ans.begin(),ans.end());
   cout<<ans<<"\n";
}
