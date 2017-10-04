#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
using namespace std;
const int maxn=100009;
int gnum;
struct trie{
   trie *nxt[26];//ukazatel kym sledva6tite vyrhove
   bool fl;//ima/nqma duma
   int ind;//index ako fl==true
   trie *faillink,*termlink;
   int ntree;
   trie *go[26];
   //termlink-> nai golqmata duma ot re4nika, koqto e sufix na dumata opredelena ot teku6tiq vryh
   //faillink-> nai golemiq krai na prefix, koito e sufix na dumata opredelena ot vyrha
};
string text;
string dict;
int n;
int last[maxn];
trie *top=NULL;
void push(string s,int idx){
   trie *cur=top;
   for(int p=0;p<s.size();p++){
      if(cur->nxt[s[p]-'a'] ==NULL){
         trie *nxty;
         nxty=new trie;
         nxty->fl=false;
         cur->nxt[s[p]-'a']=nxty;
         nxty->ntree=++gnum;
      }
      cur=cur->nxt[s[p]-'a'];
   }
   cur->fl=true;
   cur->ind=idx;
}
bool find(string s){
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
         cout<<(char)('a'+i)<<"( "<<cur->nxt[i]->ntree<<" , "
            <<cur->nxt[i]->faillink->ntree<<" , "
            <<cur->nxt[i]->termlink->ntree<<" , "
            <<cur->go[i]->ntree<<" )"<<"\n";
         parse(in+1,cur->nxt[i]);
      }
   }
}
void bfs(){
   queue<trie*> q;
   top->faillink=top;
   top->termlink=top;
   top->fl=false;
   top->ind=-1;
   top->ntree=0;
   for(int i=0;i<26;i++){
      top->go[i] = top->nxt[i]!=NULL ? top->nxt[i] : top;
   }
   trie *cur,*nw;
   q.push(top);
   while(!q.empty()){
      cur=q.front();
      q.pop();
      for(int i=0;i<26;i++){
         nw=cur->nxt[i];
         if(nw!=NULL){
            trie *nflink;
            for(nflink=cur->faillink; (nflink->nxt[i]==NULL || nflink->nxt[i]==nw) && nflink!=top; nflink=nflink->faillink)
               ;

            if(nflink->nxt[i]!=NULL&&nflink->nxt[i]!=nw)
               nflink=nflink->nxt[i];
            nw->faillink=nflink;

            nw->termlink = nw->faillink->fl==true ? nw->faillink : nw->faillink->termlink;
            
            nw->go[i] = nw->nxt[i]!=NULL ? nw->nxt[i] : nw->faillink->go[i];
            
            //cout<<"node "<<nw->ntree<<" got a flink and tlink "<<nw->faillink->ntree<<" and "<<nw->termlink->ntree<<"\n";
            q.push(nw);
         }
         if(cur->go[i]==NULL){
            cur->go[i] = cur->nxt[i]!=NULL ? cur->nxt[i] : cur->faillink->go[i];
         }
      }
   }
}
void djitkai(trie *p,int idx){
   do{
      if(p->fl==true){
         cout<<"word with idx "<<p->ind<<" ends at "<<idx<<"\n";
      }
      p=p->termlink;
   }while(p!=top);
}
void solve(){
   trie *p=top;
   //for(int i=0;i<26;i++)cout<<top->nxt[0]->go[i]->ind<<" ";cout<<"\n";
   for(int i=0;i<text.size();i++){
      p=p->go[text[i]-'a'];
      //cout<<i<<"\n";
      assert(p!=NULL);
      //cout<<p->ind<<"\n";
      djitkai(p,i);
   }
}
int main(){
   top=new trie;
   cin>>text;
   cin>>n;
   for(int i=1;i<=n;i++){
      cin>>dict;
      push(dict,i);
   }
   //cout<<"AL PUSH\n";
   bfs();
   //cout<<"done\n";
   parse(0,top);
   solve();
}
