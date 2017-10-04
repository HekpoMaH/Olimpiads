 //Persistent Lazy Propagation - Dimitar Karev & Petar Velkov
#include<iostream>
#include<cmath>
#include<algorithm>
#include<climits>
#include<fstream>
using namespace std;
struct Tree
{
    long long val,store;
    Tree *Left, *Right;
};
long long N=1,Leaves[200000],p=1,CntRoots=1,Levels=1,n,Type,State,l,r,v,Ans=0;
Tree *Roots[200005];
void BuildTree(Tree *Node,int lvl)
{
    Node->store=0;
    if(lvl==Levels)
    {
        if(p<=n)cin>>Node->val;
        else Node->val=0;
        p++;
        return;
    }
    Node->Left=new Tree;
    Node->Right=new Tree;
    BuildTree(Node->Left,lvl+1);
    BuildTree(Node->Right,lvl+1);
    Node->val=Node->Left->val+Node->Right->val;
}
long long Add=0;
void Update(Tree *NewNode,Tree *OldNode,int x,int y)
{
    NewNode->val=OldNode->val;
    NewNode->store=OldNode->store;
    if(x>=l && y<=r)
    {
        NewNode->val=OldNode->val+v*(y-x+1);
        NewNode->store=v+OldNode->store;
        NewNode->Left=OldNode->Left;
        NewNode->Right=OldNode->Right;
        return;
    }
    long long Mid=(x+y)/2;
    if(x>r || Mid<l) NewNode->Left=OldNode->Left;
    else
    {
        NewNode->Left=new Tree;
        Update(NewNode->Left,OldNode->Left,x,Mid);
    }

    if(Mid+1>r || y<l) NewNode->Right=OldNode->Right;
    else
    {
        NewNode->Right= new Tree;
        Update(NewNode->Right,OldNode->Right,Mid+1,y);
    }
    NewNode->val=NewNode->Left->val+NewNode->Right->val+NewNode->store*(y-x+1);
}
void FindSum(Tree *Node,int x,int y)
{
    if(x>r || y<l)return;
    if(l<=x && y<=r)
    {
        Ans+=(y-x+1)*Add+Node->val;
        return;
    }
    int Mid=(x+y)/2;

    Add+=Node->store;
    FindSum(Node->Left,x,Mid);
    FindSum(Node->Right,Mid+1,y);
    Add-=Node->store;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long Queries;
    cin>>n;
    while(N<n){N<<=1;Levels++;}
    Roots[1]=new Tree;
    BuildTree(Roots[1],1);
    cin>>Queries;
    for(int i=1;i<=Queries;i++)
    {
        cin>>Type>>State>>l>>r;
        if(Type==1)
        {
            cin>>v; CntRoots++;
            Roots[ CntRoots ]=new Tree;
            Roots[ CntRoots ]->val=0; Roots[ CntRoots ]->store=0;
            Update(Roots[ CntRoots ], Roots[ State ], 1, N);
        }
        else
        {
            Add=0; Ans=0;
            FindSum(Roots[ State ], 1, N);
            cout<<Ans<<"\n";
        }
    }
    return 0;
}
