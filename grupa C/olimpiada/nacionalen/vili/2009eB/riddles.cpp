#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t;
int n,k,a[100004];
bool check(int mid)
{
    int v[100004];
    for(int i=1;i<=mid;i++)v[i]=a[i];
    sort(v+1,v+mid+1);
    //cout<<"v->";
    //for(int i=1;i<=mid;i++)cout<<" "<<v[i];
    //cout<<endl;
    long long s=0;
    for(int i=1;i<=mid;i++)
    {
        if(v[i]>s+1)return false;
        //cout<<"v["<<i<<"]="<<v[i]<<" "<<"s="<<s<<endl;
        s+=v[i];if(s>=k)return true;
    }
    return false;
}
void solve()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int left=1,right=n,mid,ans=n+1;
    while(left<=right)
    {
        mid=(left+right)/2;
        //cout<<"mid="<<mid<<endl;
        if(check(mid)){ans=min(ans,mid);right=mid-1;}
        else left=mid+1;
    }
    if(ans==n+1)printf("-1\n");
    else printf("%d\n",ans);
}
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)solve();
    return 0;
}