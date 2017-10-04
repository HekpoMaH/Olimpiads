#include<bits/stdc++.h>
using namespace std;
int p[1009];
int n,m,q;
int find(int node)
{
    while(node!=p[node])node=p[node];
    return node;
}
void uni(int n1,int n2)
{
    while(n2!=p[n2])n2=p[n2];
    int k;
    while(n1!=p[n1])
    {
        k=p[n1];
        p[n1]=n2;
        n1=k;
    }
    p[n1]=n2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
    }
    int x,y,t;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        if(find(x)!=find(y))uni(x,y);
    }
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>t>>x>>y;
        if(t==1)
        {
            if(find(x)==find(y))cout<<1;
            else cout<<0;
        }
        else uni(x,y);
    }
    cout<<endl;
}
