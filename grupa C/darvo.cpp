#include<iostream>
using namespace std;
struct tree
{
  int key;
  tree *left,*right;
}*t;
void addnode(int x,tree*&t)
{
  if(t==NULL)
  {
    t=new tree;
    t->key=x;
    t->left=NULL;
    t->right=NULL;
  }
  else if(x<t->key)addnode(x,t->left);
  else if(x>t->key)addnode(x,t->right);
}
void create(tree *&t)
{
  t=NULL;
  int x;
  while(cin>>x)addnode(x,t);
}
int teglo(tree*t)
{
  int br;
  if(t!=NULL)br=1+teglo(t->left)+teglo(t->right);
  else br=0;
  return br;
}
int suma(tree *t)
{
  int sum;
  if(t!=NULL)sum=t->key+suma(t->left)+suma(t->right);
  else sum=0;
  return sum;
}
int main()
{
  create(t);
  cout<<teglo(t)<<" "<<suma(t)<<endl;
  return 0;
}
