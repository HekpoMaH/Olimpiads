#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,d[200009],br;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        d[x]++;d[y]++;
    }
    for(int i=1;i<=n;i++)br+=d[i]/2-1;
    cout<<br+1<<"\n";
}
