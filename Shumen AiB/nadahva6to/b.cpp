#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>s1>>s2;
   int used1[10],used2[10];
   memset(used1,0,sizeof(used1));
   memset(used2,0,sizeof(used2));
   vector<int> ans;
   for(int i=0;i<s1.size();i++){
      used1[s1[i]-'0']++;
   }
   for(int i=0;i<s2.size();i++){
      used2[s2[i]-'0']++;
   }
   for(int i=9;i>=0;i--){
      while(used1[i]>0&&used2[i]>0){
         ans.push_back(i);
         used1[i]--;
         used2[i]--;
      }
   }
   if(ans.size()==0){
      cout<<-1<<"\n";
      exit(0);
   }
   
   for(int i=0;i<ans.size();i++){
      cout<<ans[i];
      if(ans[0]==0)break;
   }
   cout<<"\n";
}
