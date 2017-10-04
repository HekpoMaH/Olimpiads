#include<bits/stdc++.h>
using namespace std;
struct treap{
   int key,prior;
   treap *l,*r;
   treap(){}
   treap(int _key,int _prior){
      key=_key;
      prior=_prior;
      l=NULL;
      r=NULL;
   }
};
void split(treap *t,int key,treap *&l,treap *&r){
   if(t==NULL){
      l=NULL;
      r=NULL;
   }
   else{
      if(key<t->key){
         split(t->l,key,l,t->l);
         r=t;
      }
      else{
         split(t->r,key,t->r,r);
         l=t;
      }
   }
}
void insert(treap *&t,treap *it){
   if(t==NULL){
      t=it;
   }
   else{
      if(it->prior>t->prior){
         split(t,it->key,it->l,it->r);
         t=it;
      }
      else insert(it->key<t->key ? t->l : t->r, it);
   }
}
void merge(treap *&t,treap *l,treap *r){
   if(l==NULL||r==NULL){
      t=l ? l : r;
   }
   else{
      if(l->prior>r->prior){
         merge(l->r,l->r,r);
         t=l;
      }
      else{
         merge(r->l,l,r->l);
         t=r;
      }
   }
}
void erase(treap *&t,int key){
   if(t->key==key){
      merge(t,t->l,t->r);
   }
   else{
      erase(key<t->key ? t->l : t->r, key);
   }
}
bool find(treap *t,int key){
   if(t==NULL)return false;
   //cout<<t->key<<" "<<key<<"\n";
   if(t->key==key)return true;
   return find(t->l,key)|find(t->r,key);
}
treap *root=NULL;
int main(){
   int n;
   srand(47);
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
      int op,x;
      cin>>op>>x;
      if(op==0)insert(root,new treap(x,rand()));
      if(op==1)erase(root,x);
      if(op==2)cout<<find(root,x)<<"\n";
      //find(root,1);
      //cout<<"-------\n";

   }
}
