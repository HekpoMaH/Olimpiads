#include<bits/stdc++.h>
using namespace std;
int n,c[109],ps[109],x,y;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>c[i],ps[i]=ps[i-1]+c[i];
    cin>>x>>y;
    for(int i=1;i<=n;i++)
    {
        //cout<<ps[i]<<" "<<ps[n]-ps[i]<<endl;
        if(ps[i]>=x&&ps[i]<=y&&ps[n]-ps[i]>=x&&ps[n]-ps[i]<=y){cout<<i+1<<endl;return 0;}
    }cout<<0<<endl;
}
