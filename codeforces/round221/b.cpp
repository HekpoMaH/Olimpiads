#include<bits/stdc++.h>
using namespace std;
int st[109];
int a[109][109];
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        st[x]-=z;
        st[y]+=z;
        a[x][y]=z;
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans+=max(0,st[i]);
    cout<<ans<<endl;
}
