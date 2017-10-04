#include<bits/stdc++.h>
using namespace std;
int n,k,a[500009];
int ps[500009],mn=500000*101,mni;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i],ps[i]=ps[i-1]+a[i];
    for(int i=1;i<=n-k+1;i++)
    {
        if(ps[i+k-1]-ps[i-1]<mn)
        {
            mn=ps[i+k-1]-ps[i-1];
            mni=i;
        }
    }
    cout<<mni<<"\n";
}
