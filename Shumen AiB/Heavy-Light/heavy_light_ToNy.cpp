#include<bits/stdc++.h>
using namespace std;
const int MAXN=100100;
struct interval
{
    int val;
    int l,r;
    interval *left,*right;
};
struct node
{
    int below;
    vector<int> v;
    interval *root;
    int pos;
    int parent;
    int level,pathlvl;
};
int n;
node d[MAXN];
void read()
{
    int i;
    int x,y;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        d[x].v.push_back(y);
        d[y].v.push_back(x);
    }
}
int initBelow(int x,int parent)
{
    int i,sz;
    d[x].below=0;
    sz=d[x].v.size();
    for(i=0;i<sz;i++)
        if(d[x].v[i]!=parent)d[x].below+=initBelow(d[x].v[i],x);
    d[x].below++;
    return d[x].below;
}
void buildIT(int l,int r,interval *root)
{
    root->l=l;
    root->r=r;
    if(l==r)
    {
        root->val=0;
        return;
    }
    root->left=new interval;
    buildIT(l,(l+r)/2,root->left);
    root->right=new interval;
    buildIT((l+r)/2+1,r,root->right);
    root->val=max(root->left->val,root->right->val);
}
void initPaths(int x,int parent,int pos,int pathparent)
{
    bool f=false;
    int i,sz;
    sz=d[x].v.size();
    if(parent==-1)d[x].level=1;
    else d[x].level=d[parent].level+1;
    d[x].pos=pos;
    d[x].parent=pathparent;
    for(i=0;i<sz;i++)
        if(d[x].v[i]!=parent)
        {
            if(d[d[x].v[i]].below>=(d[x].below+1)/2)
            {
                f=true;
                d[d[x].v[i]].root=d[x].root;
                d[d[x].v[i]].pathlvl=d[x].pathlvl;
                initPaths(d[x].v[i],x,pos+1,pathparent);
            }
            else
            {
                d[d[x].v[i]].root=new interval;
                d[d[x].v[i]].pathlvl=d[x].level+1;
                initPaths(d[x].v[i],x,0,x);
            }
        }
    if(!f)buildIT(0,d[x].pos,d[x].root);
}
void update(interval *root,int y,int z)
{
    if(root->l==root->r)
    {
        root->val+=z;
        return;
    }
    if(y<=(root->l+root->r)/2)update(root->left,y,z);
    else update(root->right,y,z);
    root->val=max(root->left->val,root->right->val);
}
int findLCA(int x,int y)
{
    while(d[x].root!=d[y].root)
    {
        if(d[x].pathlvl>d[y].pathlvl)x=d[x].parent;
        else y=d[y].parent;
    }
    if(d[x].level<d[y].level)return x;
    else return y;
}
int findInterval(interval *root,int l,int r)
{
    if(l<=root->l&&root->r<=r)return root->val;
    if(l>root->r||root->l>r)return 0;
    return max(findInterval(root->left,l,r),findInterval(root->right,l,r));
}
int compute(int x,int y)
{
    int current=0;
    bool first=true;
    if(d[x].root!=d[y].root)current=max(current,findInterval(d[x].root,0,d[x].pos));
    while(d[x].root!=d[y].root)
    {
        if(!first)current=max(current,findInterval(d[x].root,0,d[x].pos));
        x=d[x].parent;
        first=false;
    }
    current=max(current,findInterval(d[x].root,d[y].pos,d[x].pos));
    return current;
}
void queries()
{
    int i,q,lca,answer;
    char x;
    int y,z;
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
        scanf("%c",&x); // for \n
        scanf("%c",&x);
        scanf("%d%d",&y,&z);
        if(x=='I')update(d[y].root,d[y].pos,z);
        else
        {
            lca=findLCA(y,z);
            if(lca)
            answer=max(compute(y,lca),compute(z,lca));
            printf("%d\n",answer);
        }
    }
}
int main()
{
    read();
    int trash=initBelow(1,-1);
    d[1].root=new interval;
    d[1].pathlvl=1;
    initPaths(1,-1,0,-1);
    queries();
    return 0;
}
