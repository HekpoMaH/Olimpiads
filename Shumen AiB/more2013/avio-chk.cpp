#include<bits/stdc++.h>
#include<queue>
using namespace std;
int a[100009];
int it[700009],listo[100009],fp,ans[100009];
int n,m,k;
int dasprali;

struct cho
{
    int a,b,st,in,in2;
    bool operator<(const cho &x)const
    {
        if(b>x.b)return false;
        if(b<x.b)return true;
        if(a>x.a)return false;
        if(a<x.a)return true;
        if(st>x.st)return false;
        return true;
    }
};
struct cho2
{
    int a,b,st,in,in2;
    bool operator<(const cho2 &x)const
    {
        if(b>x.b)return true;
        if(b<x.b)return false;
        if(a>x.a)return true;
        if(a<x.a)return false;
        if(st>x.st)return false;
        return true;
    }
};
cho p[100009];
cho2 p2[100009];
void rec(int l,int r,int idx)
{
    if(l==r)
    {
        listo[l]=idx;//el[idx]=l;
        it[idx]=a[l];
        return;
    }
    rec(l,(l+r)/2,idx*2);
    rec((l+r)/2+1,r,idx*2+1);
    it[idx]=it[idx*2]+it[idx*2+1];
}
int find(int l,int r,int ql,int qr,int idx)
{
    if(l==r)return l;
    int nl=l,nr,hui=1000000000;
    if(it[idx]==0)return 1000000000;
    if(it[idx*2]>0)
    {
        nl=l;nr=(l+r)/2;

        if(!(qr<nl||ql>nr))hui=min(hui,find(nl,nr,ql,qr,idx*2));
    }
    if(it[idx*2+1]>0)
    {
        nl=(l+r)/2+1;nr=r;
        if(!(qr<nl||ql>nr))hui=min(hui,find(nl,nr,ql,qr,idx*2+1));
    }
    return hui;
}
bool cmp(cho fi,cho se)
{
    if(fi.st>se.st)return true;
    if(fi.st<se.st)return false;
    if(fi.b>se.b)return true;
    if(fi.b<se.b)return false;
    if(fi.a>se.a)return true;
    return false;
}
void decin()
{
    priority_queue<cho> pq;
    int la=1,deseninterval=m;
    //
    for(int i=1;i<=n;i++)
    {
        if(p[i].st==1)pq.push(p[i]);
    }
    //cout<<"F"<<endl;
    //cout<<p[1].st<<" "<<endl;
    //cout<<pq.empty()<<endl;
    //vector<cho> mfa;
    cho gat;
    while(!pq.empty()&&deseninterval>0)
    {
        for(int i=1;i<=k;i++)
        {
            if(!pq.empty())
            {
                gat=pq.top();
                if(gat.b!=deseninterval)break;
                p[gat.in2]=gat;
                pq.pop();
                //cout<<gat.in<<" "<<gat.a<<" "<<gat.b<<endl;
            }
        }
        if(!pq.empty())gat=pq.top();
        //for(int i=0;i<mfa.size();i++)p[mfa[i].in]=mfa[i],cout<<"R"<<mfa[i].in<<" "<<mfa[i].a<<" "<<mfa[i].b<<endl;
        //cout<<"COMPLETED"<<endl;
        //mfa.clear();
        while(!pq.empty())
        {
            if(pq.top().b!=deseninterval)break;
            gat=pq.top();
            gat.b--;
            pq.pop();
            if(gat.a>gat.b){dasprali=1;return;}
            pq.push(gat);//cout<<"mamka ti mrasna "<<gat.a<<" "<<gat.b<<" "<<deseninterval<<endl;
        }
        deseninterval--;
        //cout<<"THIS MOMENT"<<pq.top().a<<" "<<pq.top().b<<" "<<deseninterval<<endl;
    }
}priority_queue<cho2> pq2;
void solveitmotherfucker()
{
    vector<cho2> paklibe;
    int sqpalnim=1;
    for(int i=1;i<=n;i++)
    {
        pq2.push(p2[i]);
        cout<<p2[i].a<<" "<<p2[i].b<<" "<<p2[i].in<<endl;
    }
    //cout<<endl;
    for(int i=1;i<=m;i++)
    {
        paklibe.clear();
        while(!pq2.empty())
        {
            //cout<<pq2.top().a<<" "<<pq2.top().b<<" "<<pq2.top().in<<endl;
            if(pq2.top().a<=i&&pq2.top().b>=i)ans[pq2.top().in]=i,a[i]--,cout<<"vkarvam "<<pq2.top().in<<" vav"<<i<<" za6toto "<<pq2.top().a<<" "<<pq2.top().b<<endl,pq2.pop();
            else paklibe.push_back(pq2.top()),pq2.pop();
            if(a[i]==0)break;
        }
        for(int j=0;j<paklibe.size();j++)pq2.push(paklibe[j]);
        //cout<<"OVER"<<endl;
    }
    int broq4=0;
    for(int i=1;i<=n;i++)if(ans[i]!=0)broq4++;
    cout<<broq4<<"\n";
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<"\n";
}
//int used[100009];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)a[i]=k;
    //rec(1,n,1);
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].a>>p[i].b>>p[i].st;
        p[i].in=i;

    }
    int ans;
    cin>>ans;
    for(int i=1;i<=ans;i++)
    {
        int x;
        cin>>x;
        if(p[i].st==1&&x==0)cout<<i<<" "<<"just fucked up"<<endl;
        if(x==0)continue;
        if(!(p[i].a<=x&&x<=p[i].b))cout<<"intervals overfucked"<<" "<<i<<endl;
        if(a[x]==0)cout<<"plane overrun"<<" "<<x<<endl;
        //used[i]=1;
        a[x]--;
    }
}

