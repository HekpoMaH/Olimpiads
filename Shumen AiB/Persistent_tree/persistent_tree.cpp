#include<bits/stdc++.h>
using namespace std;
const int nmax=2*1e5+9;
typedef long long lli;
struct tree{
   lli val,lazy;
   tree *left,*right;
};
lli n,leaves[nmax],cntroots=1,levels=1,type,state,l,r,v,ans=0,N,p=1;
tree *roots[nmax];
void buildtree(tree *node,int lvl){
   node->lazy=0;
   //cout<<"lvl="<<lvl<<"\n";
   //cout.flush();
   if(lvl==levels){
      if(p<=n)cin>>node->val;
      else node->val=0;
      p++;
      return;
   }
   node->left=new tree;
   node->right=new tree;
   buildtree(node->left,lvl+1);
   buildtree(node->right,lvl+1);
   node->val=node->left->val+node->right->val;
}
lli add;
void update(tree *nw,tree *old,int x,int y){
   nw->val=old->val;
   nw->lazy=old->lazy;
   if(l<=x&&y<=r){
      nw->val=old->val+v*(y-x+1);
      nw->lazy=v+old->lazy;
      nw->left=old->left;
      nw->right=old->right;
      return;
   }
   lli mid=x+y;
   mid/=2;
   if(x>r||mid<l)nw->left=old->left;
   else{
      nw->left=new tree;
      update(nw->left,old->left,x,mid);
   }
   if(mid+1>r||y<l)nw->right=old->right;
   else{
      nw->right=new tree;
      update(nw->right,old->right,mid+1,y);
   }
   nw->val=nw->left->val+nw->right->val+nw->lazy*(y-x+1);
}
void findsum(tree *node,int x,int y){
   //cout<<node->val<<" "<<x<<" "<<y<<"\n";
   //cout.flush();
   if(x>r||y<l)return;
   if(l<=x&&y<=r){
      ans+=(y-x+1)*add+node->val;
      return;
   }
   lli mid=x+y;
   mid/=2;
   add+=node->lazy;
   findsum(node->left,x,mid);
   findsum(node->right,mid+1,y);
   add-=node->lazy;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   lli q;
   cin>>n;
   N=1;
   while(N<n){
      N*=2;
      levels++;
   }
   roots[1]=new tree;
   buildtree(roots[1],1);
   cout<<"BUILT\n";
   cin>>q;
   for(int i=1;i<=q;i++){
      cin>>type>>state>>l>>r;
      if(type==1){
         cin>>v;
         cntroots++;
         roots[cntroots]=new tree;
         roots[cntroots]->val=0;roots[cntroots]->lazy=0;
         update(roots[cntroots],roots[state],1,n);
      }
      else{
         add=0;ans=0;
         findsum(roots[state],1,n);
         cout<<ans<<"\n";
         cout.flush();
      }
   }
}
/*
 * 1 2 3 4 91 483 14
 * 4 5 3 4 91 483 14
 * 1 3 4 4
 *
 */
