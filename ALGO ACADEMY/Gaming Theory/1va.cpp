#include<bits/stdc++.h>
using namespace std;
int a[109],n,brs,brr,ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=100;j++)
        {
            brs=brr=0;
            if(i>=j)for(int k=1;k<=n;k++)
            {
                if(a[k]==i+j)brs++;
                if(a[k]==i-j)brr++;
            }
            if(brs!=0&&brr!=0)ans=max(ans,i*j);
        }
    }
    cout<<ans<<endl;
}
