#include<bits/stdc++.h>
using namespace std;
int a[109][109];
int n;
string s[109];
int used[109];
int d[109];
string ans="";
void go(int x){
   used[x]=1;
   ans+=(x+'a');
   for(int i=0;i<26;i++){
      if(a[x][i]==1){
         d[i]--;
         a[x][i]--;
         if(used[i]==0)go(i);
      }
   }
}
void topsort(){
   stack<int> stack;
   for(int i=0;i<26;i++){
      if(d[i]==0&&used[i]==0){
         go(i);
      }
   }
}
int main(){
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>s[i];
   }
   for(int i=1;i<n;i++){
      for(int j=i+1;j<=i+1;j++){
         for(int k=0;k<(int)min(s[i].size(),s[j].size());k++){
            if(s[i][k]!=s[j][k]){
               //if(a[s[j][k]-'a'][s[i][k]-'a']==1){
               //   cout<<"Impossible\n";
               //   exit(0);
               //}
               a[s[i][k]-'a'][s[j][k]-'a']=1;
               d[s[j][k]-'a']++;
               break;
            }
         }
      }
   }
   topsort();
   for(int i=0;i<26;i++){
      for(int j=0;j<26;j++){
         if(a[i][j]!=0){
            cout<<"Impossible\n";
            exit(0);
         }
      }
   }
   if(ans.size()!=26)cout<<"Impossible\n";
   else cout<<ans<<"\n";
}
