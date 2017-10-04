#include<bits/stdc++.h>
using namespace std;
string s;
int p,n;
string s1;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>p;
   cin>>s;
   s1=s;
   int i;
   int fl=1;
   for(i=n-1;i>=0;i--){
      int used[30];
      memset(used,0,sizeof(used));
      for(int j=i;j>=0&&j>=i-2;j--){
         used[s1[j]-'a']++;
      }
      for(int j=s1[i]-'a';j<p;j++){
         if(used[j]==0){
            s1[i]=j+'a';
            fl=0;
            break;
         }
      }
      if(!fl)break;
   }
   if(fl==1){
      cout<<"NO\n";
      return 0;
   }
   if(s==s1){
      cout<<"NO\n";
      return 0;
   }
   for(int i1=i+1;i1<n;i1++){
      int used[30];
      memset(used,0,sizeof(used));
      for(int j=i1-1;j>=0&&j>=i1-2;j--){
         used[s1[j]-'a']++;
      }
      for(int j=0;j<p;j++){
         if(used[j]==0){
            s1[i1]=j+'a';
            break;
         }
      }
   }
   if(s==s1){
      cout<<"NO\n";
      return 0;
   }
   cout<<s1<<"\n";
}
