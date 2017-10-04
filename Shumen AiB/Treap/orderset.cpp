//spoj orderset
#include<bits/stdc++.h>
using namespace std;
struct treap{
   int key,prior;
   int cnt;
   treap *l,*r;
   treap(){}
   treap(int _key,int _prior){
      key=_key;
      prior=_prior;
      cnt=1;
      l=NULL;
      r=NULL;
   }
};
int cnt(treap *t){
   return t ? t->cnt : 0;
}
void upCnt(treap *t){
   if(t!=NULL){
      t->cnt=1+cnt(t->l)+cnt(t->r);
   }
}
void split(treap *t,int key,treap *&l,treap*&r){
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
   upCnt(t);
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
      else insert(it->key<t->key ? t->l : t-> r, it);
   }
   upCnt(t);
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
   upCnt(t);
}
void erase(treap *&t,int key){
   if(t->key==key){
      merge(t,t->l,t->r);
   }
   else{
      erase(key<t->key ? t->l : t->r, key);
   }
   upCnt(t);
}
treap *find(treap *t,int key){
   if(t==NULL)return NULL;
   if(t->key==key)return t;
   if(t->key>key)return find(t->l,key);
   return find(t->r,key);
}
int cntSmaller(treap *t,int key){
   if(t==NULL)return 0;
   if(t->key<key){
      if(t->l!=NULL)return 1+t->l->cnt+cntSmaller(t->r,key);
      return 1+cntSmaller(t->r,key);
   }
   return cntSmaller(t->l,key);
}
/*int treapKthSmallest(pointreap T,int x0)
{
    //printf("%d %d %d\n",T->x,T->y,x0);
    if(treapS(T->left)+1==x0)return T->x;
    if(treapS(T->left)+1<x0)
        return treapKthSmallest(T->right,x0-(treapS(T->left)+1));
    return treapKthSmallest(T->left,x0);
}*/
treap *findK(treap *t,int k){
   if(t==NULL)return NULL;
   int tlef;
   if(t->l)tlef=t->l->cnt+1;
   else tlef=1;
   if(tlef==k)return t;
   if(tlef<k){
      return findK(t->r,k-tlef);
   }
   return findK(t->l,k);
}
treap *root=NULL;
treap *s;
int main(){
   int q;
   srand(47);
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>q;
   for(int i=1;i<=q;i++){
      char ch;
      int x;
      cin>>ch;
      cin>>x;
      if(ch=='I'){
         if(find(root,x)==NULL)insert(root,new treap(x,rand()));
      }
      if(ch=='D'){
         if(find(root,x)!=NULL)erase(root,x);
      }
      if(ch=='C'){
         cout<<cntSmaller(root,x)<<"\n";
      }
      if(ch=='K'){
         s=findK(root,x);
         if(s==NULL)cout<<"invalid\n";
         else cout<<s->key<<"\n";
      }
   }
}
