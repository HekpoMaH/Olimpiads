#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<cmath>
using namespace std;
struct book
{
    int t,w;
};
book a[101];
int n;
bool cmp(book x,book y)
{
    if(x.w>y.w)return true;
    if(x.w<y.w)return false;
    if(x.t>y.t)return true;
    return false;
}
int tw,tt;
int dp[10009];
int main()
{
    cin>>n;
    for(int i=1;i<=10009;i++)dp[i]=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].t>>a[i].w;tw+=a[i].w;
        for(int j=10009;j>=0;j--)
        {
            if(dp[j]!=-1&&j+a[i].t<10009)dp[j+a[i].t]=max(dp[j+a[i].t],dp[j]+a[i].w);
        }
    }
    for(int i=1;i<=10009;i++)
    {
        if(dp[i]!=-1)
        {
            if(tw-dp[i]<=i){cout<<i<<endl;break;}
        }
    }
    /*sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        tt+=a[i].t;tw-=a[i].w;
        //cout<<a[i].t<<" "<<a[i].w<<endl;
        if(tt>=tw){cout<<tt<<endl;return 0;}
    }*/
}

