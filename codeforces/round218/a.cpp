#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[109],b[109],ans=101;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i],a[i]--;
    for(int i=0;i<(1<<k);i++)
    {
        memset(b,0,sizeof(b));
        for(int j=1;j<=k;j++)
        {
            if(i&(1<<(j-1)))b[j]=1;
        }
        for(int j=k+1;j<=n;j++)
        {
            if(j%k!=0)b[j]=b[j%k];
            else b[j]=b[k];
        }
        int br=0;
        for(int j=1;j<=n;j++)if(b[j]!=a[j])br++;
        ans=min(br,ans);
    }
    cout<<ans<<endl;
}
