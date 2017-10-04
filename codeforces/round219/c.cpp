#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
int n;
int ans;
int s[500009],used[500009];
bool chk(int x)
{
    for(int i=1;i<=x;i++)
    {
        cout<<i<<" "<<n+i-x<<" "<<s[i]<<" "<<s[n+i-x]<<endl;
        if(s[i]*2>s[n+i-x])return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++)cin>>s[i];
    //int uk1=1,uk2=2;
    sort(s+1,s+n+1);
    int l=0,r=n/2;
    int mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        cout<<"cheking for "<<mid<<endl;
        if(chk(mid)==true)ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<n-ans<<endl;
}
