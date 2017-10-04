#include<bits/stdc++.h>
using namespace std;
int t;
int n,k,a[100010];
bool chek(int x)
{
    int v[100009];
    for(int i=1;i<=x;i++)v[i]=a[i];
    sort(v+1,v+x+1);
    long long s=0;
    for(int i=1;i<=x;i++)
    {
        if(v[i]>s+1)return false;
        s+=v[i];
        if(s>=k)return true;
    }
    return false;
}
void solve()
{
    //ios::sync_with_stdio(false);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int l=0,r=n,ans=n+1,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(chek(mid)==true){ans=mid;r=mid-1;}
        else l=mid+1;
    }
    if(ans==n+1)printf("-1\n");
    else printf("%d\n",ans);
}
int main()
{
    cin>>t;
    while(t--)solve();
}
