#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
using namespace std;
const int nmax=1e5+9;
struct trie{
   int nxt[29];
   bool fl;
   int ind;
   int faillink,termlink;
   int go[29];
   int ntree;
};
string text;
string dict;
int n;
int last[nmax];
int curtoad=1;
trie tr[nmax];
void push(string s,int idx){
   int cur=1;
   for(int p=0;p<s.size();p++){
      if(tr[cur].nxt[s[p]-'a']==0){
         curtoad++;
         tr[curtoad].fl=false;
         tr[cur].nxt[s[p]-'a']=curtoad;
         tr[cur].ntree=curtoad;
      }
      cur=tr[cur].nxt[s[p]-'a'];
   }
   tr[cur].fl=true;
   tr[cur].ind=idx;
}
void parse(int in,int cur){
   for(int i=0;i<26;i++){
      if(tr[cur].nxt[i]!=0){
         for(int j=1;j<=in;j++)cout<<" ";
         if(tr[tr[cur].nxt[i]].fl)cout<<"*";
         cout<<(char)('a'+i)<<"( "<<tr[cur].nxt[i]-1<<" , "
            <<tr[tr[cur].nxt[i]].faillink-1<<" , "
            <<tr[tr[cur].nxt[i]].termlink-1<<" , "
            <<tr[cur].go[i]-1<<" )"<<"\n";
         parse(in+1,tr[cur].nxt[i]);
      }
   }
}
void bfs(){
   queue<int> q;
   int cur=1;
   tr[cur].faillink=1;
   tr[cur].termlink=1;
   tr[cur].fl=false;
   tr[cur].ind=-1;
   tr[cur].ntree=0;
   for(int i=0;i<26;i++){
      tr[cur].go[i]=tr[cur].nxt[i]!=0 ? tr[cur].nxt[i] : cur;
   }
   q.push(cur);
   int nw;
   while(!q.empty()){
      cur=q.front();
      q.pop();
      for(int i=0;i<26;i++){
         nw=tr[cur].nxt[i];
         if(nw!=0){
            int nflink;
            for(nflink=tr[cur].faillink;(tr[nflink].nxt[i]==0||tr[nflink].nxt[i]==nw)&&nflink!=1;nflink=tr[nflink].faillink)
               ;
            if(tr[nflink].nxt[i]!=0&&tr[nflink].nxt[i]!=nw)
               nflink=tr[nflink].nxt[i];
            tr[nw].faillink=nflink;
            tr[nw].termlink=tr[tr[nw].faillink].fl==true ? tr[nw].faillink : tr[tr[nw].faillink].termlink;
            tr[nw].go[i]=tr[nw].nxt[i]!=0 ? tr[nw].nxt[i] : tr[tr[nw].faillink].go[i];
            q.push(nw);
         }
         if(tr[cur].go[i]==0){
            tr[cur].go[i]= tr[cur].nxt[i]!=0 ? tr[cur].nxt[i] : tr[tr[cur].faillink].go[i];
         }
      }
   }
}
void djitkai(int cur,int idx){
   do{
      if(tr[cur].fl==true)
         cout<<"word with idx "<<tr[cur].ind<<" ends at "<<idx<<"\n";
      cur=tr[cur].termlink;
   }while(cur>1);
}
void solve(){
   int cur=1;
   for(int i=0;i<text.size();i++){
      cur=tr[cur].go[text[i]-'a'];
      djitkai(cur,i);
   }
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>text;
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>dict;
      push(dict,i);
   }
   //cout<<"PUshEd\n";
   //cout.flush();
   bfs();
   //cout<<"BfeSSS\n";
   //cout.flush();
   //parse(0,1);
   solve();
}
