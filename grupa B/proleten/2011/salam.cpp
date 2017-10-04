#include<bits/stdc++.h>
using namespace std;
const int nmax=1000009;
int p1[nmax],p2[nmax];
int a[nmax],n,mx,mxi,mx2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],p1[i]=p1[i-1]+a[i];
    for(int i=n;i>=1;i--)
    {
        p2[i]=max(p2[i+1],p1[n]-p1[i-1]);
    }
    for(int i=0;i<=n+1;i++)
    {
        if(p1[i]+p2[i+1]>=mx)
        {
            mx=p1[i]+p2[i+1];
            mxi=i;
        }
        //cout<<i<<" "<<p1[i]<<" "<<p2[i+1]<<"\n";
    }
    cout<<mx<<"\n";
    cout<<mxi<<" ";
    for(int i=n+1;i>=1;i--)
    {
        if(p2[mxi+1]==p2[i])
        {
            mx2=i;
            break;
        }
    }
    cout<<mx2<<"\n";
}
