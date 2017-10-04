#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long sl[200009],sr[200009],a1[200009],a2[200009],dp1[200009],dp2[200009],d[200009];
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i];
        sl[i]+=sl[i-1]+d[i];
    }
    for(int i=k;i<=n;i++)
    {
        if(dp1[i-1]>=sl[i]-sl[i-k])
        {
            a1[i]=d[i-1];
            dp1[i]=dp1[i-1];
        }
        else
        {
            a1[i]=i-k+1;
            dp1[i]=sl[i]-sl[i-k];
        }
    }
    for(int i=n;i>=1;i--)
    {
        sr[i]=sr[i+1]+d[i];
    }
    for(int i=n-k+1;i>=1;i--)
    {
        if(dp2[i+1]>sr[i]-sr[i+k])
        {
            a2[i]=a2[i+1];
            dp2[i]=dp2[i+1];
        }
        else
        {
            a2[i]=i;
            dp2[i]=sr[i]-sr[i+k];
        }
    }
    long long ans=0,x,y;
    for(int i=k;i+1<=n-k+1;i++)
    {
        if(dp1[i]+dp2[i+1]>ans)
        {
            ans=dp1[i]+dp2[i+1];
            x=a1[i];y=a2[i+1];
        }
    }
    cout<<x<<" "<<y<<endl;
}

