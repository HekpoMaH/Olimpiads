#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
struct qu
{
    int l;int r;
    int idx;
};
qu dq;
vector<qu> qrs;
int a[300004],n,m;
int last[1000009];
int ans[200009],t[30001];
bool cmp(qu fi,qu se)
{
    if(fi.r<se.r)return true;
    if(fi.r>se.r)return false;
    if(fi.l<se.l)return true;
    return false;
}
void update(int idx,int val)
{
    if(idx==0)return;
    while(idx<=n)
    {//cout<<idx<<endl;
        t[idx]+=val;
        idx+=(idx&-idx);
    }
}
int get(int idx)
{
    if(idx==0)return 0;
    int ss=0;
    while(idx!=0)ss+=t[idx],idx-=(idx&-idx);
    return ss;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&dq.l,&dq.r);
        dq.idx=i;
        qrs.push_back(dq);
    }
    dq.l=-1,dq.r=0;
    dq.idx=-1;
    qrs.push_back(dq);
    int sum;
    sort(qrs.begin(),qrs.end(),cmp);
    //for(int i=0;i<qrs.size();i++)cout<<qrs[i].l<<" "<<qrs[i].r<<endl;
    for(int i=1;i<qrs.size();i++)
    {
        for(int j=qrs[i-1].r+1;j<=qrs[i].r;j++)
        {
            update(last[a[j]],-1);
            last[a[j]]=j;
            update(last[a[j]],1);
        }
        if(qrs[i].r!=qrs[i-1].r)sum=get(qrs[i].r);
        ans[qrs[i].idx]=sum-get(qrs[i].l-1);

    }
    for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
}
