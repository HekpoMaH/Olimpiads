#include<bits/stdc++.h>
using namespace std;
int n,k;
int f[309][309],ps[309],a[309];
int sumdv(int x)
{
    int res=0;
    while(x!=0)
    {
        res+=x&1;
        x>>=1;
    }
    return res;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i],ps[i]=ps[i-1]+sumdv(a[i]);
    memset(f,31,sizeof(f));
    for(int i=1;i<=k;i++)
    {
        f[1][i]=a[1];
    }
    for(int i=1;i<=n;i++)
    {
        f[i][1]=ps[i];
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=k;j++)
        {
            for(int p=1;p<i;p++)
            {
                f[i][j]=min(f[i][j],max(f[p][j-1],ps[i]-ps[p]));
            }
        }
    }
    cout<<f[n][k]<<endl;
    int minimalnovr=f[n][k],sum=0,br=0;
    for(int i=1;i<=n;i++)
    {
        br++;
        sum+=sumdv(a[i]);
        cout<<"sum="<<sum<<" "<<i<<endl;
        if(sum>minimalnovr)cout<<br-1<<" ",br=1,sum=sumdv(a[i]);
        //cout<<a[i]<<" ";
    }
    cout<<br;
    cout<<endl;
}
