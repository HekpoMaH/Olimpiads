#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<string>
#include<climits>
#include<fstream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#define lli long long
using namespace std;
struct Tree
{
    lli val,store;
    Tree Left, Right;
};
lli N=1,Leaves[200000],CntRoots=1,Levels=1,n,p=1,l,r,v,l1,r1,s=0;
Tree *Roots[200005];
void BuildTree(Tree *K,lli lvl)
{
    K->store=0;
    if(lvl==Levels)
    {
        if(p<=n)cin>>K->val;
        else K->val=0;
        p++;
        return;
    }
    K->Left=new Tree;
    K->Right=new Tree;
    BuildTree(K->Left,lvl+1);
    BuildTree(K->Right,lvl+1);
    K->val=K->Left->val+K->Right->val;
}
lli Add=0;
void Update(Tree K,Tree K1,lli x,lli y)
{
    if(x>=l && y<=r)
    {
        K->val=K1->val+v*(y-x+1);
        K->store=v+K1->store;
        K->Left=K1->Left;
        K->Right=K1->Right;
        return;
    }
    lli Mid=(x+y)/2;
    if(x>r || Mid<l) K->Left=K1->Left;
    else
    {
        K->Left=new Tree; K->Left->val=K1->Left->val;
        K->Left->store=K1->Left->store;
        Update(K->Left,K1->Left,x,Mid);
    }

    if(Mid+1>r || y<l) K->Right=K1->Right;
    else
    {
        K->Right= new Tree; K->Right->val=K1->Right->val;
        K->Right->store=K1->Right->store;
        Update(K->Right,K1->Right,Mid+1,y);
    }
    K->val=K->Left->val+K->Right->val+K->store*(y-x+1);
}
void Solve(Tree *K,lli x,lli y)
{
    if(x>r1 || y<l1)return;
    if(l1<=x && y<=r1)
    {
        s+=(y-x+1)*Add+K->val;
        return;
    }
    lli Mid=(x+y)/2;

    Add+=K->store;
    Solve(K->Left,x,Mid);
    Solve(K->Right,Mid+1,y);
    Add-=K->store;
    //K->val=K->Left->val+K->Right->val+K->store*(y-x+1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    lli Q;
    cin>>Q>>n;
    while(N<n){N<<=1;Levels++;}
    Roots[1]=new Tree;
    BuildTree(Roots[1],1);
    for(lli i=2;i<=Q;i++)
    {
        cin>>p>>l>>r>>v>>l1>>r1;
        l=((l+s)%n)+1;  r=((r+s)%n)+1;
        l1=((l1+s)%n)+1;  r1=((r1+s)%n)+1;
        Roots[i]=new Tree; s=0; Add=0;
        Roots[i]->store=0; Roots[i]->val=0;
        Update(Roots[i],Roots[p],1,N);
        Solve(Roots[i],1,N);
        cout<<s<<"\n";
    }
    return 0;
}
