#include<bits/stdc++.h>
using namespace std;
const int nmax=1000009;
struct node
{
    int x,y;
};
struct it
{
    int x,lvl;
};
vector<node>v[nmax];
int n,pos,used[nmax];
int obh[10*nmax],lvl[10*nmax],first[nmax];
it intervalno[10*nmax];
long long pat[nmax];
void read()
{
    int x,y;
    node tad;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        cin>>x>>y;
        tad.x=x;
        tad.y=y;
        v[i].push_back(tad);
        tad.x=i;
        v[x].push_back(tad);
    }
}
void dfs(int x,int y,int lev)
{
    pat[x]=y;
    used[x]=1;
    for(int i=0;i<v[x].size();i++)
    {
        if(used[v[x][i].x]==0)
        {
            dfs(v[x][i].x,y+v[x][i].y,lev+1);
            obh[++pos]=x;
            lvl[pos]=lev;
            if(!first[x])first[x]=pos;
        }
    }
    if(v[x].size()==1)
    {
        obh[++pos]=x;
        lvl[pos]=lev;
        if(!first[x])first[x]=pos;
    }
}
void makeit(int idx,int l,int r)
{
    it el1,el2;
    if(l==r)
    {
        intervalno[idx].x=obh[l];
        intervalno[idx].lvl=lvl[l];
        return;
    }
    makeit(idx*2,l,(l+r)/2);
    makeit(idx*2+1,(l+r)/2+1,r);
    if(intervalno[idx*2].lvl<intervalno[idx*2+1].lvl)intervalno[idx]=intervalno[idx*2];
    //cout<<"the mim"
    else intervalno[idx]=intervalno[idx*2+1];
}
it find(int idx,int l,int r,int l1,int r1)
{
    it el1,el2;
    int gr1,gr2,gr3,gr4;
    if(l1<=l&&r<=r1)return intervalno[idx];
    gr1=l;gr2=(l+r)/2;
    gr3=(l+r)/2+1;gr4=r;
    if(!(gr2<l1||r1<gr1))el1=find(idx*2,gr1,gr2,l1,r1);
    else el1.lvl=-1;
    if(!(gr4<l1||r1<gr3))el2=find(idx*2+1,gr3,gr4,l1,r1);
    else el2.lvl=-1;
    if((el1.lvl!=-1&&el1.lvl<el2.lvl) || el2.lvl==-1)return el1;
    return el2;
}
long long dist(int x,int y,int lca)
{
    return pat[x]+pat[y]-2*pat[lca];
}
void solve()
{
    int q,a,b;
    it el;
    int lca;
    long long ans,curr,t;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>a>>b>>t;
        el=find(1,1,pos,min(first[a],first[b]),max(first[a],first[b]));
        lca=el.x;
        //cout<<"lca="<<lca<<endl;
        if(lca==1)
        {
            ans=2*min(dist(1,a,1),t)+dist(1,b,1);
            curr=2*dist(1,a,1)+min(dist(1,b,1),t);
            ans=min(ans,curr);
            curr=dist(1,a,1)+t;
            ans=min(ans,curr);
        }
        else if(lca==a)
        {
            ans=min(dist(1,a,1),t)+dist(a,b,lca);
            curr=dist(1,a,1)+min(dist(a,b,lca),t);
            ans=min(ans,curr);
            curr=min(dist(1,b,1),t)+2*dist(a,b,lca);
            ans=min(ans,curr);
            curr=dist(1,b,1)+2*min(dist(a,b,lca),t);
            ans=min(ans,curr);
        }
        else if(lca==b)
        {
            ans=min(dist(1,b,1),t)+2*dist(a,b,lca);
            curr=dist(1,b,1)+2*min(dist(a,b,lca),t);
            ans=min(ans,curr);
            curr=min(dist(1,a,1),t)+dist(a,b,lca);
            ans=min(ans,curr);
            curr=dist(1,a,1)+min(dist(a,b,lca),t);
            ans=min(ans,curr);
        }
        else
        {
            ans=min(dist(1,lca,1),t)+2*dist(lca,a,lca)+dist(b,lca,lca);
            curr=dist(1,lca,1)+2*min(dist(lca,a,lca),t)+dist(b,lca,lca);
            ans=min(curr,ans);
            curr=dist(1,lca,1)+2*dist(lca,a,lca)+min(dist(b,lca,lca),t);
            ans=min(curr,ans);
            curr=t+dist(a,b,lca);
            ans=min(curr,ans);
            curr=dist(1,a,1)+min(dist(a,b,lca),t);
            ans=min(curr,ans);
        }
        cout<<ans<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    read();
    dfs(1,0,1);
    makeit(1,1,pos);

    solve();
}
