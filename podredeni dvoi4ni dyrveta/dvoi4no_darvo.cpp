#include<bits/stdc++.h>
using namespace std;
struct node{
   int x;
   node *lef,*righ;
};
node *root;
int height(node *cur){
   if(cur==NULL)return -1;
   return max(height(cur->lef),height(cur->righ))+1;
}
int teglo(node *cur){
   if(cur==NULL)return 0;
   return teglo(cur->lef)+teglo(cur->righ)+1;
}
void addnode(int q,node *&cur){
   if(cur==NULL){
      cur=new node;
      cur->x=q;
      cur->lef=NULL;
      cur->righ=NULL;
   }
   else{
      if(q==cur->x)return;
      if(q<cur->x){
         addnode(q,cur->lef);
         return;
      }
      addnode(q,cur->righ);
   }
}
void shift(node *&fi,node *&se){
   if(fi->righ!=NULL)shift(fi->righ,se);
   else{
      se->x=fi->x;
      se=fi;
      fi=fi->lef;
   }
}
void delnode(int q,node *&cur){
   if(cur==NULL){
      cout<<"No such node\n";
      return;
   }
   if(q<cur->x){
      delnode(q,cur->lef);
   }
   else if(q>cur->x){
      delnode(q,cur->righ);
   }
   else{
      node *t=cur;
      if(cur->lef==NULL){
         cur=cur->righ;
      }
      else if(cur->righ==NULL){
         cur=cur->lef;
      }
      else{
         shift(cur->lef,t);
      }
      delete t;
   }
}
node *search(int q,node *cur){
   if(cur==NULL){
      return NULL;
   }
   if(q==cur->x)return cur;
   if(q<cur->x)return search(q,cur->lef);
   if(q>cur->x)return search(q,cur->righ);
}
bool searchpath(int n1,int n2){
   node *st=search(n1,root);
   return search(n2,st)!=NULL;
}
void printpath(int q,node *cur){
   cout<<cur->x<<" ";
   if(q==cur->x)return;
   if(q<cur->x)printpath(q,cur->lef);
   else printpath(q,cur->righ);
}
void lkd(node *cur){
   if(cur==NULL){
      return;
   }
   lkd(cur->lef);
   cout<<cur->x<<" ";
   lkd(cur->righ);
}
void printtree(node *cur,int lvl){
   if(cur==NULL){
      return;
   }
   printtree(cur->righ,lvl+1);
   for(int i=1;i<=4*lvl;i++)cout<<" ";
   cout<<cur->x<<" ";
   cout<<"\n";
   printtree(cur->lef,lvl+1);
}
int main(){
   int n;
   cin>>n;
   int q;
   while(n--){
      cin>>q;
      addnode(q,root);
   }
   cout<<height(root)<<"\n";
   lkd(root);
   cout<<"\n";
   printtree(root,0);
   //cout<<teglo(root)<<"\n";
   //cin>>n;
   //if(search(n,root)==NULL){
   //   cout<<"No such number\n";
   //}
   //else cout<<"Found\n";
   //int x,y;
   //cin>>x>>y;
   //cout<<(searchpath(x,y)==true ? "Exists\n" : "Doesn't exist\n");
   //if(searchpath(x,y)==true){
   //   printpath(y,search(x,root));
   //   cout<<"\n";
   //}
   cout<<"------------------\n";
   cin>>n;
   delnode(n,root);
   printtree(root,0);
}
