//sweep line ftw
#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
struct line
{
    int xb,yb,xe,ye;
    int hor;int idx;
    bool operator < (const line &x)const
    {
        if(idx<x.idx)return true;
        return false;
    }
};
line a[100009];
set<line> s;
set<int> vkarani;
map<int,vector<pair<int,int> > > tip;
vector<int> xove;
//1 na4alo 2 krai 3 proverka;
void cal(int f,int s)
{
    if(a[f].yb>a[s].ye)return;
    if(a[f].ye<a[s].yb)return;
    if(a[s].xb>a[f].xe)return;
    if(a[s].xe<a[f].xb)return;
    ans=max(min(min( abs(a[s].xb-a[f].xb),abs(a[s].xe-a[f].xb) ), min(abs(a[f].ye-a[s].yb),abs(a[f].yb-a[s].yb)) ),ans);
}
void proverka(int daidx)
{
    set<line>::iterator it;
    for(it=s.begin();it!=s.end();it++)
    {
        //cout<<it->xb<<" "<<it->yb<<" - "<<it-> xe<<" "<<it-> ye<<" ans=";
        cal(daidx,it->idx);
        //cout<<ans<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int x,y,l;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>l;
        a[i].xb=x;a[i].yb=y;
        a[i].xe=x;a[i].ye=y+l;a[i].idx=i;
        if(vkarani.find(x)==vkarani.end())xove.push_back(x);
        vkarani.insert(x);
        tip[x].push_back(make_pair(3,i));
    }
    for(int i=n+1;i<=m+n;i++)
    {
        cin>>x>>y>>l;
        a[i].xb=x;a[i].yb=y;
        a[i].xe=x+l;a[i].ye=y;a[i].idx=i;
        //eds.insert(x+l);
        a[i].hor=1;
        //cout<<x<<" a "<<x+l<<" "<<(vkarani.find(x)!=vkarani.end())<<" "<<(vkarani.find(x+l)!=vkarani.end())<<endl;
        if(vkarani.find(x)==vkarani.end())xove.push_back(x);
        vkarani.insert(x);
        if(vkarani.find(x+l)==vkarani.end())xove.push_back(x+l);
        vkarani.insert(x+l);
        tip[x].push_back(make_pair(1,i));
        tip[x+l].push_back(make_pair(2,i));
    }
    sort(xove.begin(),xove.end());
    //unique(xove.begin(),xove.end());
    //cout<<"xove"<<" "<<xove.size()<<endl;
    for(int i=0;i<xove.size();i++)
    {
        for(int j=0;j<tip[xove[i]].size();j++)
        {
            if(tip[xove[i]][j].first==1)s.insert(a[tip[xove[i]][j].second]);
            if(tip[xove[i]][j].first==2)s.erase(a[tip[xove[i]][j].second]);
            if(tip[xove[i]][j].first==3)proverka(a[tip[xove[i]][j].second].idx);
        }

    }
    cout<<ans<<endl;
}
