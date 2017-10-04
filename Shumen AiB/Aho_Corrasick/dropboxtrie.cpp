#include<bits/stdc++.h>
using namespace std;
const int maxn=100009;
unordered_map<string,bool> m;
struct trie{
   trie *nxt[26];
   bool fl;
};
string text;
string dict;
int n;
int last[maxn];
trie *top=NULL;
void push(string s){
   trie *cur=top;
   for(int p=0;p<s.size();p++){
      if(cur->nxt[s[p]-'a'] ==NULL){
         trie *nxty;
         nxty=new trie;
         nxty->fl=false;
         cur->nxt[s[p]-'a']=nxty;
      }
      cur=cur->nxt[s[p]-'a'];
   }
   cur->fl=true;
}
bool find(string s){
   reverse(s.begin(),s.end());
   trie *cur=top;
   for(int p=0;p<s.size();p++){
      cur=cur->nxt[s[p]-'a'];
      if(cur==NULL){
         return false;
      }
   }
   return cur->fl;
}
void parse(int in,trie *cur){
   for(int i=0;i<26;i++){
      if(cur->nxt[i]!=NULL){
         for(int j=1;j<=in;j++)cout<<" ";
         if(cur->nxt[i]->fl)cout<<"*";
         cout<<(char)('a'+i)<<"\n";
         parse(in+1,cur->nxt[i]);
      }
   }
}
int main(){
   top=new trie;
   top->fl=false;
   cin>>text;
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>dict;
      reverse(dict.begin(),dict.end());
      push(dict);
      m[dict]=true;
   }
   memset(last,0,sizeof(last));
   for(int i=0;i<text.size();i++){
      trie *cur=top;
      for(int k=1;k<=20;k++){
         if(i-k+1<0)continue;
         cur=cur->nxt[text[i-k+1]-'a'];
         if(cur==NULL)break;
         if(cur->fl ==true){
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
