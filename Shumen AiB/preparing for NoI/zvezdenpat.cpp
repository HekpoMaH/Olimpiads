#include<iostream>
#include<stack>
#include<cstring>
#include<vector>
using namespace std;
int a[300009];
int n;
struct itra
{
    int val,pos;
};


const int maxn=300009,maxval=9000000;
vector<int> o;
itra it[6*maxn];
long long kind[maxn],l,r,last[maxn],pos[maxn],t[maxn],start[maxn];
void rec(int pos,int l,int r)
{
    if(l==r)
    {
        start[l]=pos;
        return;
    }
    rec(pos*2,l,(l+r)/2);
    rec(pos*2+1,(l+r)/2+1,r);
}
itra build(int pos,int l,int r)
{
    if(l==r)
    {
        it[pos].val=kind[l];
        it[pos].pos=l;
        return it[pos];
    }
    int mid=(l+r)/2;
    itra tmp1,tmp2;
    tmp1=build(pos*2,l,mid);
    tmp2=build(pos*2+1,mid+1,r);
    if(tmp1.val<tmp2.val)it[pos]=tmp1;
    else it[pos]=tmp2;
    return it[pos];
}
void init()
{
    rec(1,1,maxn);
    for(int i=2;i<=n;i++)
    {
        kind[a[i]]=maxval;
    }
    kind[a[1]]=1;
    for(int i=1;i<=maxn;i++)if(a[1]!=i)kind[i]=maxval;
    build(1,1,maxn);
}
void update(int k)
{
    int idx=start[k] ;
    it[idx].val=kind[k];
    itra tmp1,tmp2;
    do
    {
        idx/=2;
        tmp1=it[idx*2];
        tmp2=it[idx*2+1];
        if(tmp1.val<tmp2.val)it[idx]=tmp1;
        else it[idx]=tmp2;
    }
    while(idx!=1);
}
void solve()
{int ans,cur;
    for(int i=1;i<=maxn;i++)last[a[i]]=i;
    init();
    itra tmp;

    pos[a[1]]=0;
    t[a[1]]=1;
    for(int i=2;i<=n;i++)
    {
        tmp=it[1];
        ans=tmp.val+1;
        cur=tmp.pos;
        pos[i]=t[cur];
        t[a[i]]=i;
        if(last[a[i]]==i)kind[a[i]]=maxval;
        else kind[a[i]]=ans;
        update(a[i]);
        //cout<<i<<" "<<ans<<endl;
    }
    //for(int i=1;i<=n;i++)cout<<last[i]<<" ";
    //cout<<endl;
    //cout<<ans<<endl;
    cur=pos[n];
    if(last[a[1]]==1||ans==maxval+1)
    {
        cout<<0<<endl;return ;
    }
    //cout<<ans-1<<" "<<"wTF"<<endl;
    while(cur>1)
    {
        //cout<<cur<<" "<<pos[cur]<<endl;
        o.push_back(cur);//cout<<cur<<" "<<pos[cur]<<endl;
        cur=pos[cur];
    }//cout<<ans-1<<" "<<"wTF"<<endl;
    o.push_back(1);
    cout<<ans-1<<endl;
    cout<<o[o.size()-1];
    for(int i=o.size()-2;i>-1;i--)
    {
        cout<<" "<<o[i];
    }
    cout<<endl;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    solve();
}
