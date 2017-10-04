#include<bits/stdc++.h>
using namespace std;
long long a[100009],ans;
long long n;
bool chk(long long md)
{
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>md)return false;
        sum+=md-a[i];
    }
    return sum>=md;
}
int main()
{
    cin>>n;
    long long l,r,mid;
    long long ssum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];ssum+=a[i];
    }
    l=1;r=ssum;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(chk(mid))
        {
            ans=mid;r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans<<endl;
}

