#include<bits/stdc++.h>
using namespace std;
struct el
{
    int st,mn;
};

int n,a[20],mx,pnts;
stack<el> k2;
void go(int pos)
{
    //cerr<<pos<<endl;
    if(pos==n+1&&k2.empty())
    {
        mx=max(mx,pnts);
        return;
    }
    el nw;
    if(pos<=n)
    {
        nw.st=a[pos];
        if(!k2.empty())nw.mn=min(nw.st,k2.top().mn);
        else nw.mn=nw.st;
        k2.push(nw);
        pnts+=k2.top().mn;
        go(pos+1);
        pnts-=k2.top().mn;
        k2.pop();
    }
    if(!k2.empty())
    {
        el lel=k2.top();
        k2.pop();
        if(!k2.empty())pnts+=k2.top().mn;
        go(pos);
        if(!k2.empty())pnts-=k2.top().mn;
        k2.push(lel);
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    go(1);
    cout<<mx<<endl;
}
