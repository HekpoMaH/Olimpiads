#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1000000007;
const int maxn=1000004;
int n,d[maxn],a[maxn];
int k,l;
int main()
{
    scanf("%d%d%d",&n,&k,&l);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    a[0]=0;a[n+1]=k;
    int right=n+1;
    d[right]=1;
    int sum=1;
    for(int left=n;left>=0;left--)
    {
        while(a[right]-a[left]>l)
        {
            sum=(sum-d[right]+mod)%mod;
            right--;
        }
        d[left]=sum;
        sum=(sum+d[left])%mod;
    }
    cout<<d[0]<<endl;
    return 0;
}
