#include<iostream>
using namespace std;
long long n,t,l=1,r=1;
long long a[100009];
long long sum[100009],ans;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>t;
    for(int i=1;i<=n;i++)cin>>a[i],sum[i]=sum[i-1]+a[i];
    while(r<=n&&l<=n)
    {
        if(sum[r]-sum[l-1]<=t)
        {
            ans=max(ans,r-l+1);
            if(r!=n)r++;
            else if(l!=n+1)l++;
        }
        else{if(l<r)l++;else r++;}
    }
    cout<<ans<<endl;
}
