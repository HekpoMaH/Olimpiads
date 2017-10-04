#include<iostream>
using namespace std;
struct tree
{
  int key;
  tree *left,*right;
}*t;
void addnode(int x,tree *&t)
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
  else cout<<"aaaaaa"<<endl;
}
void create(tree*& t)
{
  t=NULL;
  int x;
  while(cin>>x)addnode(x,t);
}
void printlkd(tree*&t)
{
  if(t!=NULL)
  {
    printlkd(t->left);
    cout<<t->key<<" ";
    printlkd(t->right);
  }
}
void print(tree*t,int h)
{
  if(t!=NULL)
  {
    print(t->right,h+1);
    for(int i=0;i<h;i++)
    {
      cout<<" ";
    }
    cout<<t->key<<endl;
    print(t->left,h+1);
  }
}
int main()
{
  create(t);
  printlkd(t);
  cout<<endl;
  print(t,0);
  return 0;
}
