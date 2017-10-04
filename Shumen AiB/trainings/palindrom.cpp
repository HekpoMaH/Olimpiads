//informatics.mccme.ru - 592
#include<bits/stdc++.h>
using namespace std;
int used[29];
string s;
int main(){
   int za_ko_tui;
   cin>>za_ko_tui;
   cin>>s;
   for(size_t i=0;i<s.size();i++){
      used[s[i]-'A']++;
   }
   string ans="";
   char pn4='.';//pyrva ne4etna -> pn4
   for(int i=0;i<26;i++){
      for(int j=1;j<=used[i]/2;j++){
         ans+=(char)(i+'A');
      }
      if(used[i]&1){
         if(pn4=='.')pn4=i+'A';
      }
   }
   cout<<ans;
   if(pn4!='.')cout<<pn4;
   reverse(ans.begin(),ans.end());
   cout<<ans<<"\n";
}

