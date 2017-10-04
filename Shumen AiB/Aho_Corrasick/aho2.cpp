#include<bits/stdc++.h>
using namespace std;
string text;
string word;
struct node{
   node *next[27];
   bool fl;
   int id;
   node *faillink;
   node *termlink;
   node *parent;
   node *go[27];
   int ntree;
};
node *root;
int br;
void addword(string s,int idx){
   node *cur=root;
   
   for(int i=0;i<(int)s.size();i++){
      if(cur->next[s[i]-'a']!=NULL)cur=cur->next[s[i]-'a'];
      else{
         br++;
         cur->next[s[i]-'a']=new node;
         cur->next[s[i]-'a']->parent=cur;
         cur=cur->next[s[i]-'a'];
         cur->ntree=br;
      }
   }
   cur->fl=true;
   cur->id=idx;
}
void parse(int in,node *cur){
   for(int i=0;i<26;i++){
      if(cur->next[i]!=NULL){
         for(int j=1;j<=in;j++)cout<<" ";
         if(cur->next[i]->fl)cout<<"*";
         cout<<(char)('a'+i)<<"( "<<cur->next[i]->ntree<<" , "
            <<cur->next[i]->faillink->ntree<<" , "
            <<cur->next[i]->termlink->ntree<<" , "
            <<cur->go[i]->ntree<<" )"<<"\n";
         parse(in+1,cur->next[i]);
      }
   }
}
void bfs(){
   queue<node*> q;
   q.push(root);
   root->faillink=root;
   root->termlink=root;
   for(int i=0;i<26;i++)root->go[i]=root;
   while(!q.empty()){
      node *cur=q.front();
      //cout<<q.size()<<"\n";
      //cout.flush();
      q.pop();
      for(int i=0;i<26;i++){
         if(cur->next[i]==NULL)continue;
         node *nfaillink=cur->faillink;
         //cout<<cur->next[i]->ntree<<"=>\n";
         while(nfaillink!=root){
            //cout<<nfaillink->ntree<<" ";
            if(nfaillink->next[i]!=NULL){
               break;
            }
            else{
               nfaillink=nfaillink->faillink;
            }
         }
         if(nfaillink->next[i]!=NULL&&nfaillink->next[i]!=cur->next[i])nfaillink=nfaillink->next[i];
         cur->next[i]->faillink=nfaillink;
         //cout<<nfaillink->ntree<<"\n";
         if(cur->next[i]->faillink->fl==true){
            cur->next[i]->termlink=cur->next[i]->faillink;
         }
         else{
            cur->next[i]->termlink=cur->next[i]->faillink->termlink;
         }
         q.push(cur->next[i]);
      }
      for(int i=0;i<26;i++){
         if(cur->next[i]!=NULL){
            cur->go[i]=cur->next[i];
         }
         else{
            cur->go[i]=cur->faillink->go[i];
         }
      }
   }
}
void output(node *nd,int pos){
   do{
      if(nd->fl==true){
         cout<<"word with idx "<<nd->id<<" ends at "<<pos<<"\n"; 
      }
      nd=nd->termlink;

   }while(nd->ntree!=0);
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>text;
   int m=0;
   cin>>m;
   root=new node;
   root->parent=root;
   for(int i=1;i<=m;i++){
      cin>>word;
      addword(word,i);
   }
   bfs();
   node *curr=root;
   for(int i=0;i<(int)text.size();i++){
      curr=curr->go[text[i]-'a'];
      output(curr,i);
   }
   parse(0,root);
}
