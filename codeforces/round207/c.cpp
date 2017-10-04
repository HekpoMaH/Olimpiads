#include<bits/stdc++.h>
using namespace std;
int r[300009],ans[300009];
int find(int xx)
{
    //cout<<x<<" "<<r[x]<<endl;
    if(xx!=r[xx])r[xx]=find(r[xx]);//,cout<<"r="<<r[xx]<<endl;
    return r[xx];
}
int n,m,le,ri,x,u;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;for(int i=1;i<=n+1;i++)r[i]=i;
    for(int i=1;i<=m;i++)
    {
        cin>>le>>ri>>x;
        //cout<<u<<endl;
        u=find(le);
        while(1)
        {
            if(u>=x)break;
            //cout<<u<<endl;
            ans[u]=x;
            r[u]=u+1;
            u=find(u);
        }
        u=find(x+1);
        //cout<<u<<endl;
        while(1)
        {
            if(u>ri)break;
            //cout<<u<<endl;
            ans[u]=x;
            r[u]=u+1;
            u=find(u);
        }
    }
    for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";cout<<endl;
}
