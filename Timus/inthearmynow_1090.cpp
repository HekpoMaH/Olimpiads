#include<iostream>
#include<cstring>
using namespace std;
int k,n,s[10005],sum,mn,ans=1;
int bit[10005];
int ss(int x)
{
    int res=0;
    while(x>0)
    {
        res+=bit[x];
        x-=x&-x;
    }
    return res;
}
void pus(int x)
{
    while(x<=n)
    {
        ++bit[x];
        x+=x&-x;
    }
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        memset(bit,0,sizeof(bit));
        sum=0;
        for(int j=1;j<=n;j++)cin>>s[j];
        for(int j=1;j<=n;j++)
        {
            sum+=j-ss(s[j]);
            //cout<<sum<<endl;
            pus(s[j]);
        }
        if(sum>mn)mn=sum, ans=i;
    }
    cout<<ans<<endl;
    return 0;
}