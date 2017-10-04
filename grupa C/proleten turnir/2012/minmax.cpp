#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;
int n,c;
int a[17],b[17];
long long res(long long num)
{
    for(int i=1;i<=n;i++)
    {
        num/=a[i];num+=b[i];
    }
    return num;
}
void bsformin(long long x)
{
    long long lef=1,righ=x,ans,mid;
    while(lef<=righ)
    {
        mid=lef+righ;mid/=2;
        if(res(mid)==c)
        {
            ans=min(ans,mid);
            righ=mid-1;
        }
        else lef=mid+1;
    }
    cout<<ans<<" ";
}
void bsformax(long long x)
{
    long long lef=x,righ=100000000000000000LL,ans,mid;
    while(lef<=righ)
    {
        mid=(lef+righ)/2;
        if(res(mid)==c)
        {
            ans=max(ans,mid);
            lef=mid+1;
        }
        else righ=mid-1;
    }
    cout<<ans<<endl;
}
int main()
{
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
    }
    long long x=c;
    for(int i=n;i>=1;i--)
    {
        x-=b[i];x*=a[i];
    }
    bsformin(x);
    bsformax(x);
    return 0;
}