#include<bits/stdc++.h>
using namespace std;
int a[109][109];
string s[109];
int d[109];
int n;
void makeadif(string aa,string b){
   for(int i=0;i<(int)min(aa.size(),b.size());i++){
      if(aa[i]!=b[i]){
         int let1=aa[i]-'a';
         int let2=b[i]-'a';
         if(a[let1][let2]==-1){
            return;
         }
         if(a[let2][let1]==-1){
            cout<<"Impossible\n";
            exit(0);
         }
         //cout<<"node "<<(char)(let1+'a')<<" "<<(char)(let2+'a')<<"\n";
         a[let1][let2]=-1;
         d[let2]++;
         return;
      }
   }
   if(aa.size()>b.size()){
      cout<<"Impossible\n";
      exit(0);
   }
}
int used[100];
int br;
string ans;
void dfs(int node){
   assert(node<26);
   br++;
   ans+=node+'a';
   used[node]=1;
   for(int i=0;i<26;i++){
      if(a[node][i]==-1&&used[i]==0)d[i]--;
      if(a[node][i]==-1&&used[i]==0)
         if(d[i]==0){
            dfs(i);
         }
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>s[i];
   }
   for(int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
         makeadif(s[i],s[j]);
      }
   }
   //for(int i=0;i<27;i++){
   //   for(int j=0;j<27;j++){
   //      cout<<a[i][j]<<" ";
   //   }
   //   cout<<"\n";
   //}
   for(int i=0;i<26;i++){
      if(d[i]==0&&used[i]==0){
         dfs(i);
      }
   }
   for(int i=0;i<26;i++){
      if(d[i]==0&&used[i]==0){
         dfs(i);
      }
   }
   for(int i=0;i<26;i++){
      if(d[i]==0&&used[i]==0){
         dfs(i);
      }
   }
   //assert(br==26);
   if(br<26)cout<<"Impossible\n";
   else{cout<<ans;
   cout<<"\n";}
}
