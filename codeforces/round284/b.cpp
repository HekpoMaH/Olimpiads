#include<bits/stdc++.h>
using namespace std;
map<string,string> cor;
map<string,bool> fi;
int n,m;
string s1,s2;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m;
   for(int i=1;i<=m;i++){
      cin>>s1>>s2;
      cor[s1]=s2;
      fi[s1]=true;
      cor[s2]=s1;
   }
   for(int i=1;i<=n;i++){
      cin>>s1;
      if(cor[s1].size()<s1.size()){
         cout<<cor[s1]<<" ";
      }
      if(cor[s1].size()>s1.size()){
         cout<<s1<<" ";
      }
      if(cor[s1].size()==s1.size()){
         if(fi[s1]==true)cout<<s1<<" ";
         else cout<<s2<<" ";
      }
   }
   cout<<"\n";
}
