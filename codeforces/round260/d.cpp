#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+5,cmax=29;
int trie[nmax][cmax];
int kids[nmax];
int verctr=1;
int k,n;
string s;
int l;
int li[nmax];
int w[nmax];
void add(){
   int cur=1;
   int letter;
   for(int i=0;i<l;i++){
      letter=s[i]-'a';
      if(trie[cur][letter]==0){
         verctr++;
         trie[cur][letter]=verctr;
         kids[cur]++;
         cur=verctr;
      }
      else{
         cur=trie[cur][letter];
      }
   }
}
bool winpos(int ver){
   bool won=false;
   if(kids[ver]==0){
      w[ver]=false;
      return false;
   }
   for(int i=0;i<26;i++){
      if(trie[ver][i]!=0){
         if(!winpos(trie[ver][i])){
            won=true;
         }
      }
   }
   w[ver]=won;
   return won;
}
bool loseintpos(int ver){
   bool lose=false;
   if(kids[ver]==0){
      li[ver]=true;
      return true;
   }
   for(int i=0;i<26;i++){
      if(trie[ver][i]!=0){
         if(!loseintpos(trie[ver][i])){
            lose=true;
         }
      }
   }
   li[ver]=lose;
   return lose;
}
int main(){  
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>k;
   for(int i=1;i<=n;i++){
      cin>>s;
      l=s.size();
      add();
   }
   winpos(1);
   loseintpos(1);
   for(int i=1;i<=n;i++){
   }
   if(!w[1]){
      cout<<"Second\n";
      return 0;
   }
   if(li[1]){
      cout<<"First\n";
      return 0;
   }
   if(k%2==0)cout<<"Second\n";
   else cout<<"First\n";
}
