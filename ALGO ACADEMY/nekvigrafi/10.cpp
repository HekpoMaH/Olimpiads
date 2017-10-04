#include<bits/stdc++.h>
using namespace std;
set<string> dumi;
map<string,int> used;
bool dif(string s1,string s2){
   int br=0;
   for(int i=0;i<s1.size();i++){
      if(s1[i]!=s2[i])br++;
      if(br>=2)return false;
   }
   return true;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   string start;
   string end;
   cin>>start;
   cin>>end;
   string s;
   while(cin>>s){
      dumi.insert(s);
   }
   queue<string> q;
   q.push(start);
   used[start]=1;
   while(!q.empty()){
      string cur;
      cur=q.front();
      q.pop();
      for(int i=0;i<cur.size();i++){
         for(int j=0;j<26;j++){
            string nw=cur;
            nw[i]=j+'a';
            if(dumi.find(nw)!=dumi.end())if(dif(nw,cur)){
               if(used[nw]==0){
                  q.push(nw);
                  used[nw]=used[cur]+1;
               }
            }
         }
      }
   }
   if(used[end]!=0)cout<<used[end]-1<<"\n";
   else cout<<"NO\n";
}
